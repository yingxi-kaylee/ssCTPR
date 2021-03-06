#' @title ssCTPR
#' @description Function to obtain beta estimates of an elastic net regression problem given summary statistics
#' from one or more traits and a reference panel
#' 
#' @details A function to find the minimum of \eqn{\beta} in  
#' \deqn{f(\beta)=\beta'R\beta - 2\beta'r + 2\lambda||\beta||_1 + \lambda_{ct}||\beta-s_{t}||^{2}}
#' where 
#' \deqn{R=(1-s)X'X/n + sI}
#' is a shrunken correlation matrix, with \eqn{X} being standardized reference panel.
#' \eqn{s} should take values in (0,1]. \eqn{r} is a vector of correlations. \eqn{s_{t}} is a vector of summary statistics from secondary traits, if any.
#' \code{keep}, \code{remove} could take one of three 
#' formats: (1) A logical vector indicating which individuals to keep/remove, 
#' (2) A \code{data.frame} with two columns giving the FID and IID of the individuals
#' to keep/remove (matching those in the .fam file), or (3) a character scalar giving the text file with the FID/IID. 
#' Likewise \code{extract}, \code{exclude} can also take one of the three formats,
#' except with the role of the FID/IID data.frame replaced with a character vector of 
#' SNP ids (matching those in the .bim file). 
#' 
#' @note Missing genotypes are interpreted as having the homozygous A2 alleles in the 
#' PLINK files (same as the --fill-missing-a2 option in PLINK). 
#' @param cor A matrix of SNP-wise correlation with primary trait, derived from summary statistics, and beta of secondary traits if have any
#' @param adj Adjacency coefficients
#' @param bfile PLINK bfile (as character, without the .bed extension)
#' @param lambda A vector of \eqn{\lambda}s (the tuning parameter)
#' @param shrink The shrinkage parameter \eqn{s} for the correlation matrix \eqn{R} 
#' @param lambda_ct A vector of \eqn{\lambda_{ctp}}s (the tuning parameter)
#' @param thr convergence threshold for \eqn{\beta}
#' @param init Initial values for \eqn{\beta} as a vector of the same length as \code{cor}
#' @param trace An integer controlling the amount of output generated. 
#' @param maxiter Maximum number of iterations
#' @param blocks A vector to split the genome by blocks (coded as c(1,1,..., 2, 2, ..., etc.))
#' @param extract SNPs to extract
#' @param exclude SNPs to exclude
#' @param keep samples to keep
#' @param remove samples to remove
#' @param chr a vector of chromosomes
#' @param mem.limit Memory limit for genotype matrix loaded. Note that other overheads are not included. 
#' @param chunks Splitting the genome into chunks for computation. Either an integer 
#' indicating the number of chunks or a vector (length equal to \code{cor}) giving the exact split. 
#' @param cluster A \code{cluster} object from the \code{parallel} package for parallel computing
#' 
#' @export

ssCTPR <- function(cor, adj, bfile, 
                     lambda=exp(seq(log(0.001), log(0.1), length.out=20)), 
                     shrink=0.9, 
                     lambda_ct=c(0, 0.06109, 0.13920, 0.24257),
                     thr=1e-4, init=NULL, trace=0, maxiter=3000, 
                     blocks=NULL,
                     keep=NULL, remove=NULL, extract=NULL, exclude=NULL, 
                     chr=NULL, 
                     mem.limit=4*10^9, chunks=NULL, cluster=NULL) {
  cor <- as.matrix(cor)
  stopifnot(sum(apply(cor,2,mode)!="numeric")==0)
  stopifnot(!any(is.na(cor)))
  adj <- as.matrix(adj)
  stopifnot(sum(apply(adj,2,mode)!="numeric")==0)
  stopifnot(!any(is.na(adj)))
  cat("maxiter: ", maxiter, "\n")
  if(any(abs(cor[,1]) > 1)) warning("Some abs(cor) > 1")
  if(any(abs(cor[,1]) == 1)) warning("Some abs(cor) == 1")
  if(length(shrink) > 1) stop("Only 1 shrink parameter at a time.")
  
  parsed <- parseselect(bfile, extract=extract, exclude = exclude, 
                        keep=keep, remove=remove, 
                        chr=chr)
  if(is.null(blocks)) {
    Blocks <- list(startvec=0, endvec=parsed$p - 1)
  } else {
    Blocks <- parseblocks(blocks)
    stopifnot(max(Blocks$endvec)==parsed$p - 1)
  }

  if(nrow(cor) != parsed$p) stop("Length of cor does not match number of selected columns in bfile")
  # stopifnot(length(cor) == parsed$p)
  traits <- ncol(cor)
  
  #### Group blocks into chunks ####
  chunks <- group.blocks(Blocks, parsed, mem.limit, chunks, cluster)
  if(trace > 0) {
    if(trace - floor(trace) > 0) {
      cat("Doing ssCTPR on chunk", unique(chunks$chunks), "\n")
    } else {
      cat("Calculations carried out in ", max(chunks$chunks.blocks), " chunks\n")
    }
  }
  if(length(unique(chunks$chunks.blocks)) > 1) {
    if(is.null(cluster)) {
      results.list <- lapply(unique(chunks$chunks.blocks), function(i) {
        ssCTPR(cor=cor[chunks$chunks==i,], adj=adj[chunks$chunks==i,], bfile=bfile, lambda=lambda, shrink=shrink, lambda_ct=lambda_ct,
                 thr=thr, init=init[chunks$chunks==i], trace=trace, maxiter=maxiter, 
                 blocks[chunks$chunks==i], keep=parsed$keep, extract=chunks$extracts[[i]], 
                 mem.limit=mem.limit, chunks=chunks$chunks[chunks$chunks==i])
      })
    } else {
      Cor <- cor; Adj <- adj; Bfile <- bfile; Lambda <- lambda; Shrink=shrink; Thr <- thr; 
      Maxiter=maxiter; Mem.limit <- mem.limit ; Trace <- trace; Init <- init; 
      Blocks <- blocks; Lambda_ct=lambda_ct
      # Make sure these are defined within the function and so copied to 
      # the child processes
      results.list <- parallel::parLapplyLB(cluster, unique(chunks$chunks.blocks), function(i) {
        ssCTPR(cor=Cor[chunks$chunks==i,], adj=Adj[chunks$chunks==i,], bfile=Bfile, lambda=Lambda, lambda_ct=Lambda_ct,
                 shrink=Shrink, thr=Thr, init=Init[chunks$chunks==i], 
                 trace=trace-0.5, maxiter=Maxiter, 
                 blocks=Blocks[chunks$chunks==i], 
                 keep=parsed$keep, extract=chunks$extracts[[i]], 
                 mem.limit=Mem.limit, chunks=chunks$chunks[chunks$chunks==i])
      })
    }
    return(do.call("merge.ssCTPR", results.list))
  }

  #### Group blocks into chunks 
  
  if(is.null(parsed$extract)) {
    extract2 <- list(integer(0), integer(0))
  } else {
	  # print(parsed$extract)
    extract2 <- selectregion(!parsed$extract)
    extract2[[1]] <- extract2[[1]] - 1
  }
  
  if(is.null(parsed$keep)) {
    keepbytes <- integer(0)
    keepoffset <- integer(0)
  } else {
    pos <- which(parsed$keep) - 1
    keepbytes <- floor(pos/4)
    keepoffset <- pos %% 4 * 2
  }
  
  if(is.null(init)) init <- rep(0.0, parsed$p) else {
    stopifnot(is.numeric(init) && length(init) == parsed$p)
  }
 # print(extract2[[1]])
 # print(extract2[[2]])
 # print(4000-sum(extract2[[2]]))
  
  init <- init + 0.0 # force R to create a copy
  
  order <- order(lambda, decreasing = T)

  if(ncol(cor)>2){
    adjr <- cor[,-1] * adj
    adj <- apply(adj,1,sum)
    adjr <- apply(adjr,1,sum)
    cor <- cbind(cor[,1],adjr)    
  }

  if(length(lambda_ct) >= 1) {
    if(trace) cat("Running ssCTPR ...\n")
    results <- lapply(lambda_ct, function(ct) {
      if(trace) cat("lambda_ct = ", ct, "\n")
      runElnet(lambda[order], shrink, ct, fileName=paste0(bfile,".bed"), 
               r=cor, adj=adj, N=parsed$N, P=parsed$P, 
               col_skip_pos=extract2[[1]], col_skip=extract2[[2]],
               keepbytes=keepbytes, keepoffset=keepoffset, 
               thr=thr, x=init, trace=trace, maxiter=maxiter,
               startvec=Blocks$startvec, endvec=Blocks$endvec)
    })
  }
  names(results) <- as.character(lambda_ct)
  
  
  # 
  # results <- runElnet(lambda[order], shrink, fileName=paste0(bfile,".bed"), 
  #                     r=cor, N=parsed$N, P=parsed$P, 
  #                     col_skip_pos=extract2[[1]], col_skip=extract2[[2]],
  #                     keepbytes=keepbytes, keepoffset=keepoffset, 
  #                     thr=1e-4, x=init, trace=trace, maxiter=maxiter,
  #                     startvec=Blocks$startvec, endvec=Blocks$endvec)
  for (jj in 1:length(results)) {
    results[[jj]]$sd <- as.vector(results[[jj]]$sd)
    results[[jj]] <- within(results[[jj]], {
      conv[order] <- conv
      beta[,order] <- beta
      pred[,order] <- pred
      loss[order] <- loss
      fbeta[order] <- fbeta
      lambda[order] <- lambda
    })
    results[[jj]]$shrink <- shrink
    
    if(length(lambda) > 0){ results[[jj]]$nparams <- as.vector(colSums(results[[jj]]$beta != 0))} else{
      results[[jj]]$nparams <- numeric(0)
    } 
    results[[jj]]$conv <- as.vector(results[[jj]]$conv)
    results[[jj]]$loss <- as.vector(results[[jj]]$loss)
    results[[jj]]$fbeta <- as.vector(results[[jj]]$fbeta)
    results[[jj]]$lambda <- as.vector(results[[jj]]$lambda)
  }
  
  class(results) <- "ssCTPR"
  return(results)
  #' @return A list with the following
  #' \item{lambda}{same as the lambda input}
  #' \item{beta}{A matrix of estimated coefficients}
  #' \item{conv}{A vector of convergence indicators. 1 means converged. 0 not converged.}
  #' \item{pred}{\eqn{=\sqrt(1-s)X\beta}}
  #' \item{loss}{\eqn{=(1-s)\beta'X'X\beta/n - 2\beta'r}}
  #' \item{fbeta}{\eqn{=\beta'R\beta - 2\beta'r + 2\lambda||\beta||_1}}
  #' \item{sd}{The standard deviation of the reference panel SNPs}
  #' \item{shrink}{same as input}
  #' \item{lambda_ct}{same as input}
  #' \item{nparams}{Number of non-zero coefficients}
}

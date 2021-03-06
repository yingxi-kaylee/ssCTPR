#' @title Function to validate output from ssCTPR.pipeline with external phenotype
#' @param ls.pipeline A ssCTPR.pipeline object
#' @param test.bfile The (\href{https://www.cog-genomics.org/plink2/formats#bed}{PLINK bfile} for the test dataset 
#' @param keep Participants to keep (see \code{\link{ssCTPR}} for more details)
#' @param remove Participants to remove
#' @param pheno A vector of phenotype OR a \code{data.frame} with 3 columns, the first 2 columns being headed "FID" and "IID", OR a filename for such a data.frame
#' @param covar A matrix of covariates OR a \code{data.frame} with 3 or more columns, the first 2 columns being headed "FID" and "IID", OR a filename for such a data.frame
#' @param validate.function Function with which to perform validation
#' @param trace Controls amount of output
#' @param destandardize Should coefficients from \code{\link{ssCTPR}} be 
#' destandardized using test dataset standard deviations before being returned?
#' @param exclude.ambiguous Should ambiguous SNPs (C/G, A/T) be excluded? 
#' @param cluster A \code{cluster} object from the \code{parallel} package for parallel computing
#' @param rematch Forces a rematching of the ls.pipline beta's with the new .bim file
#' @param ... parameters to pass to \code{\link{sd.bfile}}
#' @details Chooses the best \code{lambda} and \code{s} by validating 
#' polygenic score against an external phenotype in the testing dataset. 
#' If \code{pheno} is not specified, then the sixth column in the testing 
#' dataset \href{https://www.cog-genomics.org/plink2/formats#fam}{.fam}\code{.fam} file is used. 
#' @rdname validate
#' @export
validate.ssCTPR.pipeline <- function(ls.pipeline, test.bfile=NULL, 
                              keep=NULL, remove=NULL, 
                              pheno=NULL, covar=NULL, 
                              validate.function=function(x, y) 
                                cor(x, y, use="complete"),
                              trace=1, 
                              destandardize=F,
                              exclude.ambiguous=T, 
                              cluster=NULL, 
                              rematch=!is.null(test.bfile), ...) {
  

  stopifnot(class(ls.pipeline) == "ssCTPR.pipeline")
  cat("YINGXI: line36\n")
  lambda_cts <- as.numeric(names(ls.pipeline$beta))
  results <- list(lambda=ls.pipeline$lambda, s=ls.pipeline$s, lambda_ctp=lambda_cts)
  
  rematch <- rematch # Forces an evaluation at this point
  if(is.null(test.bfile)) {
    test.bfile <- ls.pipeline$test.bfile
    keep.through.pheno <- !is.null(pheno) && 
                             ((is.data.frame(pheno)) || 
                              (is.character(pheno) && length(pheno) == 1))
    if(is.null(keep) && is.null(remove) && !keep.through.pheno)
      keep <- ls.pipeline$keep.test
  }

  ### Pheno & covar ### 
  parsed.test <- parseselect(test.bfile, keep=keep, remove=remove, export=TRUE)
  phcovar <- parse.pheno.covar(pheno=pheno, covar=covar, parsed=parsed.test, 
                               trace=trace)
  parsed.test <- phcovar$parsed
  pheno <- phcovar$pheno
  covar <- phcovar$covar
  
  ### Destandardize ### 
  if(destandardize) {
    if(ls.pipeline$destandardized) stop("beta in ls.pipeline already destandardized.")
    sd <- sd.bfile(test.bfile, extract=ls.pipeline$test.extract, 
                   keep=parsed.test$keep, trace=trace)
    sd[sd <= 0] <- Inf # Do not want infinite beta's!
    # if(ls.pipeline$traits>1){
    #   sd <- rep(sd,ls.pipeline$traits)
    # }
    for(ii in 1:length(ls.pipeline$beta)){
      ls.pipeline$beta[[ii]] <- lapply(ls.pipeline$beta[[ii]], function(x) as.matrix(Matrix::Diagonal(x=1/sd) %*% x))
    }
    
    # ls.pipeline$beta <- lapply(ls.pipeline$beta, 
    #                            function(x) as.matrix(Matrix::Diagonal(x=1/sd) %*% x))
    recal <- T
  }

  if(rematch) {
    if(trace) cat("Coordinating ssCTPR output with test data...\n")
    
    if(length(test.bfile) > 1) stop("Multiple 'test.bfile's not supported here.")
    bim <- fread(paste0(test.bfile, ".bim"))
    bim$V1 <- as.character(sub("^chr", "", bim$V1, ignore.case = T))
    
    m <- matchpos(ls.pipeline$sumstats, bim, auto.detect.ref = F, 
                       ref.chr = "V1", ref.snp="V2", ref.pos="V4", ref.alt="V5", ref.ref="V6", 
                       rm.duplicates = T, exclude.ambiguous = exclude.ambiguous, 
                       silent=T)
    cat("YINGXI: line87\n")
    beta <- list()
    for(ii in 1:length(ls.pipeline$beta)){
      beta[[as.character(ii)]] <- lapply(ls.pipeline$beta[[ii]], function(x) as.matrix(Matrix::Diagonal(x=m$rev) %*% x[m$order,]))
    }
    
    
    # beta <- lapply(ls.pipeline$beta, function(x) 
    #   as.matrix(Matrix::Diagonal(x=m$rev) %*% x[m$order, ]))
    
    if(trace) cat("Calculating PGS...\n")
    cat("YINGXI: line98\n")
    pgs <- list()
    for(ii in 1:length(beta)){
      pgs[[as.character(ii)]] <- lapply(beta[[ii]], function(x) pgs(bfile=test.bfile, weights = x, 
                                                                            extract=m$ref.extract, keep=parsed.test$keep, 
                                                                            cluster=cluster))
    }  #need to modify?? solved
    # pgs <- lapply(beta, function(x) pgs(bfile=test.bfile, weights = x, 
    #                                     extract=m$ref.extract, 
    #                                     keep=parsed.test$keep, 
    #                                     cluster=cluster, 
    #                                     trace=trace-1))
    cat("YINGXI: line110\n")
    names(pgs) <- names(ls.pipeline$beta)
    results <- c(results, list(pgs=pgs))

  } else {
    recal <- !identical(ls.pipeline$test.bfile, test.bfile) || 
      !identical(parsed.test$keep, ls.pipeline$keep.test)
    if(is.null(ls.pipeline$pgs) || recal) { ## need to modify? solved
      if(trace) cat("Calculating PGS...\n")
      cat("YINGXI: line119\n")
      pgs <- list()
      for(ii in 1:length(ls.pipeline$beta)){
        pgs[[as.character(ii)]] <- lapply(ls.pipeline$beta[[ii]], function(x) pgs(bfile=test.bfile, weights = x, 
                                                                      extract=ls.pipeline$test.extract, keep=parsed.test$keep, 
                                                                      cluster=cluster))
      } 
      # pgs <- lapply(ls.pipeline$beta, function(x) pgs(bfile=test.bfile, 
      #                                     weights = x, 
      #                                     extract=ls.pipeline$test.extract, 
      #                                     keep=parsed.test$keep, 
      #                                     cluster=cluster, 
      #                                     trace=trace-1))
      cat("YINGXI: line132\n")
      names(pgs) <- names(ls.pipeline$beta)
      results <- c(results, list(pgs=pgs))
    } else {
    # } else if(is.null(parsed.test$keep)) {
      results <- c(results, list(pgs=ls.pipeline$pgs))
    # } else {
    #   pgs <- ls.pipeline$pgs
    #   for(i in 1:length(pgs)) {
    #     pgs[[i]] <- pgs[[i]][parsed.test$keep, ]
    #   }
    #   results <- c(results, list(pgs=pgs))
    }
    beta <- ls.pipeline$beta
  } 

  ### Prepare PGS ###
  lambdas <- rep(ls.pipeline$lambda, length(ls.pipeline$s))
  ss <- rep(ls.pipeline$s, rep(length(ls.pipeline$lambda), length(ls.pipeline$s)))
  PGS <- list()
  for(ii in 1:length(results$pgs)){
    PGS[[as.character(ii)]] <- do.call("cbind", results$pgs[[ii]])
  }
  names(PGS) <- names(results$pgs)
  
  ### pheno ###
  if(sd(pheno, na.rm = TRUE) == 0 && ncol(PGS) > 1) 
    stop("There's no variation in phenotype")

  ### covar ### 
  if(!is.null(covar)) {
    for(ii in length(PGS)){
      for(i in 1:ncol(PGS[[ii]])) {
        PGS[[ii]][,i] <- residuals(lm(PGS[[1]][,i] ~ ., data=covar, na.action = na.exclude))
      }  
    }
    
    stopifnot(nrow(covar) == parsed.test$n) 
    adj.pheno <- resid(lm(pheno ~ ., data=covar, na.action = na.exclude))
  } else {
    adj.pheno <- pheno
  }
  
  ### Validate ###
  cors <- list()
  suppressWarnings(
    for(ii in 1:length(PGS)){
      cors[[as.character(ii)]] <- as.vector(
        apply(PGS[[ii]], MARGIN = 2, FUN=validate.function, adj.pheno)) 
    })
  names(cors) <- names(PGS)
  
  if(is.function(validate.function)) {
    funcname <- deparse(substitute(validate.function))
  } else if(is.character(validate.function)) {
    funcname <- validate.function
  } else {
    stop("What is being passed to validate.function? I can't figure out.")
  }

  cors <- lapply(cors, function(x){
    x[is.na(x)] <- -Inf
    return(x) 
  })
  max_cor <- sapply(cors, function(x) max(x))
  best.ct.index <- which(max_cor == max(max_cor))[1]
  best.ct <- as.numeric(names(cors)[best.ct.index])
  best.index <- which(cors[[best.ct.index]]==max(max_cor))[1]
  best.s <- ss[best.index]
  best.lambda <- lambdas[best.index]
  best.pgs <- PGS[[best.ct.index]][,best.index]
  len.lambda <- length(ls.pipeline$lambda)
  best.beta.s <- ceiling(best.index / len.lambda)
  best.beta.lambda <- best.index %% len.lambda
  best.beta.lambda[best.beta.lambda == 0] <- len.lambda
  best.beta <- beta[[best.ct.index]][[best.beta.s]][,best.beta.lambda] ## need to modify? Solved
  
  validation.table <- lapply(cors, function(x) data.frame(lambda=lambdas, s=ss, value=x))
  
  #### Results table ####
  if(is.null(phcovar$table)) {
    if(is.null(parsed.test[['fam']])) parsed.test[['fam']] <- read.table2(parsed.test$famfile)
    results.table <- parsed.test[['fam']][,1:2]
    colnames(results.table) <- c("FID", "IID")
    if(!is.null(parsed.test$keep)) results.table <- results.table[parsed.test$keep,]
    results.table$pheno <- pheno
    results.table$best.pgs <- best.pgs
  } else {
    results.table <- phcovar$table
    results.table$best.pgs <- best.pgs[results.table$order]
  }
  
  results <- c(results, list(best.s=best.s, 
                             best.ct=best.ct,
                             best.lambda=best.lambda,
                             best.pgs=best.pgs, 
                             best.beta=best.beta, 
                             traits=ls.pipeline$traits,
                             validation.table=validation.table, 
                             validation.type=funcname, 
                             pheno=pheno, 
                             best.validation.result=max(max_cor), 
                             results.table=results.table))
  class(results) <- "validate.ssCTPR"
  return(results)

}

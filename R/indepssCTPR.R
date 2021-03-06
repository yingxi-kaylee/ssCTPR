#' @title Independent ssCTPR based on summary statistics (a.k.a. soft-thresholding)
#' 
#' @param coef vector/matrix of regression coefficients (\eqn{r})
#' @param adj vector of adjacency coefficients
#' @param lambda a vector of \eqn{\lambda}s 
#' @param lambda_ct a vector of \eqn{\lambda_{ctp}}s
#' @param thr threshold to stop CD algorithm
#' @param maxiter the maximum number of iterations
#' @param trace controls the amount of output
#' 
#' @details A function to find the minimum of \eqn{\beta} in  
#' \deqn{f(\beta)=\beta'\beta - 2\beta'r + 2\lambda||\beta||_1 + \lambda_{ct}||\beta-\s{t}||^{2}}
#' where \eqn{r} is the vector of regression coefficients.
#' @export
indepssCTPR <- function(coef, adj, lambda=exp(seq(log(0.001), log(0.1), length.out=20)), lambda_ct, thr=1e-4,maxiter=10000, trace=1) {
  coef <- as.matrix(coef)
  traits <- ncol(coef)
  p <- nrow(coef)
  
  if(traits==1){ # single trait
    results <- matrix(0,ncol = length(lambda), p)
    for(i in 1:length(lambda)) {
      results[,i] <- sign(coef) * pmax((abs(coef) - lambda[i]),0)
    }
    ls <- list()
    ls[[as.character(0)]] <- list(lambda=lambda, beta=results)
  } else{ # cross traits
    indeplasso_fixed_ctp <- function(lambda_ct){
      results <- matrix(0,ncol = length(lambda), p)
      ctp <- lambda_ct*coef[,2]
      for(i in 1:length(lambda)) {
        results[,i] <- sign(coef[,1]+ctp) * pmax((abs(coef[,1]+ctp) - lambda[i]),0) / (1+lambda_ct*adj)
      }
      
      return(list(lambda=lambda, beta=results))
    }
    
    ls <- list()
    if(length(lambda_ct) > 0) {
      if(trace) cat("Running independent ssCTPR ...\n")
      ls <- lapply(lambda_ct, function(ct) {
        if(trace) cat("lambda_ct = ", ct, "\n")
        indeplasso_fixed_ctp(ct)
      })
    }
    names(ls) <- as.character(lambda_ct)
  }
  
  #' @return A list with the length equal to the number of lambda_ct, each element of the list has teh following elements
  #' \item{lambda}{Same as \code{lambda} in input}
  #' \item{beta}{A matrix of estimates of \eqn{\beta}}

  return(ls)
}

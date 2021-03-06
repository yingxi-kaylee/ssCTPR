% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/subset.ssCTPR.pipeline.R
\name{subset.ssCTPR.pipeline}
\alias{subset.ssCTPR.pipeline}
\title{Subset a ssCTPR.pipeline object by lambda, s and lambda_ct}
\usage{
\method{subset}{ssCTPR.pipeline}(ssCTPR.pipeline, s = NULL, lambda = NULL, lambda_ct = NULL)
}
\arguments{
\item{ssCTPR.pipeline}{An object returned by ssCTPR.pipeline}

\item{s}{Value(s) of s to restrict to}

\item{lambda}{Value(s) of lambda to restrict to}

\item{lambda_ct}{Values(s) of lambda_ct to restrict to}
}
\value{
A ssCTPR.pipeline object
}
\description{
Subset a ssCTPR.pipeline object by lambda, s and lambda_ct
}
\details{
This function is usually used to reapply a validated pgs to a new data.set. 
See example below.
}
\examples{
\dontrun{
 ### Run ssCTPR using standard pipeline ### 
 lp <- ssCTPR.pipeline(cor=cor, traits=ncol(cor), lambda_ct = lambda_ct,
                          chr=ss$Chr, pos=ss$Position, 
                          A1=ss$A1, A2=ss$A2,
                          ref.bfile=ref.bfile, test.bfile=test.bfile, 
                          LDblocks = ld)
 v <- validate(lp)
 lp2 <- subset(lp, s=v$best.s, lambda=v$best.lambda, lambda_ct=v$best.lambda_ct)
 v2 <- validate(lp2)
}
}

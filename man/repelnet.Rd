% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{repelnet}
\alias{repelnet}
\title{performs elnet by blocks}
\usage{
repelnet(
  lambda1,
  lambda2,
  lambda_ct,
  diag,
  X,
  r,
  adj,
  thr,
  x,
  yhat,
  trace,
  maxiter,
  startvec,
  endvec
)
}
\arguments{
\item{lambda1}{lambda}

\item{lambda2}{shrinkage parameter s}

\item{lambda_ct}{cross trait penalty}

\item{diag}{diag(X'X)}

\item{X}{genotype Matrix}

\item{r}{correlations}

\item{adj}{adjacency coefficients}

\item{thr}{threshold}

\item{x}{beta coef}

\item{yhat}{A vector, X*x}

\item{trace}{if >1 displays the current iteration}

\item{maxiter}{maximal number of iterations}

\item{startvec}{start position for each block}

\item{endvec}{end position for each block}
}
\value{
conv
}
\description{
performs elnet by blocks
}
\keyword{internal}

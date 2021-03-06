// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/ssCTPR.h"
#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

// countlines
int countlines(const char* fileName);
static SEXP _ssCTPR_countlines_try(SEXP fileNameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const char* >::type fileName(fileNameSEXP);
    rcpp_result_gen = Rcpp::wrap(countlines(fileName));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_countlines(SEXP fileNameSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_countlines_try(fileNameSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// multiBed3
arma::mat multiBed3(const std::string fileName, int N, int P, const arma::mat input, arma::Col<int> col_skip_pos, arma::Col<int> col_skip, arma::Col<int> keepbytes, arma::Col<int> keepoffset, const int trace);
static SEXP _ssCTPR_multiBed3_try(SEXP fileNameSEXP, SEXP NSEXP, SEXP PSEXP, SEXP inputSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP traceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::string >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    Rcpp::traits::input_parameter< int >::type P(PSEXP);
    Rcpp::traits::input_parameter< const arma::mat >::type input(inputSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type col_skip_pos(col_skip_posSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type col_skip(col_skipSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type keepbytes(keepbytesSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type keepoffset(keepoffsetSEXP);
    Rcpp::traits::input_parameter< const int >::type trace(traceSEXP);
    rcpp_result_gen = Rcpp::wrap(multiBed3(fileName, N, P, input, col_skip_pos, col_skip, keepbytes, keepoffset, trace));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_multiBed3(SEXP fileNameSEXP, SEXP NSEXP, SEXP PSEXP, SEXP inputSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP traceSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_multiBed3_try(fileNameSEXP, NSEXP, PSEXP, inputSEXP, col_skip_posSEXP, col_skipSEXP, keepbytesSEXP, keepoffsetSEXP, traceSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// multiBed3sp
arma::mat multiBed3sp(const std::string fileName, int N, int P, const arma::vec beta, const arma::Col<int> nonzeros, const arma::Col<int> colpos, const int ncol, arma::Col<int> col_skip_pos, arma::Col<int> col_skip, arma::Col<int> keepbytes, arma::Col<int> keepoffset, const int trace);
static SEXP _ssCTPR_multiBed3sp_try(SEXP fileNameSEXP, SEXP NSEXP, SEXP PSEXP, SEXP betaSEXP, SEXP nonzerosSEXP, SEXP colposSEXP, SEXP ncolSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP traceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::string >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    Rcpp::traits::input_parameter< int >::type P(PSEXP);
    Rcpp::traits::input_parameter< const arma::vec >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::Col<int> >::type nonzeros(nonzerosSEXP);
    Rcpp::traits::input_parameter< const arma::Col<int> >::type colpos(colposSEXP);
    Rcpp::traits::input_parameter< const int >::type ncol(ncolSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type col_skip_pos(col_skip_posSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type col_skip(col_skipSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type keepbytes(keepbytesSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type keepoffset(keepoffsetSEXP);
    Rcpp::traits::input_parameter< const int >::type trace(traceSEXP);
    rcpp_result_gen = Rcpp::wrap(multiBed3sp(fileName, N, P, beta, nonzeros, colpos, ncol, col_skip_pos, col_skip, keepbytes, keepoffset, trace));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_multiBed3sp(SEXP fileNameSEXP, SEXP NSEXP, SEXP PSEXP, SEXP betaSEXP, SEXP nonzerosSEXP, SEXP colposSEXP, SEXP ncolSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP traceSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_multiBed3sp_try(fileNameSEXP, NSEXP, PSEXP, betaSEXP, nonzerosSEXP, colposSEXP, ncolSEXP, col_skip_posSEXP, col_skipSEXP, keepbytesSEXP, keepoffsetSEXP, traceSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// elnet
int elnet(double lambda1, double lambda2, double lambda_ct, const arma::vec& diag, const arma::mat& X, const arma::mat& r, const arma::vec& adj, double thr, arma::vec& x, arma::vec& yhat, int trace, int maxiter);
static SEXP _ssCTPR_elnet_try(SEXP lambda1SEXP, SEXP lambda2SEXP, SEXP lambda_ctSEXP, SEXP diagSEXP, SEXP XSEXP, SEXP rSEXP, SEXP adjSEXP, SEXP thrSEXP, SEXP xSEXP, SEXP yhatSEXP, SEXP traceSEXP, SEXP maxiterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< double >::type lambda1(lambda1SEXP);
    Rcpp::traits::input_parameter< double >::type lambda2(lambda2SEXP);
    Rcpp::traits::input_parameter< double >::type lambda_ct(lambda_ctSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type diag(diagSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type r(rSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type adj(adjSEXP);
    Rcpp::traits::input_parameter< double >::type thr(thrSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type yhat(yhatSEXP);
    Rcpp::traits::input_parameter< int >::type trace(traceSEXP);
    Rcpp::traits::input_parameter< int >::type maxiter(maxiterSEXP);
    rcpp_result_gen = Rcpp::wrap(elnet(lambda1, lambda2, lambda_ct, diag, X, r, adj, thr, x, yhat, trace, maxiter));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_elnet(SEXP lambda1SEXP, SEXP lambda2SEXP, SEXP lambda_ctSEXP, SEXP diagSEXP, SEXP XSEXP, SEXP rSEXP, SEXP adjSEXP, SEXP thrSEXP, SEXP xSEXP, SEXP yhatSEXP, SEXP traceSEXP, SEXP maxiterSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_elnet_try(lambda1SEXP, lambda2SEXP, lambda_ctSEXP, diagSEXP, XSEXP, rSEXP, adjSEXP, thrSEXP, xSEXP, yhatSEXP, traceSEXP, maxiterSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// repelnet
int repelnet(double lambda1, double lambda2, double lambda_ct, arma::vec& diag, arma::mat& X, arma::mat& r, arma::vec& adj, double thr, arma::vec& x, arma::vec& yhat, int trace, int maxiter, arma::Col<int>& startvec, arma::Col<int>& endvec);
static SEXP _ssCTPR_repelnet_try(SEXP lambda1SEXP, SEXP lambda2SEXP, SEXP lambda_ctSEXP, SEXP diagSEXP, SEXP XSEXP, SEXP rSEXP, SEXP adjSEXP, SEXP thrSEXP, SEXP xSEXP, SEXP yhatSEXP, SEXP traceSEXP, SEXP maxiterSEXP, SEXP startvecSEXP, SEXP endvecSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< double >::type lambda1(lambda1SEXP);
    Rcpp::traits::input_parameter< double >::type lambda2(lambda2SEXP);
    Rcpp::traits::input_parameter< double >::type lambda_ct(lambda_ctSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type diag(diagSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type r(rSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type adj(adjSEXP);
    Rcpp::traits::input_parameter< double >::type thr(thrSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type yhat(yhatSEXP);
    Rcpp::traits::input_parameter< int >::type trace(traceSEXP);
    Rcpp::traits::input_parameter< int >::type maxiter(maxiterSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type startvec(startvecSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type endvec(endvecSEXP);
    rcpp_result_gen = Rcpp::wrap(repelnet(lambda1, lambda2, lambda_ct, diag, X, r, adj, thr, x, yhat, trace, maxiter, startvec, endvec));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_repelnet(SEXP lambda1SEXP, SEXP lambda2SEXP, SEXP lambda_ctSEXP, SEXP diagSEXP, SEXP XSEXP, SEXP rSEXP, SEXP adjSEXP, SEXP thrSEXP, SEXP xSEXP, SEXP yhatSEXP, SEXP traceSEXP, SEXP maxiterSEXP, SEXP startvecSEXP, SEXP endvecSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_repelnet_try(lambda1SEXP, lambda2SEXP, lambda_ctSEXP, diagSEXP, XSEXP, rSEXP, adjSEXP, thrSEXP, xSEXP, yhatSEXP, traceSEXP, maxiterSEXP, startvecSEXP, endvecSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// genotypeMatrix
arma::mat genotypeMatrix(const std::string fileName, int N, int P, arma::Col<int> col_skip_pos, arma::Col<int> col_skip, arma::Col<int> keepbytes, arma::Col<int> keepoffset, const int fillmissing);
static SEXP _ssCTPR_genotypeMatrix_try(SEXP fileNameSEXP, SEXP NSEXP, SEXP PSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP fillmissingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< const std::string >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    Rcpp::traits::input_parameter< int >::type P(PSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type col_skip_pos(col_skip_posSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type col_skip(col_skipSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type keepbytes(keepbytesSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type keepoffset(keepoffsetSEXP);
    Rcpp::traits::input_parameter< const int >::type fillmissing(fillmissingSEXP);
    rcpp_result_gen = Rcpp::wrap(genotypeMatrix(fileName, N, P, col_skip_pos, col_skip, keepbytes, keepoffset, fillmissing));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_genotypeMatrix(SEXP fileNameSEXP, SEXP NSEXP, SEXP PSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP fillmissingSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_genotypeMatrix_try(fileNameSEXP, NSEXP, PSEXP, col_skip_posSEXP, col_skipSEXP, keepbytesSEXP, keepoffsetSEXP, fillmissingSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// normalize
arma::vec normalize(arma::mat& genotypes);
static SEXP _ssCTPR_normalize_try(SEXP genotypesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type genotypes(genotypesSEXP);
    rcpp_result_gen = Rcpp::wrap(normalize(genotypes));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_normalize(SEXP genotypesSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_normalize_try(genotypesSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// runElnet
List runElnet(arma::vec& lambda, double shrink, double lambda_ct, const std::string fileName, arma::mat& r, arma::vec& adj, int N, int P, arma::Col<int>& col_skip_pos, arma::Col<int>& col_skip, arma::Col<int>& keepbytes, arma::Col<int>& keepoffset, double thr, arma::vec& x, int trace, int maxiter, arma::Col<int>& startvec, arma::Col<int>& endvec);
static SEXP _ssCTPR_runElnet_try(SEXP lambdaSEXP, SEXP shrinkSEXP, SEXP lambda_ctSEXP, SEXP fileNameSEXP, SEXP rSEXP, SEXP adjSEXP, SEXP NSEXP, SEXP PSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP thrSEXP, SEXP xSEXP, SEXP traceSEXP, SEXP maxiterSEXP, SEXP startvecSEXP, SEXP endvecSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< arma::vec& >::type lambda(lambdaSEXP);
    Rcpp::traits::input_parameter< double >::type shrink(shrinkSEXP);
    Rcpp::traits::input_parameter< double >::type lambda_ct(lambda_ctSEXP);
    Rcpp::traits::input_parameter< const std::string >::type fileName(fileNameSEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type r(rSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type adj(adjSEXP);
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    Rcpp::traits::input_parameter< int >::type P(PSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type col_skip_pos(col_skip_posSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type col_skip(col_skipSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type keepbytes(keepbytesSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type keepoffset(keepoffsetSEXP);
    Rcpp::traits::input_parameter< double >::type thr(thrSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type trace(traceSEXP);
    Rcpp::traits::input_parameter< int >::type maxiter(maxiterSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type startvec(startvecSEXP);
    Rcpp::traits::input_parameter< arma::Col<int>& >::type endvec(endvecSEXP);
    rcpp_result_gen = Rcpp::wrap(runElnet(lambda, shrink, lambda_ct, fileName, r, adj, N, P, col_skip_pos, col_skip, keepbytes, keepoffset, thr, x, trace, maxiter, startvec, endvec));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP _ssCTPR_runElnet(SEXP lambdaSEXP, SEXP shrinkSEXP, SEXP lambda_ctSEXP, SEXP fileNameSEXP, SEXP rSEXP, SEXP adjSEXP, SEXP NSEXP, SEXP PSEXP, SEXP col_skip_posSEXP, SEXP col_skipSEXP, SEXP keepbytesSEXP, SEXP keepoffsetSEXP, SEXP thrSEXP, SEXP xSEXP, SEXP traceSEXP, SEXP maxiterSEXP, SEXP startvecSEXP, SEXP endvecSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(_ssCTPR_runElnet_try(lambdaSEXP, shrinkSEXP, lambda_ctSEXP, fileNameSEXP, rSEXP, adjSEXP, NSEXP, PSEXP, col_skip_posSEXP, col_skipSEXP, keepbytesSEXP, keepoffsetSEXP, thrSEXP, xSEXP, traceSEXP, maxiterSEXP, startvecSEXP, endvecSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    bool rcpp_isLongjump_gen = Rcpp::internal::isLongjumpSentinel(rcpp_result_gen);
    if (rcpp_isLongjump_gen) {
        Rcpp::internal::resumeJump(rcpp_result_gen);
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}

// validate (ensure exported C++ functions exist before calling them)
static int _ssCTPR_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("int(*countlines)(const char*)");
        signatures.insert("arma::mat(*multiBed3)(const std::string,int,int,const arma::mat,arma::Col<int>,arma::Col<int>,arma::Col<int>,arma::Col<int>,const int)");
        signatures.insert("arma::mat(*multiBed3sp)(const std::string,int,int,const arma::vec,const arma::Col<int>,const arma::Col<int>,const int,arma::Col<int>,arma::Col<int>,arma::Col<int>,arma::Col<int>,const int)");
        signatures.insert("int(*elnet)(double,double,double,const arma::vec&,const arma::mat&,const arma::mat&,const arma::vec&,double,arma::vec&,arma::vec&,int,int)");
        signatures.insert("int(*repelnet)(double,double,double,arma::vec&,arma::mat&,arma::mat&,arma::vec&,double,arma::vec&,arma::vec&,int,int,arma::Col<int>&,arma::Col<int>&)");
        signatures.insert("arma::mat(*genotypeMatrix)(const std::string,int,int,arma::Col<int>,arma::Col<int>,arma::Col<int>,arma::Col<int>,const int)");
        signatures.insert("arma::vec(*normalize)(arma::mat&)");
        signatures.insert("List(*runElnet)(arma::vec&,double,double,const std::string,arma::mat&,arma::vec&,int,int,arma::Col<int>&,arma::Col<int>&,arma::Col<int>&,arma::Col<int>&,double,arma::vec&,int,int,arma::Col<int>&,arma::Col<int>&)");
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP _ssCTPR_RcppExport_registerCCallable() { 
    R_RegisterCCallable("ssCTPR", "_ssCTPR_countlines", (DL_FUNC)_ssCTPR_countlines_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_multiBed3", (DL_FUNC)_ssCTPR_multiBed3_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_multiBed3sp", (DL_FUNC)_ssCTPR_multiBed3sp_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_elnet", (DL_FUNC)_ssCTPR_elnet_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_repelnet", (DL_FUNC)_ssCTPR_repelnet_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_genotypeMatrix", (DL_FUNC)_ssCTPR_genotypeMatrix_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_normalize", (DL_FUNC)_ssCTPR_normalize_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_runElnet", (DL_FUNC)_ssCTPR_runElnet_try);
    R_RegisterCCallable("ssCTPR", "_ssCTPR_RcppExport_validate", (DL_FUNC)_ssCTPR_RcppExport_validate);
    return R_NilValue;
}

static const R_CallMethodDef CallEntries[] = {
    {"_ssCTPR_countlines", (DL_FUNC) &_ssCTPR_countlines, 1},
    {"_ssCTPR_multiBed3", (DL_FUNC) &_ssCTPR_multiBed3, 9},
    {"_ssCTPR_multiBed3sp", (DL_FUNC) &_ssCTPR_multiBed3sp, 12},
    {"_ssCTPR_elnet", (DL_FUNC) &_ssCTPR_elnet, 12},
    {"_ssCTPR_repelnet", (DL_FUNC) &_ssCTPR_repelnet, 14},
    {"_ssCTPR_genotypeMatrix", (DL_FUNC) &_ssCTPR_genotypeMatrix, 8},
    {"_ssCTPR_normalize", (DL_FUNC) &_ssCTPR_normalize, 1},
    {"_ssCTPR_runElnet", (DL_FUNC) &_ssCTPR_runElnet, 18},
    {"_ssCTPR_RcppExport_registerCCallable", (DL_FUNC) &_ssCTPR_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_ssCTPR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// windowsInterruptGAMS
int windowsInterruptGAMS(int pid);
RcppExport SEXP _miro_util_windowsInterruptGAMS(SEXP pidSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type pid(pidSEXP);
    rcpp_result_gen = Rcpp::wrap(windowsInterruptGAMS(pid));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_miro_util_windowsInterruptGAMS", (DL_FUNC) &_miro_util_windowsInterruptGAMS, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_miro_util(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
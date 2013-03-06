# TEST EXECS
DEF_TRIG = check_vd_cos check_vd_sin check_vd_tan check_vd_acos check_vd_asin check_vd_atan check_vd_atan2  check_vd_sincos
DEF_ARITH = check_vd_abs check_vd_add check_vd_addx check_vd_div check_vd_divx check_vd_mul check_vd_mulx check_vd_sqr check_vd_sub check_vd_subx check_vd_xsub check_vd_xdiv check_vd_negate
DEF_EL = check_vd_exp check_vd_expm1 check_vd_ln check_vd_log10 check_vd_log1p
DEF_HYP = check_vd_acosh check_vd_asinh check_vd_atanh check_vd_cosh check_vd_sinh check_vd_tanh
DEF_SPECFUN = check_vd_cdfnorm check_vd_erf check_vd_erfc check_vd_lgamma check_vd_tgamma
DEF_PWR = check_vd_cbrt check_vd_hypot check_vd_inv check_vd_invcbrt check_vd_invsqrt check_vd_pow check_vd_powx check_vd_pow2o3 check_vd_pow3o2 check_vd_sqrt
DEF_ROUND = check_vd_ceil check_vd_floor check_vd_modf check_vd_nearbyint check_vd_rint check_vd_round check_vd_trunc

TESTS=$(DEF_TRIG) $(DEF_ARITH) $(DEF_EL) $(DEF_HYP) $(DEF_SPECFUN) $(DEF_PWR) $(DEF_ROUND)

# PROGRAMS

check_PROGRAMS = $(DEF_TRIG) $(DEF_ARITH) $(DEF_EL) $(DEF_HYP) $(DEF_SPECFUN) $(DEF_PWR) $(DEF_ROUND)
LDADD = $(top_builddir)/src/libizy.la
INCLUDES = -I $(top_builddir)/include/
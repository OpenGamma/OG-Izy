# TEST EXECS
DEF_TRIG = check_vdcos check_vdsin check_vdtan check_vdacos check_vdasin check_vdatan check_vdatan2  check_vdsincos
DEF_ARITH = check_vdabs check_vdadd check_vdaddx check_vddiv check_vddivx check_vdmul check_vdmulx check_vdsqr check_vdsub check_vdsubx 
DEF_EL = check_vdexp check_vdexpm1 check_vdln check_vdlog10 check_vdlog1p
DEF_HYP = check_vdacosh check_vdasinh check_vdatanh check_vdcosh check_vdsinh check_vdtanh
DEF_SPECFUN = check_vdcdfnorm check_vderf check_vderfc check_vdlgamma check_vdtgamma
DEF_PWR = check_vdcbrt check_vdhypot check_vdinv check_vdinvcbrt check_vdinvsqrt check_vdpow check_vdpowx check_vdpow2o3 check_vdpow3o2 check_vdsqrt
DEF_ROUND = check_vdceil check_vdfloor check_vdmodf check_vdnearbyint check_vdrint check_vdround check_vdtrunc

TESTS=$(DEF_TRIG) $(DEF_ARITH) $(DEF_EL) $(DEF_HYP) $(DEF_SPECFUN) $(DEF_PWR) $(DEF_ROUND)

# PROGRAMS

check_PROGRAMS = $(DEF_TRIG) $(DEF_ARITH) $(DEF_EL) $(DEF_HYP) $(DEF_SPECFUN) $(DEF_PWR) $(DEF_ROUND)
LDADD = $(top_builddir)/src/libizy.la
INCLUDES = -I $(top_builddir)/include/
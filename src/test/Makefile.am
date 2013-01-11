# TEST EXECS
DEF_TRIG = check_vdcos check_vdsin check_vdtan check_vdacos check_vdasin check_vdatan check_vdatan2  check_vdsincos
DEF_ARITH = check_vdabs check_vdadd check_vdaddx check_vddiv check_vddivx check_vdmul check_vdmulx check_vdsqr check_vdsub check_vdsubx 
DEF_EL = check_vdexp check_vdexpm1 check_vdln check_vdlog10 check_vdlog1p
DEF_HYP = check_vdacosh check_vdasinh check_vdatanh check_vdcosh check_vdsinh check_vdtanh
DEF_SPECFUN = check_vdcdfnorm check_vderf check_vderfc check_vdlgamma check_vdtgamma

TESTS=$(DEF_TRIG) $(DEF_ARITH) $(DEF_EL) $(DEF_HYP) $(DEF_SPECFUN)

# PROGRAMS

check_PROGRAMS = $(DEF_TRIG) $(DEF_ARITH) $(DEF_EL) $(DEF_HYP) $(DEF_SPECFUN)
LDADD = $(top_builddir)/src/libizy.la
INCLUDES = -I $(top_builddir)/include/

# TRIG
check_vdcos_SOURCES = check_vdcos.c 
# check_vdcos_LDADD = $(top_builddir)/src/libizy.la
check_vdsin_SOURCES = check_vdsin.c 
check_vdtan_SOURCES = check_vdtan.c 
check_vdacos_SOURCES = check_vdacos.c 
check_vdasin_SOURCES = check_vdasin.c 
check_vdatan_SOURCES = check_vdatan.c 
check_vdatan2_SOURCES = check_vdatan2.c 
check_vdsincos_SOURCES = check_vdsincos.c 

# ARITH
check_vdabs_SOURCES = check_vdabs.c 
check_vdadd_SOURCES = check_vdadd.c 
check_vdaddx_SOURCES = check_vdaddx.c 
check_vddiv_SOURCES = check_vddiv.c 
check_vddivx_SOURCES = check_vddivx.c 
check_vdmul_SOURCES = check_vdmul.c 
check_vdmulx_SOURCES = check_vdmulx.c 
check_vdsqr_SOURCES = check_vdsqr.c 
check_vdsub_SOURCES = check_vdsub.c 
check_vdsubx_SOURCES = check_vdsubx.c 

# EXP+LOG
check_vdexp_SOURCES = check_vdexp.c 
check_vdexpm1_SOURCES = check_vdexpm1.c
check_vdln_SOURCES = check_vdln.c
check_vdlog10_SOURCES = check_vdlog10.c
check_vdlog1p_SOURCES = check_vdlog1p.c

# HYPERBOLIC
check_vdacosh_SOURCES = check_vdacosh.c
check_vdasinh_SOURCES = check_vdasinh.c
check_vdatanh_SOURCES = check_vdatanh.c
check_vdcosh_SOURCES = check_vdcosh.c
check_vdsinh_SOURCES = check_vdsinh.c
check_vdtanh_SOURCES = check_vdtanh.c

#SPECFUN
check_vdcdfnorm_SOURCES = check_vdcdfnorm.c
#check_vdcdfnorminv_SOURCES = check_vdcdfnorminv.c
check_vderf_SOURCES = check_vderf.c
check_vderfc_SOURCES = check_vderfc.c
#check_vderfinv_SOURCES = check_vderfinv.c
#check_vderfcinv_SOURCES = check_vderfcinv.c
check_vdlgamma_SOURCES = check_vdlgamma.c
check_vdtgamma_SOURCES = check_vdtgamma.c
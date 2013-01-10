# TEST EXECS
DEF_TRIG = check_vdcos check_vdsin check_vdtan check_vdacos check_vdasin check_vdatan check_vdatan2  check_vdsincos
DEF_ARITH = check_vdadd check_vdaddx check_vdsub check_vdsubx check_vdmul check_vdmulx check_vddiv check_vddivx

TESTS=$(DEF_TRIG) $(DEF_ARITH)

# PROGRAMS

check_PROGRAMS = $(DEF_TRIG) $(DEF_ARITH)
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
check_vdadd_SOURCES = check_vdadd.c 

check_vdaddx_SOURCES = check_vdaddx.c 

check_vdsub_SOURCES = check_vdsub.c 

check_vdsubx_SOURCES = check_vdsubx.c 

check_vdmul_SOURCES = check_vdmul.c 

check_vdmulx_SOURCES = check_vdmulx.c 

check_vddiv_SOURCES = check_vddiv.c 

check_vddivx_SOURCES = check_vddiv.c 




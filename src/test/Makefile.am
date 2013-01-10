# TEST EXECS
DEF_TRIG = check_vdcos check_vdsin check_vdtan check_vdacos check_vdasin check_vdatan check_vdatan2  check_vdsincos
DEF_ARITH = check_vdadd check_vdaddx

TESTS=$(DEF_TRIG) $(DEF_ARITH)

# PROGRAMS

check_PROGRAMS = $(DEF_TRIG) $(DEF_ARITH)

INCLUDES = -I $(top_builddir)/include/

# TRIG
check_vdcos_SOURCES = check_vdcos.c 
check_vdcos_LDADD = $(top_builddir)/src/libizy.la

check_vdsin_SOURCES = check_vdsin.c 
check_vdsin_LDADD = $(top_builddir)/src/libizy.la

check_vdtan_SOURCES = check_vdtan.c 
check_vdtan_LDADD = $(top_builddir)/src/libizy.la

check_vdacos_SOURCES = check_vdacos.c 
check_vdacos_LDADD = $(top_builddir)/src/libizy.la

check_vdasin_SOURCES = check_vdasin.c 
check_vdasin_LDADD = $(top_builddir)/src/libizy.la

check_vdatan_SOURCES = check_vdatan.c 
check_vdatan_LDADD = $(top_builddir)/src/libizy.la

check_vdatan2_SOURCES = check_vdatan2.c 
check_vdatan2_LDADD = $(top_builddir)/src/libizy.la

check_vdsincos_SOURCES = check_vdsincos.c 
check_vdsincos_LDADD = $(top_builddir)/src/libizy.la

# ARITH
check_vdadd_SOURCES = check_vdadd.c 
check_vdadd_LDADD = $(top_builddir)/src/libizy.la

check_vdaddx_SOURCES = check_vdaddx.c 
check_vdaddx_LDADD = $(top_builddir)/src/libizy.la


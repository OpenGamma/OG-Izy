AC_PREREQ(2.5)
AC_INIT(libizy,0.0.1,stuart@opengamma.com)
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_AWK
AC_PROG_SED
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_CPP
AC_PROG_CXX
# see if we can use GNU SOURCE, this is called high so that CFLAGS flags are mangled in the correct order
AC_GNU_SOURCE
LT_INIT()
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_LIBTOOL
AM_PROG_CC_C_O
AC_PROG_FC

AS_IF([test "x$CC" != "gcc"],[
# guess at flags for architectural tuning
AX_GCC_ARCHFLAG
],[])



# check for f77
AC_PROG_F77([fl32 f77 fort77 xlf g77 f90 xlf90 gfortran])
AC_F77_WRAPPERS

#checks for openmp
AX_OPENMP([  ] , [ echo \
"------------------------------------------------------------------------
ERROR: Compiler does not appear to support OpenMP, testing needs this!
------------------------------------------------------------------------"
exit]) 


# Checks for libraries.

# Checks for functions in libraries, makes sure they do stuff
AC_CHECK_LIB([m], [pow],[],[
echo \
"------------------------------------------------------------------------
ERROR: libm appears to be missing. This is quite unusual. The RPM
glibc-devel usually contains this library. Alternatively it can be
obtained from http://www.gnu.org/s/libc/
------------------------------------------------------------------------"
exit
])


# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h])
AC_CHECK_HEADERS([float.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset])


# Adds in versioning for libraries
# According to http://sources.redhat.com/autobook/autobook/autobook_91.html#SEC91
# Versions go like this:
#If you have changed any of the sources for this library, the revision number must be incremented. This is a new revision of the current interface.

#If the interface has changed, then current must be incremented, and revision reset to `0'. This is the first revision of a new interface.

#If the new interface is a superset of the previous interface (that is, if the previous interface has not been broken by the changes in this new release), then age must be incremented. This release is backwards compatible with the previous release.

#If the new interface has removed elements with respect to the previous interface, then you have broken backward compatibility and age must be reset to `0'. This release has a new, but backwards incompatible interface. 

LIBIZY_CURRENT=0
LIBIZY_REVISION=1
LIBIZY_AGE=0
LIBIZY_VERSION=$LIBIZY_CURRENT:\
$LIBIZY_REVISION:$LIBIZY_AGE
AC_SUBST(LIBIZY_VERSION)



AC_SUBST(OMP_CFLAGS,$OPENMP_CFLAGS)

AC_CONFIG_FILES([Makefile
                src/Makefile
                src/reference/Makefile
                ])
AM_INIT_AUTOMAKE
AC_OUTPUT

echo "
  Package: $PACKAGE_NAME version $PACKAGE_VERSION
  Prefix.............: $prefix
  C Compiler.........: $CC $CFLAGS $CPPFLAGS
  Linker.............: $LD $LDFLAGS $LIBS
  OPENMP.............: ${OPENMP_CFLAGS}
"

#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

# Include folder
include_directories (${IZY_SOURCE_DIR}/include)

# Linker path needs izy folder for izy library
link_directories (${IZY_BINARY_DIR}/izy)

# Set test names
set(DEF_DOUBLE_TRIG check_vd_cos check_vd_sin check_vd_tan check_vd_acos check_vd_asin check_vd_atan check_vd_atan2  check_vd_sincos)
set(DEF_DOUBLE_ARITH check_vd_abs check_vd_add check_vd_addx check_vd_div check_vd_divx check_vd_mul check_vd_mulx check_vd_sqr check_vd_sub check_vd_subx check_vd_xsub check_vd_xdiv check_vd_negate)
set(DEF_DOUBLE_EL check_vd_exp check_vd_expm1 check_vd_ln check_vd_log10 check_vd_log1p)
set(DEF_DOUBLE_HYP check_vd_acosh check_vd_asinh check_vd_atanh check_vd_cosh check_vd_sinh check_vd_tanh)
set(DEF_DOUBLE_SPECFUN check_vd_cdfnorm check_vd_erf check_vd_erfc check_vd_lgamma check_vd_tgamma)
set(DEF_DOUBLE_PWR check_vd_cbrt check_vd_hypot check_vd_inv check_vd_invcbrt check_vd_invsqrt check_vd_pow check_vd_powx check_vd_pow2o3 check_vd_pow3o2 check_vd_sqrt)
set(DEF_DOUBLE_ROUND check_vd_ceil check_vd_floor check_vd_modf check_vd_nearbyint check_vd_rint check_vd_round check_vd_trunc)
set(DEF_COMPLEX_TRIG check_vz_sin check_vz_cos check_vz_tan check_vz_asin check_vz_acos check_vz_atan)
set(DEF_COMPLEX_HYP check_vz_sinh check_vz_cosh check_vz_tanh check_vz_asinh check_vz_acosh check_vz_atanh)
set(DEF_COMPLEX_ARITH check_vz_add check_vz_sub check_vz_mul check_vz_div check_vz_addx check_vz_subx check_vz_mulx check_vz_divx check_vz_xsub check_vz_xdiv check_vz_abs check_vz_arg check_vz_negate check_vz_negatereal check_vz_conj check_vz_mulbyconj)
set(DEF_COMPLEX_EL check_vz_exp check_vz_ln check_vz_log10)
set(DEF_COMPLEX_PWR check_vz_sqrt check_vz_pow check_vz_powx)

set(TESTS ${DEF_DOUBLE_TRIG} ${DEF_DOUBLE_ARITH} ${DEF_DOUBLE_EL} ${DEF_DOUBLE_HYP} ${DEF_DOUBLE_SPECFUN} ${DEF_DOUBLE_PWR} ${DEF_DOUBLE_ROUND} ${DEF_COMPLEX_TRIG} ${DEF_COMPLEX_HYP} ${DEF_COMPLEX_PWR} ${DEF_COMPLEX_ARITH})

# Compile and link each test, and add to the list of tests.
foreach(TEST ${TESTS})
  add_executable(${TEST} ${TEST}.c)
  target_link_libraries(${TEST} izy izyreference)
  get_target_property(TEST_LOC ${TEST} LOCATION)
  add_test(${TEST} ${TEST_LOC})
  if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_test(${TEST}_memcheck valgrind --leak-check=full --error-exitcode=1 ${TEST_LOC})
  endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
endforeach()

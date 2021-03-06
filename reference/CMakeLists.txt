#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

# Include folders
include_directories (${IZY_SOURCE_DIR}/include)

# Sources for the IZY reference library
set(REFSRC reference_vd_abs.c reference_vd_acos.c reference_vd_acosh.c reference_vd_add.c reference_vd_addx.c reference_vd_asin.c reference_vd_asinh.c reference_vd_atan2.c reference_vd_atan.c reference_vd_atanh.c reference_vd_cbrt.c reference_vd_cdfnorm.c  reference_vd_ceil.c reference_vd_cos.c reference_vd_cosh.c reference_vd_div.c reference_vd_divx.c reference_vd_erf.c reference_vd_erfc.c reference_vd_exp.c reference_vd_expm1.c reference_vd_floor.c reference_vd_hypot.c reference_vd_inv.c reference_vd_invcbrt.c reference_vd_invsqrt.c reference_vd_lgamma.c reference_vd_linearfrac.c reference_vd_ln.c reference_vd_log10.c reference_vd_log1p.c reference_vd_modf.c reference_vd_mul.c reference_vd_mulx.c reference_vd_nearbyint.c reference_vd_negate.c reference_vd_pow2o3.c reference_vd_pow3o2.c reference_vd_pow.c reference_vd_powx.c reference_vd_rint.c reference_vd_round.c reference_vd_sin.c reference_vd_sincos.c reference_vd_sinh.c reference_vd_sqr.c reference_vd_sqrt.c reference_vd_sub.c reference_vd_subx.c reference_vd_tan.c reference_vd_tanh.c reference_vd_tgamma.c reference_vd_trunc.c reference_vd_xdiv.c reference_vd_xsub.c reference_vz_abs.c reference_vz_acos.c reference_vz_acosh.c reference_vz_add.c reference_vz_addx.c reference_vz_arg.c reference_vz_asin.c reference_vz_asinh.c reference_vz_atan.c reference_vz_atanh.c reference_vz_conj.c reference_vz_cos.c reference_vz_cosh.c reference_vz_div.c reference_vz_divx.c reference_vz_exp.c reference_vz_ln.c reference_vz_log10.c reference_vz_mulbyconj.c reference_vz_mul.c reference_vz_mulx.c reference_vz_negate.c reference_vz_negatereal.c reference_vz_pow.c reference_vz_powx.c reference_vz_sin.c reference_vz_sinh.c reference_vz_sqrt.c reference_vz_sub.c reference_vz_subx.c reference_vz_tan.c reference_vz_tanh.c reference_vz_xdiv.c reference_vz_xsub.c)

## unimplemented function stubs
# set(UNIMPLEMENTED reference_vd_cdfnorminv.c reference_vd_erfcinv.c reference_vd_erfinv.c)

# build multilib
add_multitarget_library(izyreference
                        VERSION ${IZY_VERSION}
                        SOVERSION ${IZY_VERSION_MAJOR}
                        SOURCES ${REFSRC}
                        LINK_LIBRARIES m
                        TARGETS ${TARGET_TYPES})

add_multitarget_export(izyreference
                        EXPORTNAME "IZY_EXPORTS"
                        TARGETS ${TARGET_TYPES}
                      )
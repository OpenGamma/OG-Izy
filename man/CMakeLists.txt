#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

# All man page names
set(MANS vd_abs vd_acos vd_acosh vd_add vd_addx vd_asin vd_asinh vd_atan2 vd_atan vd_atanh vd_cbrt vd_cdfnorm vd_cdfnorminv vd_ceil vd_cos vd_cosh vd_div vd_divx vd_erf vd_erfc vd_erfcinv vd_erfinv vd_exp vd_expm1 vd_floor vd_hypot vd_inv vd_invcbrt vd_invsqrt vd_lgamma vd_ln vd_log10 vd_log1p vd_modf vd_mul vd_mulx vd_nearbyint vd_negate vd_pow2o3 vd_pow vd_pow3o2 vd_powx vd_rint vd_round vd_sin vd_sincos vd_sinh vd_sqr vd_sqrt vd_sub vd_subx vd_tan vd_tanh vd_tgamma vd_trunc vd_xdiv vd_xsub vz_abs vz_acos vz_acosh vz_add vz_addx vz_arg vz_asin vz_asinh vz_atan vz_atanh vz_conj vz_cos vz_cosh vz_div vz_divx vz_exp vz_ln vz_log10 vz_mul vz_mulbyconj vz_mulx vz_negate vz_negatereal vz_pow vz_powx vz_sin vz_sinh vz_sqrt vz_sub vz_subx vz_tan vz_tanh vz_xdiv vz_xsub)

# Set location to install each man page
foreach(MAN ${MANS})
  install(FILES ${MAN}.3 DESTINATION share/man3 COMPONENT doc)
endforeach()

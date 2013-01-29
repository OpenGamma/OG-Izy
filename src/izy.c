// libizy
#include "libizy/izy.h"
#include "libizy/izyreference.h"

/* 1 arg 1 result */

#define IZY_ONEARGONERESULT(_T,_NAME) \
v##_T##_reference_##_NAME(count, arg0, offsetarg0, out0, offsetout0);

#define IZY_D_ONEARGONERESULT(_NAME) IZY_ONEARGONERESULT(d,_NAME)
#define IZY_Z_ONEARGONERESULT(_NAME) IZY_ONEARGONERESULT(z,_NAME)

/* 1 arg 2 results */

#define IZY_ONEARGTWORESULT(_T,_NAME) \
v##_T##_reference_##_NAME(count, arg0, offsetarg0, out0, offsetout0, out1, offsetout1);

#define IZY_D_ONEARGTWORESULT(_NAME) IZY_ONEARGTWORESULT(d,_NAME)
#define IZY_Z_ONEARGTWORESULT(_NAME) IZY_ONEARGTWORESULT(z,_NAME)


/* 2 arg 1 result */

#define IZY_TWOARGONERESULT(_T,_NAME) \
v##_T##_reference_##_NAME(count, arg0, offsetarg0, arg1, offsetarg1, out0, offsetout0);

#define IZY_D_TWOARGONERESULT(_NAME) IZY_TWOARGONERESULT(d,_NAME)
#define IZY_Z_TWOARGONERESULT(_NAME) IZY_TWOARGONERESULT(z,_NAME)



void vd_acos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(acos)
};

void vd_asin(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(asin)
};

void vd_atan(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(atan)
};

void vd_atan2(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(atan2)
};

void vd_cos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cos)
};

void vd_sin(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sin)
};

void vd_sincos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1)
{
 IZY_D_ONEARGTWORESULT(sincos)
};

void vd_tan(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(tan)
};

void vd_acosh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(acosh)
};

void vd_asinh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(asinh)
};

void vd_atanh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(atanh)
};

void vd_cosh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cosh)
};

void vd_sinh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sinh)
};

void vd_tanh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(tanh)
};

void vd_cbrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cbrt)
};

void vd_hypot(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(hypot)
};

void vd_inv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(inv)
};

void vd_invcbrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(invcbrt)
};

void vd_invsqrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(invsqrt)
};

void vd_pow(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(pow)
};

void vd_powx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(powx)
};

void vd_pow2o3(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(pow2o3)
};

void vd_pow3o2(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(pow3o2)
};

void vd_sqrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sqrt)
};

void vd_exp(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(exp)
};

void vd_expm1(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(expm1)
};

void vd_ln(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(ln)
};

void vd_log10(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(log10)
};

void vd_log1p(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(log1p)
};

void vd_abs(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(abs)
};

void vd_add(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(add)
};

void vd_addx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(addx)
};

void vd_div(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(div)
};

void vd_divx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(divx)
};

void vd_mul(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(mul)
};

void vd_mulx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(mulx)
};

void vd_sqr(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sqr)
};

void vd_sub(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(sub)
};

void vd_subx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(subx)
};

void vd_ceil(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(ceil)
};

void vd_floor(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(floor)
};

void vd_modf(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1)
{
 IZY_D_ONEARGTWORESULT(modf)
};

void vd_nearbyint(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(nearbyint)
};

void vd_rint(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(rint)
};

void vd_round(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(round)
};

void vd_trunc(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(trunc)
};

void vd_cdfnorm(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cdfnorm)
};

void vd_cdfnorminv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cdfnorminv)
};

void vd_erf(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erf)
};

void vd_erfc(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erfc)
};

void vd_erfinv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erfinv)
};

void vd_erfcinv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erfcinv)
};

void vd_lgamma(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(lgamma)
};

void vd_tgamma(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(tgamma)
};

/* COMPLEX */

void vz_abs(const int * count, const double complex * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(abs)
};

void vz_acos(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(acos)
};

void vz_acosh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(acosh)
};

void vz_add(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(add)
};

void vz_addx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(addx)
};

void vz_arg(const int * count, const double complex * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(arg)
};

void vz_asin(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(asin)
};

void vz_asinh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(asinh)
};

void vz_atan(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(atan)
};
void vz_atanh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(atanh)
};
void vz_conj(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(conj)
};

void vz_cos(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(cos)
};

void vz_cosh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(cosh)
};

void vz_div(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(div)
};

void vz_divx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(divx)
};

void vz_exp(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(exp)
};

void vz_ln(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(ln)
};

void vz_log10(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(log10)
};

void vz_mul(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(mul)
};

void vz_mulx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(mulx)
};

void vz_mulbyconj(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(mulbyconj)
};

void vz_pow(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(pow)
};

void vz_powx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(powx)
};

void vz_sin(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(sin)
};

void vz_sinh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(sinh)
};

void vz_sqrt(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(sqrt)
};

void vz_sub(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(sub)
};

void vz_subx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(subx)
};

void vz_tan(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(tan)
};

void vz_tanh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(tanh)
};


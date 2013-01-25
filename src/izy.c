// libizy
#include "libizy/izy.h"
#include "libizy/izyreference.h"


#define IZY_REFERENCE_ONEARGONERESULT(_NAME) \
vd_reference_##_NAME(arg0, offsetarg0, out0, offsetout0, count);




#define IZY_REFERENCE_ONEARGTWORESULT(_NAME) \
vd_reference_##_NAME(arg0, offsetarg0, out0, offsetout0, out1, offsetout1, count);





#define IZY_REFERENCE_TWOARGONERESULT(_NAME) \
vd_reference_##_NAME(arg0, offsetarg0, arg1, offsetarg1, out0, offsetout0, count);




#define IZY_REFERENCE_TWOARGONEISCONSTONERESULT(_NAME)\
vd_reference_##_NAME(arg0, offsetarg0, arg1, offsetarg1, out0, offsetout0, count);



void vd_acos(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(acos)
};

void vd_asin(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(asin)
};

void vd_atan(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(atan)
};

void vd_atan2(double * arg0, const int * offsetarg0, double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONERESULT(atan2)
};

void vd_cos(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(cos)
};

void vd_sin(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(sin)
};

void vd_sincos(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1, const int * count)
{
 IZY_REFERENCE_ONEARGTWORESULT(sincos)
};

void vd_tan(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(tan)
};

void vd_acosh(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(acosh)
};

void vd_asinh(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(asinh)
};

void vd_atanh(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(atanh)
};

void vd_cosh(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(cosh)
};

void vd_sinh(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(sinh)
};

void vd_tanh(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(tanh)
};

void vd_cbrt(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(cbrt)
};

void vd_hypot(double * arg0, const int * offsetarg0, double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONERESULT(hypot)
};

void vd_inv(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(inv)
};

void vd_invcbrt(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(invcbrt)
};

void vd_invsqrt(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(invsqrt)
};

void vd_pow(double * arg0, const int * offsetarg0, double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(pow)
};

void vd_powx(double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(powx)
};

void vd_pow2o3(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(pow2o3)
};

void vd_pow3o2(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(pow3o2)
};

void vd_sqrt(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(sqrt)
};

void vd_exp(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(exp)
};

void vd_expm1(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(expm1)
};

void vd_ln(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(ln)
};

void vd_log10(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(log10)
};

void vd_log1p(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(log1p)
};

void vd_abs(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(abs)
};

void vd_add(double * arg0, const int * offsetarg0, double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONERESULT(add)
};

void vd_addx(double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(addx)
};

void vd_div(double * arg0, const int * offsetarg0, double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONERESULT(div)
};

void vd_divx(double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(divx)
};

void vd_mul(double * arg0, const int * offsetarg0, double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONERESULT(mul)
};

void vd_mulx(double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(mulx)
};

void vd_sqr(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(sqr)
};

void vd_sub(double * arg0, const int * offsetarg0, double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONERESULT(sub)
};

void vd_subx(double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(subx)
};

void vd_ceil(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(ceil)
};

void vd_floor(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(floor)
};

void vd_modf(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1, const int * count)
{
 IZY_REFERENCE_ONEARGTWORESULT(modf)
};

void vd_nearbyint(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(nearbyint)
};

void vd_rint(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(rint)
};

void vd_round(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(round)
};

void vd_trunc(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(trunc)
};

void vd_cdfnorm(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(cdfnorm)
};

void vd_cdfnorminv(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(cdfnorminv)
};

void vd_erf(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(erf)
};

void vd_erfc(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(erfc)
};

void vd_erfinv(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(erfinv)
};

void vd_erfcinv(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(erfcinv)
};

void vd_lgamma(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(lgamma)
};

void vd_tgamma(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
 IZY_REFERENCE_ONEARGONERESULT(tgamma)
};

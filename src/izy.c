// libizy
#include "libizy/izy.h"
#include "libizy/izyreference.h"


#define IZY_REFERENCE_ONEARGONERESULT(_NAME) \
vd_reference_##_NAME(count, arg0, offsetarg0, out0, offsetout0);




#define IZY_REFERENCE_ONEARGTWORESULT(_NAME) \
vd_reference_##_NAME(count, arg0, offsetarg0, out0, offsetout0, out1, offsetout1);





#define IZY_REFERENCE_TWOARGONERESULT(_NAME) \
vd_reference_##_NAME(count, arg0, offsetarg0, arg1, offsetarg1, out0, offsetout0);




#define IZY_REFERENCE_TWOARGONEISCONSTONERESULT(_NAME)\
vd_reference_##_NAME(count, arg0, offsetarg0, arg1, offsetarg1, out0, offsetout0);



void vd_acos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(acos)
};

void vd_asin(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(asin)
};

void vd_atan(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(atan)
};

void vd_atan2(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONERESULT(atan2)
};

void vd_cos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(cos)
};

void vd_sin(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(sin)
};

void vd_sincos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1)
{
 IZY_REFERENCE_ONEARGTWORESULT(sincos)
};

void vd_tan(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(tan)
};

void vd_acosh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(acosh)
};

void vd_asinh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(asinh)
};

void vd_atanh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(atanh)
};

void vd_cosh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(cosh)
};

void vd_sinh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(sinh)
};

void vd_tanh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(tanh)
};

void vd_cbrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(cbrt)
};

void vd_hypot(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONERESULT(hypot)
};

void vd_inv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(inv)
};

void vd_invcbrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(invcbrt)
};

void vd_invsqrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(invsqrt)
};

void vd_pow(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(pow)
};

void vd_powx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(powx)
};

void vd_pow2o3(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(pow2o3)
};

void vd_pow3o2(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(pow3o2)
};

void vd_sqrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(sqrt)
};

void vd_exp(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(exp)
};

void vd_expm1(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(expm1)
};

void vd_ln(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(ln)
};

void vd_log10(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(log10)
};

void vd_log1p(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(log1p)
};

void vd_abs(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(abs)
};

void vd_add(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONERESULT(add)
};

void vd_addx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(addx)
};

void vd_div(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONERESULT(div)
};

void vd_divx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(divx)
};

void vd_mul(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONERESULT(mul)
};

void vd_mulx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(mulx)
};

void vd_sqr(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(sqr)
};

void vd_sub(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONERESULT(sub)
};

void vd_subx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_TWOARGONEISCONSTONERESULT(subx)
};

void vd_ceil(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(ceil)
};

void vd_floor(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(floor)
};

void vd_modf(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1)
{
 IZY_REFERENCE_ONEARGTWORESULT(modf)
};

void vd_nearbyint(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(nearbyint)
};

void vd_rint(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(rint)
};

void vd_round(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(round)
};

void vd_trunc(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(trunc)
};

void vd_cdfnorm(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(cdfnorm)
};

void vd_cdfnorminv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(cdfnorminv)
};

void vd_erf(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(erf)
};

void vd_erfc(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(erfc)
};

void vd_erfinv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(erfinv)
};

void vd_erfcinv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(erfcinv)
};

void vd_lgamma(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(lgamma)
};

void vd_tgamma(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_REFERENCE_ONEARGONERESULT(tgamma)
};

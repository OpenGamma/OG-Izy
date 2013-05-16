// libizy
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_MKL
#include "mkl.h"
#endif

#include "libizy/izy.h"
#include "libizy/izyreference.h"

/* 1 arg 1 result */
#ifdef HAVE_MKL

#define IZY_ONEARGONERESULT(_T,_NAME,_MKLNAME,CAST) \
v##_T##_MKLNAME(*count, CAST &arg0[*offsetarg0], CAST &out0[*offsetout0]);
#define IZY_D_ONEARGONERESULT(_NAME,_MKLNAME) IZY_ONEARGONERESULT(d,_NAME,_MKLNAME,)
#define IZY_Z_ONEARGONERESULT(_NAME,_MKLNAME) IZY_ONEARGONERESULT(z,_NAME,_MKLNAME,(MKL_Complex16 *))

#else

#define IZY_ONEARGONERESULT(_T,_NAME,_MKLNAME) \
v##_T##_reference_##_NAME(count, arg0, offsetarg0, out0, offsetout0);
#define IZY_D_ONEARGONERESULT(_NAME,_MKLNAME) IZY_ONEARGONERESULT(d,_NAME,_MKLNAME)
#define IZY_Z_ONEARGONERESULT(_NAME,_MKLNAME) IZY_ONEARGONERESULT(z,_NAME,_MKLNAME)

#endif

/* 1 arg 2 results */
#ifdef HAVE_MKL

#define IZY_ONEARGTWORESULT(_T,_NAME,_MKLNAME,CAST) \
v##_T##_MKLNAME(*count, CAST &arg0[*offsetarg0], CAST &out0[*offsetout0], CAST &out1[*offsetout1]);
#define IZY_D_ONEARGTWORESULT(_NAME,_MKLNAME) IZY_ONEARGTWORESULT(d,_NAME,_MKLNAME,)
#define IZY_Z_ONEARGTWORESULT(_NAME,_MKLNAME) IZY_ONEARGTWORESULT(z,_NAME,_MKLNAME,(MKL_Complex16 *))

#else

#define IZY_ONEARGTWORESULT(_T,_NAME,_MKLNAME) \
v##_T##_reference_##_NAME(count, arg0, offsetarg0, out0, offsetout0, out1, offsetout1);
#define IZY_D_ONEARGTWORESULT(_NAME,_MKLNAME) IZY_ONEARGTWORESULT(d,_NAME,_MKLNAME)
#define IZY_Z_ONEARGTWORESULT(_NAME,_MKLNAME) IZY_ONEARGTWORESULT(z,_NAME,_MKLNAME)

#endif




/* 2 arg 1 result */
#ifdef HAVE_MKL

#define IZY_TWOARGONERESULT(_T,_NAME,_MKLNAME,CAST)\
v##_T##_MKLNAME(*count, CAST &arg0[*offsetarg0], CAST &arg1[*offsetarg1], CAST &out0[*offsetout0]);
#define IZY_D_TWOARGONERESULT(_NAME,_MKLNAME) IZY_TWOARGONERESULT(d,_NAME,_MKLNAME,)
#define IZY_Z_TWOARGONERESULT(_NAME,_MKLNAME) IZY_TWOARGONERESULT(z,_NAME,_MKLNAME,(MKL_Complex16 *))

#else

#define IZY_TWOARGONERESULT(_T,_NAME,_MKLNAME) \
v##_T##_reference_##_NAME(count, arg0, offsetarg0, arg1, offsetarg1, out0, offsetout0);
#define IZY_D_TWOARGONERESULT(_NAME,_MKLNAME) IZY_TWOARGONERESULT(d,_NAME,_MKLNAME)
#define IZY_Z_TWOARGONERESULT(_NAME,_MKLNAME) IZY_TWOARGONERESULT(z,_NAME,_MKLNAME)

#endif





void vd_acos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
IZY_D_ONEARGONERESULT(acos,Acos)
};

void vd_asin(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(asin,Asin)
};

void vd_atan(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(atan,Atan)
};

void vd_atan2(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(atan2,Atan2)
};

void vd_cos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cos,Cos)
};

void vd_sin(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sin,Sin)
};

void vd_sincos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1)
{
 IZY_D_ONEARGTWORESULT(sincos,SinCos)
};

void vd_tan(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(tan,Tan)
};

void vd_acosh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(acosh,Acosh)
};

void vd_asinh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(asinh,Asinh)
};

void vd_atanh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(atanh,Atanh)
};

void vd_cosh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cosh,Cosh)
};

void vd_sinh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sinh,Sinh)
};

void vd_tanh(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(tanh,Tanh)
};

void vd_cbrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cbrt,Cbrt)
};

void vd_hypot(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(hypot,Hypot)
};

void vd_inv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(inv,Inv)
};

void vd_invcbrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(invcbrt,InvCbrt)
};

void vd_invsqrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(invsqrt,InvSqrt)
};

void vd_pow(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(pow,Pow)
};

void vd_powx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
#ifdef HAVE_MKL
	vdPowx(*count,&arg0[*offsetarg0],arg1[*offsetarg1],&out0[*offsetout0]);
#else
	vd_reference_powx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
#endif
 
};

void vd_pow2o3(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(pow2o3,Pow2o3)
};

void vd_pow3o2(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(pow3o2,Pow3o2)
};

void vd_sqrt(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sqrt,Sqrt)
};

void vd_exp(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(exp,Exp)
};

void vd_expm1(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(expm1,Expm1)
};

void vd_ln(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(ln,Ln)
};

void vd_log10(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(log10,Log10)
};

void vd_log1p(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(log1p,Log1p)
};

void vd_abs(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(abs,Abs)
};

void vd_negate(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 vd_reference_negate(count, arg0, offsetarg0, out0, offsetout0);
};

void vd_add(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(add,Add)
};

void vd_addx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 	vd_reference_addx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vd_div(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(div,Div)
};

void vd_divx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
	vd_reference_divx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vd_xdiv(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
  vd_reference_xdiv(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vd_mul(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(mul,Mul)
};

void vd_mulx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
	vd_reference_mulx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vd_sqr(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(sqr,Sqr)
};

void vd_sub(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
 IZY_D_TWOARGONERESULT(sub,Sub)
};

void vd_subx(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
	vd_reference_subx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vd_xsub(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0)
{
  vd_reference_xsub(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vd_ceil(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(ceil,Ceil)
};

void vd_floor(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(floor,Floor)
};

void vd_modf(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1)
{
 IZY_D_ONEARGTWORESULT(modf,Modf)
};

void vd_nearbyint(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(nearbyint,NearbyInt)
};

void vd_rint(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(rint,Rint)
};

void vd_round(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(round,Round)
};

void vd_trunc(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(trunc,Trunc)
};

void vd_cdfnorm(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cdfnorm,CdfNorm)
};

void vd_cdfnorminv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(cdfnorminv,CdfNormInv)
};

void vd_erf(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erf,Erf)
};

void vd_erfc(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erfc,Erfc)
};

void vd_erfinv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erfinv,ErfInv)
};

void vd_erfcinv(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(erfcinv,ErfcInv)
};

void vd_lgamma(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(lgamma,LGamma)
};

void vd_tgamma(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
 IZY_D_ONEARGONERESULT(tgamma,TGamma)
};

/* COMPLEX */

void vz_abs(const int * count, const double complex * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
#ifdef HAVE_MKL
	vzAbs(*count,(MKL_Complex16 *)&arg0[*offsetarg0],&out0[*offsetout0]);
#else
	vz_reference_abs(count,arg0,offsetarg0,out0,offsetout0);
#endif
};

void vz_acos(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(acos,Acos)
};

void vz_acosh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(acosh,Acosh)
};

void vz_add(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(add,Add)
};

void vz_addx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
 	vz_reference_addx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vz_arg(const int * count, const double complex * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
#ifdef HAVE_MKL
	vzArg(*count,(MKL_Complex16 *)&arg0[*offsetarg0],&out0[*offsetout0]);
#else
	vz_reference_arg(count,arg0,offsetarg0,out0,offsetout0);
#endif
};

void vz_asin(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(asin,Asin)
};

void vz_asinh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(asinh,Asinh)
};

void vz_atan(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(atan,Atan)
};

void vz_atanh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(atanh,Atanh)
};

void vz_conj(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(conj,Conj)
};

void vz_negatereal(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
  vz_reference_negatereal(count, arg0, offsetarg0, out0, offsetout0);
};

void vz_negate(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
  vz_reference_negate(count, arg0, offsetarg0, out0, offsetout0);
}

void vz_cos(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(cos,Cos)
};

void vz_cosh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(cosh,Cosh)
};

void vz_div(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(div,Div)
};

void vz_divx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
 	vz_reference_divx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vz_xdiv(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
  vz_reference_xdiv(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vz_exp(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(exp,Exp)
};

void vz_ln(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(ln,Ln)
};

void vz_log10(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(log10,Log10)
};

void vz_mul(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(mul,Mul)
};

void vz_mulx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
 	vz_reference_mulx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vz_mulbyconj(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(mulbyconj,MulByConj)
};

void vz_pow(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(pow,Pow)
};

void vz_powx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
#ifdef HAVE_MKL
	vzPowx(*count,(MKL_Complex16 *)&arg0[*offsetarg0],*(MKL_Complex16 *)&arg1[*offsetarg1],(MKL_Complex16 *)&out0[*offsetout0]);
#else
	vz_reference_powx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
#endif
};

void vz_sin(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(sin,Sin)
};

void vz_sinh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(sinh,Sinh)
};

void vz_sqrt(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(sqrt,Sqrt)
};

void vz_sub(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
IZY_Z_TWOARGONERESULT(sub,Sub)
};

void vz_subx(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
 	vz_reference_subx(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vz_xsub(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
  vz_reference_xsub(count,arg0,offsetarg0,arg1,offsetarg1,out0,offsetout0);
};

void vz_tan(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(tan,Tan)
};

void vz_tanh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
IZY_Z_ONEARGONERESULT(tanh,Tanh)
};


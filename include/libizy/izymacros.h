//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

#ifndef _IZYMACROS_H
#define _IZYMACROS_H 1

#ifdef __cplusplus
#include <complex>
#include <cstdint>
#else
#include <complex.h>
#include <stdint.h>
#endif

#ifdef __cplusplus
typedef std::complex<double> complex16;
typedef std::complex<float> complex8;
typedef double real8;
typedef float real4;
typedef std::int32_t int4;
#else
typedef double complex complex16;
typedef float complex complex8;
typedef double real8;
typedef float real4;
typedef int32_t int4;
#endif


/* double precision definitions */
#define _ONEARGONERESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const real8 * arg0, const int * offsetarg0, real8 * out0, const int * offsetout0);

#define _ONEARGTWORESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const real8 * arg0, const int * offsetarg0, real8 * out0, const int * offsetout0, real8 * out1, const int * offsetout1);

#define _TWOARGONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const real8 * arg0, const int * offsetarg0, const real8 * arg1, const int * offsetarg1, real8 * out0, const int * offsetout0);

#define _TWOARGONEISCONSTONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const real8 * arg0, const int * offsetarg0, const real8 * arg1, const int * offsetarg1, real8 * out0, const int * offsetout0);

#define _DVECTORONEARGONERESULTFUNCTION(_NAME) _ONEARGONERESULTFUNCTION(vd_, _NAME)
#define _DVECTORONEARGTWORESULTFUNCTION(_NAME) _ONEARGTWORESULTFUNCTION(vd_, _NAME)
#define _DVECTORTWOARGONERESULTFUNCTION(_NAME) _TWOARGONERESULTFUNCTION(vd_, _NAME)
#define _DVECTORTWOARGONEISCONSTONERESULTFUNCTION(_NAME) _TWOARGONEISCONSTONERESULTFUNCTION(vd_, _NAME)


/* real8 complex definitions */
#define _ZONECOMPLEXARGONECOMPLEXRESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const complex16 * arg0, const int * offsetarg0, complex16 * out0, const int * offsetout0);

#define _ZONECOMPLEXARGONEDOUBLERESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const complex16 * arg0, const int * offsetarg0, real8 * out0, const int * offsetout0);

#define _ZTWOCOMPLEXARGONECOMPLEXRESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const complex16 * arg0, const int * offsetarg0, const complex16 * arg1, const int * offsetarg1, complex16 * out0, const int * offsetout0);

#define _ZTWOCOMPLEXARGONEDOUBLERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const complex16 * arg0, const int * offsetarg0, const complex16 * arg1, const int * offsetarg1, real8 * out0, const int * offsetout0);

#define _ZVECTORONECOMPLEXARGONECOMPLEXRESULTFUNCTION(_NAME) _ZONECOMPLEXARGONECOMPLEXRESULTFUNCTION(vz_, _NAME)
#define _ZVECTORONECOMPLEXARGONEDOUBLERESULTFUNCTION(_NAME) _ZONECOMPLEXARGONEDOUBLERESULTFUNCTION(vz_, _NAME)
#define _ZVECTORTWOCOMPLEXARGONECOMPLEXRESULTFUNCTION(_NAME) _ZTWOCOMPLEXARGONECOMPLEXRESULTFUNCTION(vz_, _NAME)
#define _ZVECTORTWOCOMPLEXARGONEDOUBLERESULTFUNCTION(_NAME) _ZTWOCOMPLEXARGONEDOUBLERESULTFUNCTION(vz_, _NAME)

#endif

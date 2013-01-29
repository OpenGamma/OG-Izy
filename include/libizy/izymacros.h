#ifndef _IZYMACROS_H
#define _IZYMACROS_H 1

/* double precision definitions */
#define _ONEARGONERESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0);

#define _ONEARGTWORESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1);

#define _TWOARGONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0);

#define _TWOARGONEISCONSTONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0);

#define _DVECTORONEARGONERESULTFUNCTION(_NAME) _ONEARGONERESULTFUNCTION(vd_, _NAME)
#define _DVECTORONEARGTWORESULTFUNCTION(_NAME) _ONEARGTWORESULTFUNCTION(vd_, _NAME)
#define _DVECTORTWOARGONERESULTFUNCTION(_NAME) _TWOARGONERESULTFUNCTION(vd_, _NAME)
#define _DVECTORTWOARGONEISCONSTONERESULTFUNCTION(_NAME) _TWOARGONEISCONSTONERESULTFUNCTION(vd_, _NAME)


/* double complex definitions */
#define _ZONECOMPLEXARGONECOMPLEXRESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0);

#define _ZONECOMPLEXARGONEDOUBLERESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const double complex * arg0, const int * offsetarg0, double * out0, const int * offsetout0);

#define _ZTWOCOMPLEXARGONECOMPLEXRESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0);

#define _ZTWOCOMPLEXARGONEDOUBLERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double * out0, const int * offsetout0);

#define _ZVECTORONECOMPLEXARGONECOMPLEXRESULTFUNCTION(_NAME) _ZONECOMPLEXARGONECOMPLEXRESULTFUNCTION(vz_, _NAME)
#define _ZVECTORONECOMPLEXARGONEDOUBLERESULTFUNCTION(_NAME) _ZONECOMPLEXARGONEDOUBLERESULTFUNCTION(vz_, _NAME)
#define _ZVECTORTWOCOMPLEXARGONECOMPLEXRESULTFUNCTION(_NAME) _ZTWOCOMPLEXARGONECOMPLEXRESULTFUNCTION(vz_, _NAME)
#define _ZVECTORTWOCOMPLEXARGONEDOUBLERESULTFUNCTION(_NAME) _ZTWOCOMPLEXARGONEDOUBLERESULTFUNCTION(vz_, _NAME)

#endif

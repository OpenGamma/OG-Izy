#ifndef _IZYMACROS_H
#define _IZYMACROS_H 1

#define _ONEARGONERESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetin0, double * out0, const int * offsetout0);
#define _ONEARGTWORESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetin0, double * out0, const int * offsetout0, double * out1, const int * offsetout1);

#define _TWOARGONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0);
#define _TWOARGONERESULTSFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, double * out1, const int * offsetout1);
#define _TWOARGONEISCONSTONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(const int * count, const double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0);

#define _VECTORONEARGONERESULTFUNCTION(_NAME) _ONEARGONERESULTFUNCTION(vd_, _NAME)
#define _VECTORONEARGTWORESULTFUNCTION(_NAME) _ONEARGTWORESULTFUNCTION(vd_, _NAME)
#define _VECTORTWOARGONERESULTFUNCTION(_NAME) _TWOARGONERESULTFUNCTION(vd_, _NAME)
#define _VECTORTWOARGONEISCONSTONERESULTFUNCTION(_NAME) _TWOARGONEISCONSTONERESULTFUNCTION(vd_, _NAME)


#endif

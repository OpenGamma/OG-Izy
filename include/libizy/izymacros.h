#ifndef _IZYMACROS_H
#define _IZYMACROS_H 1

#define _ONEARGONERESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(double * arg0, const int * offsetin0, double * out0, const int * offsetout0, const int * count);
#define _ONEARGTWORESULTFUNCTION(_VECTORNAME,_NAME) void _VECTORNAME##_NAME(double * arg0, const int * offsetin0, double * out0, const int * offsetout0, double * out1, const int * offsetout1, const int * count);

#define _TWOARGONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(double * arg0, const int * offsetin0, double * arg1, const int * offset1, double * out0, const int * offsetout0, const int * count);
#define _TWOARGONERESULTSFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(double * arg0, const int * offsetin0, double const * arg1, const int * offset1, double out0, const int * offsetout0, double out1, const int * offsetout1, const int * count);
#define _TWOARGONEISCONSTONERESULTFUNCTION(_VECTORNAME, _NAME) void _VECTORNAME##_NAME(double * arg0, const int * offsetin0, const double * arg1, const int * offsetin1, double * out0, const int * offsetout0, const int * count);

#define _VECTORONEARGONERESULTFUNCTION(_NAME) _ONEARGONERESULTFUNCTION(vd_, _NAME)
#define _VECTORONEARGTWORESULTFUNCTION(_NAME) _ONEARGTWORESULTFUNCTION(vd_, _NAME)
#define _VECTORTWOARGONERESULTFUNCTION(_NAME) _TWOARGONERESULTFUNCTION(vd_, _NAME)
#define _VECTORTWOARGONEISCONSTONERESULTFUNCTION(_NAME) _TWOARGONEISCONSTONERESULTFUNCTION(vd_, _NAME)


#endif

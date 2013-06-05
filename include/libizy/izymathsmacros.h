//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

#ifndef IZYMATHSMACROS_H
#define IZYMATHSMACROS_H 1

#define DVOP(_OP) \
        int i;\
        double * out0ref;\
        const double * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        { \
                out0ref[i] = arg0ref[i] _OP arg1ref[i];\
        }

#define DVOPX(_OP) \
        int i;\
        double * out0ref;\
        const double * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]=arg0ref[i] _OP *arg1ref;\
        }

#define DVXOP(_OP) \
        int i;\
        double * out0ref;\
        const double * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]=*arg0ref _OP arg1ref[i];\
        }

#define DVFUNC(_OP) \
        int i; \
        double * out0ref;\
        const double * arg0ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i]);\
        }

#define DVFUNCWCONST(_OP,_CONST) \
        int i; \
        double * out0ref;\
        const double * arg0ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i], _CONST);\
        }

#define DVFUNC2ARG(_OP) \
        int i; \
        double * out0ref;\
        const double * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i], arg1ref[i]);\
        }

/* complex macros */
#define ZVOP(_OP) \
        int i;\
        double complex * out0ref;\
        const double complex * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        { \
                out0ref[i] = arg0ref[i] _OP arg1ref[i];\
        }

#define ZVOPX(_OP) \
        int i;\
        double complex * out0ref;\
        const double complex * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]=arg0ref[i] _OP *arg1ref;\
        }

#define ZVXOP(_OP) \
        int i;\
        double complex * out0ref;\
        const double complex * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= *arg0ref  _OP arg1ref[i];\
        }

#define ZVFUNC(_OP) \
        int i; \
        double complex * out0ref;\
        const double complex * arg0ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i]);\
        }

#define ZVFUNCWCONST(_OP,_CONST) \
        int i; \
        double complex * out0ref;\
        const double complex * arg0ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i], _CONST);\
        }

#define ZVFUNCD(_OP) \
        int i; \
        double * out0ref;\
        const double complex * arg0ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i]);\
        }

#define ZVFUNC2ARG(_OP) \
        int i; \
        double complex * out0ref;\
        const double complex * arg0ref, * arg1ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        arg1ref = &arg1[*offsetarg1];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i], arg1ref[i]);\
        }

#endif

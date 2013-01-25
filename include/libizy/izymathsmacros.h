#ifndef IZYMATHSMACROS_H
#define IZYMATHSMACROS_H 1

#define VOP(_OP) \
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

#define VOPX(_OP) \
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

#define VFUNC(_OP) \
        int i; \
        double * out0ref;\
        const double * arg0ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i]);\
        }

#define VFUNCWCONST(_OP,_CONST) \
        int i; \
        double * out0ref;\
        const double * arg0ref;\
        out0ref = &out0[*offsetout0];\
        arg0ref = &arg0[*offsetarg0];\
        for(i=0;i<*count;i++)\
        {\
                out0ref[i]= _OP(arg0ref[i], _CONST);\
        }

#define VFUNC2ARG(_OP) \
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

#endif
//mul
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vz_reference_mulbyconj(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
        int i;
        double complex * out0ref;
        const double complex * arg0ref, * arg1ref;
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        arg1ref = &arg1[*offsetarg1];
        for(i=0;i<*count;i++)
        {
                out0ref[i]=arg0ref[i]*conj(arg1ref[i]);
        }
}

//cdfnorm
#include<math.h>
#include "izyreference.h"
#include "izymathsmacros.h"
#define _SQRT2L 1.4142135623730950488016887242096981L
void vd_reference_cdfnorm(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
        int i;
        double * out0ref, * arg0ref;
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        for(i=0;i<count;i++)
        {
                out0ref[i]= 0.5e0*(1.e0+erf(arg0ref[i]/_SQRT2L));
        }
        
};
#undef _SQRT2L
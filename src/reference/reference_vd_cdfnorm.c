//cdfnorm
#include <math.h>
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vd_reference_cdfnorm(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
        int i;
        double * out0ref, * arg0ref;
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        for(i=0;i<*count;i++)
        {
                out0ref[i]= 0.5e0*(1.e0+erf(arg0ref[i]/M_SQRT2));
        }
        
};

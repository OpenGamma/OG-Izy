//sqr
#include<math.h>
#include "izyreference.h"
#include "izymathsmacros.h"
void vd_reference_sqr(double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, const int * count)
{
        int i;
        double * out0ref, * arg0ref;
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        for(i=0;i<*count;i++)
        {
                out0ref[i]= arg0ref[i] * arg0ref[i];
        }
};

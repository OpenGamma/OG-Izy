/* addx */
#include "izyreference.h"
#include "izymathsmacros.h"
void vd_reference_addx(double * arg0, const int * offsetarg0, const double * arg1, const int * offsetarg1, double * out0, const int * offsetout0, const int * count)
{
        int i;
        double * out0ref, * arg0ref;
        double const * arg1ref;
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        arg1ref = &arg1[*offsetarg1];
        for(i=0;i<*count;i++)
        {
                out0ref[i]=arg0ref[i] + *arg1ref;
        }
};

//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

//log10
#include <math.h>
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vz_reference_log10(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
// doesn't exist at present, use a messy work around
//         ZVFUNC(clog10)
        int i;
        double complex * out0ref;
        const double complex * arg0ref;
        const double log10 = log(10.);
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        for(i=0;i<*count;i++)
        {
                out0ref[i]= clog(arg0ref[i])/log10;
        }

}

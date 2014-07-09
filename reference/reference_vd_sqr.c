//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

//sqr
#include <math.h>
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vd_reference_sqr(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0)
{
        int i;
        double * out0ref;
        const double * arg0ref;
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        for(i=0;i<*count;i++)
        {
                out0ref[i]= arg0ref[i] * arg0ref[i];
        }
}

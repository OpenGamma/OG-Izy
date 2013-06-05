//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

//negate real part
#include <math.h>
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vz_reference_negatereal(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
        int i; 
        double complex * out0ref;
        const double complex * arg0ref;
        out0ref = &out0[*offsetout0];
        arg0ref = &arg0[*offsetarg0];
        for(i=0;i<*count;i++)
        {
                out0ref[i] = -creal(arg0ref[i]) + I * cimag(arg0ref[i]);
        }
};

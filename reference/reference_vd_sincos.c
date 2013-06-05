//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

//sincos
#include <math.h>
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vd_reference_sincos(const int * count, const double * arg0, const int * offsetarg0, double * out0, const int * offsetout0, double * out1, const int * offsetout1)
{
        int i;
        double * out0ref, * out1ref;
        const double * arg0ref;
        out0ref = &out0[*offsetout0];
        out1ref = &out1[*offsetout1];
        arg0ref = &arg0[*offsetarg0];
        for(i=0;i<*count;i++)\
        {
#ifdef HAVE_MKL
                sincos(arg0ref[i], &out0ref[i], &out1ref[i]);
#else
                out0ref[i] = sin(arg0ref[i]);
                out1ref[i] = cos(arg0ref[i]);                
#endif
        }
};

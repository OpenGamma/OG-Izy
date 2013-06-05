//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

//cosh
#include <math.h>
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vz_reference_cosh(const int * count, const double complex * arg0, const int * offsetarg0, double complex * out0, const int * offsetout0)
{
        ZVFUNC(ccosh)
};

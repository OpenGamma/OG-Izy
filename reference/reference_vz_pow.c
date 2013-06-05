//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

//pow
#include <math.h>
#include "libizy/izyreference.h"
#include "libizy/izymathsmacros.h"
void vz_reference_pow(const int * count, const double complex * arg0, const int * offsetarg0, const double complex * arg1, const int * offsetarg1, double complex * out0, const int * offsetout0)
{
        ZVFUNC2ARG(cpow)
};

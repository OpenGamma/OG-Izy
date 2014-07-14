//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

#ifdef HAVE_CONFIG
#include "libizy/config.h"
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "libizy/izy.h"
#include "izymakecheck.h"


int main()
{
#include "vd_sincos_c.inc"
  int i;
  double results_data0[n_expected];
  double results_data1[n_expected];

  const int offsetin0 = 0;
  const int offsetout0 = 0;
  const int offsetout1 = 0;
  const int count = n_in;

  /* make izy call */
  vd_sincos(&count,in_data,&offsetin0,results_data0,&offsetout0,results_data1,&offsetout1);

  /* check */
  for(i=0; i<n_expected; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data0[i], results_data0[i], IZY_MAX_ULPS, _STANDARD_LOOP_INCORRECT_RESULT)
      TEST_DOUBLE_EQUALS_FULL(i, expected_data1[i], results_data1[i], IZY_MAX_ULPS, _STANDARD_LOOP_INCORRECT_RESULT)
    }

  /* stage offset call */
  const int offsetin_used0 = (int)(0.2*count);
  const int offsetout_used0 = (int)(0.4*count);
  const int offsetout_used1 = (int)(0.4*count);
  const int count_used = count - offsetout_used0;
  memset(results_data0,0x0,count*sizeof(double));

  /* make izy call */
  vd_sincos(&count_used,in_data,&offsetin_used0,results_data0,&offsetout_used0,results_data1,&offsetout_used1);

  /* check */
  for(i=0; i < count_used; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data0[i+offsetin_used0], results_data0[i+offsetout_used0], IZY_MAX_ULPS, _OFFSET_LOOP_INCORRECT_RESULT)
      TEST_DOUBLE_EQUALS_FULL(i, expected_data1[i+offsetin_used0], results_data1[i+offsetout_used1], IZY_MAX_ULPS, _OFFSET_LOOP_INCORRECT_RESULT)
    }

  /* stage calls to saturation */
  double IVAL =  0.e0;
  double RVAL0 =  0.e0;
  double RVAL1 =  0.e0;
  const int one = 1;

  /* test NaN arg0 */
  IVAL = NAN;
  vd_sincos(&one,&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL0, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL1, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  /* test +INF */
  IVAL = INFINITY;
  vd_sincos(&one,&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL0, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL1, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  /* test -INF */
  IVAL = -INFINITY;
  vd_sincos(&one,&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL0, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL1, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)
  return 0;
}



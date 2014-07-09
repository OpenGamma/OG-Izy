//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

#ifdef HAVE_CONFIG
#include "libizy/config.h"
#endif
#define  _XOPEN_SOURCE 600
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "libizy/izy.h"
#include "izymakecheck.h"


int main()
{
#include "vd_asin_c.inc"
  int i;
  double results_data[n_expected];
  const int offsetin0 = 0;
  const int offsetout0 = 0;
  const int count = n_in;

  /* make izy call */
  vd_asin(&count,in_data,&offsetin0,results_data,&offsetout0);

  /* check */
  for(i=0; i<n_expected; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data[i], results_data[i], IZY_MAX_ULPS, _STANDARD_LOOP_INCORRECT_RESULT)
    }

  /* stage offset call */
  const int offsetin_used0 = (int)(0.2*count);
  const int offsetout_used0 = (int)(0.4*count);;
  const int count_used = count - offsetout_used0;
  memset(results_data,0x0,count*sizeof(double));

  /* make izy call */
  vd_asin(&count_used,in_data,&offsetin_used0,results_data,&offsetout_used0);

  /* check */
  for(i=0; i < count_used; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data[i+offsetin_used0], results_data[i+offsetout_used0], IZY_MAX_ULPS, _OFFSET_LOOP_INCORRECT_RESULT)
    }

  /* stage calls to saturation */
  double IVAL =  0.e0;
  double RVAL =  0.e0;
  const int one = 1;

  /* test NaN */
  IVAL = NAN;
  vd_asin(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  /* test +INF */
  IVAL = INFINITY;
  vd_asin(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  /* test -INF */
  IVAL = -INFINITY;
  vd_asin(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  /* stage calls to out of bounds */
  IVAL = 2;
  vd_asin(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  IVAL = -2;
  vd_asin(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  /* stage calls at poles, should ret 0 */
  IVAL = 1;
  vd_asin(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(M_PI_2, RVAL, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)

  IVAL = -1;
  vd_asin(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(-M_PI_2, RVAL, IZY_MAX_ULPS, _EXTREMITY_INCORRECT_RESULT)




  return 0;
}
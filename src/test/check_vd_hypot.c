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

// hypot has large range
#ifdef IZY_DBL_EPSILON
#undef IZY_DBL_EPSILON
#define IZY_DBL_EPSILON  (100 * DBL_EPSILON)
#endif

int main()
{
#include "vd_hypot_c.inc"
  int i;
  double results_data[n_expected];
  const int offsetin0 = 0;
  const int offsetin1 = 0;
  const int offsetout0 = 0;
  const int count = n_in;
  memset(results_data,0x0,count*sizeof(double));

  /* make izy call */
  vd_hypot(&count,in_data0,&offsetin0,in_data1,&offsetin1,results_data,&offsetout0);

  /* check */
  for(i=0; i<n_expected; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data[i], results_data[i], IZY_DBL_EPSILON, _STANDARD_LOOP_INCORRECT_RESULT)
    }

  /* stage offset call */
  const int offsetin_used0 = (int)0.2*count;
  const int offsetin_used1 = (int)0.2*count;
  const int offsetout_used0 = (int)0.4*count;
  const int count_used = count - offsetout_used0;

  /* make izy call */
  vd_hypot(&count_used,in_data0,&offsetin_used0,in_data1,&offsetin_used1,results_data,&offsetout_used0);

  /* check */
  for(i=offsetout_used0; i < offsetout_used0+count_used; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data[i], results_data[i], IZY_DBL_EPSILON, _OFFSET_LOOP_INCORRECT_RESULT)
    }

  /* stage calls to saturation */
  double IVAL0 =  0.e0;
  double IVAL1 =  0.e0;
  double RVAL =  0.e0;
  const int one = 1;

  /* test NaN arg0 */
  IVAL0 = NAN;
  IVAL1 =  0.e0;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = NAN;
  IVAL1 = INFINITY;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = NAN;
  IVAL1 = -INFINITY;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = NAN;
  IVAL1 = NAN;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  /* test +INF */
  IVAL0 = INFINITY;
  IVAL1 =  0.e0;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = INFINITY;
  IVAL1 = INFINITY;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = INFINITY;
  IVAL1 = -INFINITY;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = INFINITY;
  IVAL1 = NAN;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  /* test -INF */
  IVAL0 = -INFINITY;
  IVAL1 =  0.e0;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = -INFINITY;
  IVAL1 = INFINITY;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = -INFINITY;
  IVAL1 = -INFINITY;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  IVAL0 = -INFINITY;
  IVAL1 = NAN;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  /* overflow */
  IVAL0 = 1.e308;
  IVAL1 = 2.e308;
  vd_hypot(&one,&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0);
  if(!isinf(RVAL))
    {
      return _INCORRECTRESULT;
    }



  return 0;
}



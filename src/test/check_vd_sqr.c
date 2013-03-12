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
#include "vd_sqr_c.inc"
  int i;
  double results_data[n_expected];
  const int offsetin0 = 0;
  const int offsetin1 = 0;
  const int offsetout0 = 0;
  const int count = n_in;
  memset(results_data,0x0,count*sizeof(double));

  /* make izy call */
  vd_sqr(&count,in_data,&offsetin0,results_data,&offsetout0);

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
  vd_sqr(&count_used,in_data,&offsetin_used0,results_data,&offsetout_used0);

  /* check */
  for(i=offsetout_used0; i < offsetout_used0+count_used; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data[i], results_data[i], IZY_DBL_EPSILON, _OFFSET_LOOP_INCORRECT_RESULT)
    }

  /* stage calls to saturation */
  double IVAL =  0.e0;
  double RVAL =  0.e0;
  const int one = 1;

  /* test NaN */
  IVAL = NAN;
  vd_sqr(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  /* test +INF */
  IVAL = INFINITY;
  vd_sqr(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  /* test -INF */
  IVAL = -INFINITY;
  vd_sqr(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)



  return 0;
}



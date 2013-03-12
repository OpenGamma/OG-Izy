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
#include "vd_invcbrt_c.inc"
  int i;
  double results_data[n_expected];
  const int offsetin0 = 0;
  const int offsetout0 = 0;
  const int count = n_in;

  /* make izy call */
  vd_invcbrt(&count,in_data,&offsetin0,results_data,&offsetout0);

  /* check */
  for(i=0; i<n_expected; i++)
    {
      TEST_DOUBLE_EQUALS_FULL(i, expected_data[i], results_data[i], IZY_DBL_EPSILON, _STANDARD_LOOP_INCORRECT_RESULT)
    }

  /* stage offset call */
  const int offsetin_used0 = (int)0.2*offsetin0;
  const int offsetout_used0 = (int)0.4*offsetin0;;
  const int count_used = count - offsetout_used0;
  memset(results_data,0x0,count*sizeof(double));

  /* make izy call */
  vd_invcbrt(&count_used,in_data,&offsetin_used0,results_data,&offsetout_used0);

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
  vd_invcbrt(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(NAN, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  /* test +INF */
  IVAL = INFINITY;
  vd_invcbrt(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  if(!(RVAL==0.e0&&!signbit(RVAL)))
    {
      return _INCORRECTRESULT;
    }

  /* test -INF */
  IVAL = -INFINITY;
  vd_invcbrt(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  if(!(RVAL==0.e0&&signbit(RVAL)))
    {
      return _INCORRECTRESULT;
    }

  /* test +0 */
  IVAL = 0.e0;
  vd_invcbrt(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(+INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)

  /* test -0 */
  IVAL = -0.e0;
  vd_invcbrt(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  TEST_DOUBLE_EQUALS_ERROR_CODE(-INFINITY, RVAL, IZY_DBL_EPSILON, _EXTREMITY_INCORRECT_RESULT)





  return 0;
}
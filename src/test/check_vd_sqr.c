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
  double * results_data = NULL;
  results_data = (double * ) malloc(n_expected*sizeof(double));
  if(!results_data)
    {
      return _MALLOCERROR;
    }

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
      if(fabs(results_data[i]-expected_data[i])>=IZY_DBL_EPSILON)
        {
          return _INCORRECTRESULT;
        }

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
      if(fabs(results_data[i]-expected_data[i])>=IZY_DBL_EPSILON)
        {
          return _INCORRECTRESULT;
        }

    }

  /* stage calls to saturation */
  double IVAL =  0.e0;
  double RVAL =  0.e0;
  const int one = 1;

  /* test NaN */
  IVAL = NAN;
  vd_sqr(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  if(!isnan(RVAL))
    {
      return _INCORRECTRESULT;
    }

  /* test +INF */
  IVAL = INFINITY;
  vd_sqr(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  if(!(isinf(RVAL)&&!signbit(RVAL)))
    {
      return _INCORRECTRESULT;
    }

  /* test -INF */
  IVAL = -INFINITY;
  vd_sqr(&one,&IVAL,&offsetin0,&RVAL,&offsetout0);
  if(!(isinf(RVAL)&&!signbit(RVAL)))
    {
      return _INCORRECTRESULT;
    }


  free(results_data);
  return 0;
}



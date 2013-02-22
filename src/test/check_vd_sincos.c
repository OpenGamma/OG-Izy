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
  double * results_data0 = NULL, * results_data1 = NULL;
  results_data0 = (double * ) malloc((n_expected)*sizeof(double));
  if(!results_data0)
    {
      return _MALLOCERROR;
    }

  results_data1 = (double * ) malloc((n_expected)*sizeof(double));
  if(!results_data1)
    {
      return _MALLOCERROR;
    }

  const int offsetin0 = 0;
  const int offsetout0 = 0;
  const int offsetout1 = 0;
  const int count = n_in;

  /* make izy call */
  vd_sincos(&count,in_data,&offsetin0,results_data0,&offsetout0,results_data1,&offsetout1);

  /* check */
  for(i=0; i<n_expected; i++)
    {
      if(fabs(results_data0[i]-expected_data0[i])>=IZY_DBL_EPSILON)
        {
          return _INCORRECTRESULT;
        }
      if(fabs(results_data1[i]-expected_data1[i])>=IZY_DBL_EPSILON)
        {
          return _INCORRECTRESULT;
        }
    }

  /* /*stage offset call */
  const int offsetin_used0 = (int)0.2*count;
  const int offsetout_used0 = (int)0.4*count;
  const int offsetout_used1 = (int)0.4*count;
  const int count_used = count - offsetout_used0;
  memset(results_data0,0x0,count*sizeof(double));
  memset(results_data1,0x0,count*sizeof(double));

  /* make izy call */
  vd_sincos(&count,in_data,&offsetin_used0,results_data0,&offsetout_used0,results_data1,&offsetout_used1);

  /* check */
  for(i=offsetout_used0; i < offsetout_used0+count_used; i++)
    {
      if(fabs(results_data0[i]-expected_data0[i])>=IZY_DBL_EPSILON)
        {
          return _INCORRECTRESULT;
        }
      if(fabs(results_data1[i]-expected_data1[i])>=IZY_DBL_EPSILON)
        {
          return _INCORRECTRESULT;
        }
    }

  /* stage calls to saturation */
  double IVAL =  0.e0;
  double RVAL0 =  0.e0;
  double RVAL1 =  0.e0;
  const int one = 1;

  /* test NaN arg0 */
  IVAL = NAN;
  vd_sincos(&one,&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1);
  if(!isnan(RVAL0)||!isnan(RVAL1))
    {
      return _INCORRECTRESULT;
    }

  /* test +INF */
  IVAL = INFINITY;
  vd_sincos(&one,&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1);
  if(!isnan(RVAL0)||!isnan(RVAL1))
    {
      return _INCORRECTRESULT;
    }

  /* test -INF */
  IVAL = -INFINITY;
  vd_sincos(&one,&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1);
  if(!isnan(RVAL0)||!isnan(RVAL1))
    {
      return _INCORRECTRESULT;
    }

  free(results_data0);
  free(results_data1);
  return 0;
}



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
        const char * countfilename = "count_sqr.txt";
        const char * inputfilename = "input_sqr.txt";        
        const char * expectedfilename = "expected_sqr.txt";        
        FILE * input = NULL;
        int i, ret;
               
        input = fopen(countfilename,"r");
        if(!input)
        {
                return _IOERROR;
        }
        int n_in = -1;
        int n_expected = -1;        
        ret=fscanf(input, "%d", &n_in);
        if(!ret)
        {
                return _READERROR;
        }
        ret=fscanf(input, "%d", &n_expected);        
        if(!ret)
        {
                return _READERROR;
        }
        fclose(input);
        
        if(n_in<1||n_expected<1)
        {
                return _BADCOUNT;
        }
        
        /* Get input data */
        input = NULL;
        input = fopen(inputfilename,"r");
        if(!input)
        {
                return _IOERROR;
        }
        double * in_data0 = NULL;
        in_data0 = (double * ) malloc((n_in>>1)*sizeof(double));
        if(!in_data0)
        {       
                return _MALLOCERROR;
        }

        /* annoyingly @pow() has 2 args so we have 2x as much data as needed so we bin it */
        double bin;
        for(i=0; i<n_in>>1;i++)
        {
                ret=fscanf(input,"%lf",&in_data0[i]);
                if(!ret)
                {
                        return _READERROR;
                }
                ret=fscanf(input,"%lf",&bin);
                if(!ret)
                {
                        return _READERROR;
                }                
        }
        fclose(input);
        
        
        /* Get results data */
        input = NULL;
        input = fopen(expectedfilename,"r");
        if(!input)
        {
                return _IOERROR;
        }
        double * expected_data = NULL;
        expected_data = (double * ) malloc(n_expected*sizeof(double));
        if(!expected_data)
        {       
                return _MALLOCERROR;
        }
        for(i=0; i<n_expected;i++)
        {
                ret=fscanf(input,"%lf",&expected_data[i]);
                if(!ret)
                {
                        return _READERROR;
                }
        }
        
        fclose(input);

        /* stage izy call */
        double * results_data = NULL;
        results_data = (double * ) malloc(n_expected*sizeof(double));
        if(!results_data)
        {       
                return _MALLOCERROR;
        }
        
        const int offsetin0 = 0;
        const int offsetin1 = 0;        
        const int offsetout0 = 0;
        const int count = n_in>>1;
        memset(results_data,0x0,count*sizeof(double));        
        
        /* make izy call */
        vd_sqr(&count,in_data0,&offsetin0,results_data,&offsetout0);
        
        /* check */
        for(i=0; i<n_expected;i++)
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
        vd_sqr(&count_used,in_data0,&offsetin_used0,results_data,&offsetout_used0);

        /* check */
        for(i=offsetout_used0; i < offsetout_used0+count_used;i++)
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
        
        free(in_data0);
        free(expected_data);        
        free(results_data);
        return 0;
}



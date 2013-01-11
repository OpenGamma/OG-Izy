#ifdef HAVE_CONFIG
#include "config.h"
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "izy.h"
#include "izymakecheck.h"


int main()
{       
        const char * countfilename = "count_sincos.txt";
        const char * inputfilename = "input_sincos.txt";        
        const char * expectedfilename = "expected_sincos.txt";        
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
        double * in_data = NULL;
        in_data = (double * ) malloc(n_in*sizeof(double));
        if(!in_data)
        {       
                return _MALLOCERROR;
        }
        for(i=0; i<n_in;i++)
        {
                ret=fscanf(input,"%lf",&in_data[i]);
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
        double * expected_data0 = NULL, * expected_data1 = NULL;
        expected_data0 = (double * ) malloc((n_expected>>1)*sizeof(double));
        expected_data1 = (double * ) malloc((n_expected>>1)*sizeof(double));        
        if(!expected_data0)
        {       
                return _MALLOCERROR;
        }
        if(!expected_data1)
        {       
                return _MALLOCERROR;
        }       
        for(i=0; i<n_expected>>1;i++)
        {
                ret=fscanf(input,"%lf",&expected_data0[i]);
                if(!ret)
                {
                        return _READERROR;
                }
                ret=fscanf(input,"%lf",&expected_data1[i]);                                
                if(!ret)
                {
                        return _READERROR;
                }                
        }
        fclose(input);


        /* stage izy call */
        double * results_data0 = NULL, * results_data1 = NULL;
        results_data0 = (double * ) malloc((n_expected>>1)*sizeof(double));
        if(!results_data0)
        {       
                return _MALLOCERROR;
        }

        results_data1 = (double * ) malloc((n_expected>>1)*sizeof(double));
        if(!results_data1)
        {       
                return _MALLOCERROR;
        }
        
        const int offsetin0 = 0;
        const int offsetout0 = 0;
        const int offsetout1 = 0;        
        const int count = n_in;
        
        /* make izy call */
        vd_sincos(in_data,&offsetin0,results_data0,&offsetout0,results_data1,&offsetout1,&count);
        
        /* check */
        for(i=0; i<n_expected>>1;i++)
        {
                if(abs(results_data0[i]-expected_data0[i])>=DBL_EPSILON)
                {
                        return _INCORRECTRESULT;
                }
                if(abs(results_data1[i]-expected_data1[i])>=DBL_EPSILON)
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
        vd_sincos(in_data,&offsetin_used0,results_data0,&offsetout_used0,results_data1,&offsetout_used1,&count);

        /* check */
        for(i=offsetout_used0; i < offsetout_used0+count_used;i++)
        {
                if(abs(results_data0[i]-expected_data0[i])>=DBL_EPSILON)
                {
                        return _INCORRECTRESULT;
                }
                if(abs(results_data1[i]-expected_data1[i])>=DBL_EPSILON)
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
        vd_sincos(&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1,&one);
        if(!isnan(RVAL0)||!isnan(RVAL1))
        {
                return _INCORRECTRESULT;
        }
        
        /* test +INF */
        IVAL = INFINITY;
        vd_sincos(&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1,&one);
        if(!isnan(RVAL0)||!isnan(RVAL1))
        {
               return _INCORRECTRESULT;
        }

        /* test -INF */
        IVAL = -INFINITY;        
        vd_sincos(&IVAL,&offsetin0,&RVAL0,&offsetout0,&RVAL1,&offsetout1,&one);
        if(!isnan(RVAL0)||!isnan(RVAL1))
        {
               return _INCORRECTRESULT;
        }
        
        free(in_data);
        free(expected_data0);
        free(expected_data1);                
        free(results_data0);
        free(results_data1);        
        return 0;
}



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
        const char * countfilename = "count_atan2.txt";
        const char * inputfilename = "input_atan2.txt";        
        const char * expectedfilename = "expected_atan2.txt";        
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
        double * in_data0 = NULL, * in_data1 = NULL;
        in_data0 = (double * ) malloc((n_in>>1)*sizeof(double));
        in_data1 = (double * ) malloc((n_in>>1)*sizeof(double));        
        if(!in_data0)
        {       
                return _MALLOCERROR;
        }
        if(!in_data1)
        {       
                return _MALLOCERROR;
        }       
        for(i=0; i<n_in>>1;i++)
        {
                ret=fscanf(input,"%lf",&in_data0[i]);
                if(!ret)
                {
                        return _READERROR;
                }
                ret=fscanf(input,"%lf",&in_data1[i]);                                
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
        vd_atan2(in_data0,&offsetin0,in_data1,&offsetin1,results_data,&offsetout0,&count);
        
        /* check */
        for(i=0; i<n_expected;i++)
        {
                if(abs(results_data[i]-expected_data[i])>=DBL_EPSILON)
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
        vd_atan2(in_data0,&offsetin_used0,in_data1,&offsetin_used1,results_data,&offsetout_used0,&count_used);

        /* check */
        for(i=offsetout_used0; i < offsetout_used0+count_used;i++)
        {
                if(abs(results_data[i]-expected_data[i])>=DBL_EPSILON)
                {
                        return _INCORRECTRESULT;
                }
                        
        }

        /* stage calls to saturation */
        double IVAL0 =  0.e0;
        double IVAL1 =  0.e0;        
        double RVAL =  0.e0;
        const int one = 1;
               
        /* test NaN arg0 */
        IVAL0 = NAN;
        IVAL1 =  0.e0;                
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
                return _INCORRECTRESULT;
        }
        
        IVAL0 = NAN;
        IVAL1 = INFINITY;         
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
                return _INCORRECTRESULT;
        }
       
        IVAL0 = NAN;
        IVAL1 = -INFINITY;        
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
                return _INCORRECTRESULT;
        }
        
        IVAL0 = NAN;
        IVAL1 = NAN;        
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
                return _INCORRECTRESULT;
        }        
              
        /* test +INF */
        IVAL0 = INFINITY;
        IVAL1 =  0.e0;        
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(abs(RVAL-M_PI_2)>=DBL_EPSILON)
        {
               return _INCORRECTRESULT;
        }

        IVAL0 = INFINITY;
        IVAL1 = INFINITY;        
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(abs(RVAL-M_PI_4)>=DBL_EPSILON)
        {
               return _INCORRECTRESULT;
        }        
        
        IVAL0 = INFINITY;
        IVAL1 = -INFINITY;        
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(abs(RVAL-3*M_PI_4)>=DBL_EPSILON)
        {
               return _INCORRECTRESULT;
        }        
        
        IVAL0 = INFINITY;
        IVAL1 = NAN;        
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
               return _INCORRECTRESULT;
        }               
        
        /* test -INF */
        IVAL0 = -INFINITY;        
        IVAL1 =  0.e0;
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(abs(RVAL+M_PI_2)>=DBL_EPSILON)
        {
               return _INCORRECTRESULT;
        }
        
        IVAL0 = -INFINITY;        
        IVAL1 = INFINITY;
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(abs(RVAL+M_PI_4)>=DBL_EPSILON)
        {
               return _INCORRECTRESULT;
        }
        
        IVAL0 = -INFINITY;        
        IVAL1 = -INFINITY;
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(abs(RVAL+3*M_PI_4)>=DBL_EPSILON)
        {
               return _INCORRECTRESULT;
        }        
        
        IVAL0 = -INFINITY;        
        IVAL1 = NAN;
        vd_atan2(&IVAL0,&offsetin0,&IVAL1,&offsetin1,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
               return _INCORRECTRESULT;
        }                
        
        free(in_data0);
        free(in_data1);        
        free(expected_data);        
        free(results_data);
        return 0;
}



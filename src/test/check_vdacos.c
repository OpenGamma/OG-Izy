#ifdef HAVE_CONFIG
#include "config.h"
#endif
#include <stdio.h>=
#include <stdlib.h>=
#include <math.h>=
#include <float.h>=
#include "izy.h"
#include "izymakecheck.h"


int main()
{       
        const char * countfilename = "count_acos.txt";
        const char * inputfilename = "input_acos.txt";        
        const char * expectedfilename = "expected_acos.txt";        
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
        const int offsetout0 = 0;
        const int count = n_in;
        
        /* make izy call */
        vd_acos(in_data,&offsetin0,results_data,&offsetout0,&count);

        /* check */
        for(i=0; i<n_expected;i++)
        {
                if(abs(results_data[i]-expected_data[i])>=DBL_EPSILON)
                {
                        return _INCORRECTRESULT;
                }
                        
        }
        
        /* stage offset call */
        const int offsetin_used0 = (int)0.2*offsetin0;
        const int offsetout_used0 = (int)0.4*offsetin0;;
        const int count_used = count - offsetout_used0;
        
        /* make izy call */       
        vd_acos(in_data,&offsetin_used0,results_data,&offsetout_used0,&count_used);

        /* check */
        for(i=offsetout_used0; i < offsetout_used0+count_used;i++)
        {
                if(abs(results_data[i]-expected_data[i])>=DBL_EPSILON)
                {
                        return _INCORRECTRESULT;
                }
                        
        }

        /* stage calls to saturation */
        double IVAL = 0;
        double RVAL = 0;
        const int one = 1;
        
        /* test NaN */
        IVAL = NAN;
        vd_acos(&IVAL,&offsetin0,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
                return _INCORRECTRESULT;
        }
        
        /* test +INF */
        IVAL = INFINITY;
        vd_acos(&IVAL,&offsetin0,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
               return _INCORRECTRESULT;
        }

        /* test -INF */
        IVAL = -INFINITY;        
        vd_acos(&IVAL,&offsetin0,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
               return _INCORRECTRESULT;
        }
        
        /* stage calls to out of bounds */        
        IVAL = 2;        
        vd_acos(&IVAL,&offsetin0,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
               return _INCORRECTRESULT;
        }
        
        IVAL = -2;
        vd_acos(&IVAL,&offsetin0,&RVAL,&offsetout0,&one);
        if(!isnan(RVAL))
        {
               return _INCORRECTRESULT;
        }
        
        /* stage calls at poles, should ret 0 */
        IVAL = 1;        
        vd_acos(&IVAL,&offsetin0,&RVAL,&offsetout0,&one);
        if(abs(RVAL)>=DBL_EPSILON)
        {
               return _INCORRECTRESULT;
        }
        
        IVAL = -1;
        vd_acos(&IVAL,&offsetin0,&RVAL,&offsetout0,&one);
        if((abs(RVAL)-M_PI)>=DBL_EPSILON)
        {               
               return _INCORRECTRESULT;
        }        
        
        free(in_data);
        free(expected_data);        
        free(results_data);
        return 0;
}
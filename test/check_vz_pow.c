//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

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
#define SMALL 1e-15

int main()
{
#include "vz_pow_c.inc"
    int i;
    complex double results_data[n_expected];
    const int offsetin0 = 0;
    const int offsetin1 = 0;
    const int offsetout0 = 0;
    const int count = n_in;
    memset(results_data,0x0,count*sizeof(complex double));

    /* make izy call */
    vz_pow(&count,in_data0,&offsetin0,in_data1,&offsetin1,results_data,&offsetout0);

    /* check */
    for(i=0; i<n_expected; i++)
    {
        if(fpclassify(creal(expected_data[i]))==FP_ZERO||fpclassify(cimag(expected_data[i]))==FP_ZERO)
        {
            if(fpclassify(creal(expected_data[i]))==FP_ZERO)
            {
                if(fabs(creal(results_data[i]))>SMALL) {
                    {
                  printf("vz_pow: special error message, real branch, fpclass=FP_ZERO: Expected cmplx(%18.16f, %18.16f), GOT cmplx(%18.16f, %18.16f), tol = %18.16f\n",creal(expected_data[i]),cimag(expected_data[i]),creal(results_data[i]),cimag(results_data[i]),SMALL);
                      __PRINT_ERROR(_STANDARD_LOOP_INCORRECT_RESULT, i)
                        return _STANDARD_LOOP_INCORRECT_RESULT;
                    }
                }
            }else{
                printf("vz_pow: testing::cmplx(%18.16f, %18.16f).^cmplx(%18.16f, %18.16f)\n", creal(in_data0[i]),cimag(in_data0[i]),creal(in_data1[i]),cimag(in_data1[i]));
                TEST_DOUBLE_EQUALS_FULL(i, creal(expected_data[i]), creal(results_data[i]), IZY_MAX_ULPS, _STANDARD_LOOP_INCORRECT_RESULT)
            }
            if(fpclassify(cimag(expected_data[i]))==FP_ZERO)
            {
                if(fabs(cimag(results_data[i]))>SMALL)
                {
                  printf("vz_pow: special error message, imag branch, fpclass=FP_ZERO: Expected cmplx(%18.16f, %18.16f), GOT cmplx(%18.16f, %18.16f), tol = %18.16f\n",creal(expected_data[i]),cimag(expected_data[i]),creal(results_data[i]),cimag(results_data[i]),SMALL);
                    __PRINT_ERROR(_STANDARD_LOOP_INCORRECT_RESULT, i)
                    return _STANDARD_LOOP_INCORRECT_RESULT;
                }
            }else{
                printf("vz_pow: testing::cmplx(%18.16f, %18.16f).^cmplx(%18.16f, %18.16f)\n", creal(in_data0[i]),cimag(in_data0[i]),creal(in_data1[i]),cimag(in_data1[i]));
                  TEST_DOUBLE_EQUALS_FULL(i, cimag(expected_data[i]), cimag(results_data[i]), IZY_MAX_ULPS, _STANDARD_LOOP_INCORRECT_RESULT)
            }
        }
        else
        {
            TEST_COMPLEX_DOUBLE_EQUALS_FULL(i, expected_data[i], results_data[i], IZY_MAX_ULPS, _STANDARD_LOOP_INCORRECT_RESULT)
        }
    }

    /* stage offset call */
    const int offsetin_used0 = (int)(0.2*count);
    const int offsetin_used1 = (int)(0.2*count);
    const int offsetout_used0 = (int)(0.4*count);
    const int count_used = count - offsetout_used0;
    memset(results_data,0x0,count*sizeof(complex double));

    /* make izy call */
    vz_pow(&count_used,in_data0,&offsetin_used0,in_data1,&offsetin_used1,results_data,&offsetout_used0);

    /* check */
    for(i=0; i < count_used; i++)
    {
        TEST_COMPLEX_DOUBLE_EQUALS_FULL(i, expected_data[i+offsetin_used0], results_data[i+offsetout_used0], IZY_MAX_ULPS, _OFFSET_LOOP_INCORRECT_RESULT)
    }

    return 0;
}



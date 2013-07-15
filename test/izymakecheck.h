//
// Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
//
// Please see distribution for license.
//

#ifndef IZYMAKECHECK_H
#define IZYMAKECHECK_H
#define _IOERROR 0x02
#define _READERROR 0x03
#define _MALLOCERROR 0x04
#define _BADCOUNT 0x05
#define _INCORRECTRESULT 0x06
#define _STANDARD_LOOP_INCORRECT_RESULT 0x07
#define _OFFSET_LOOP_INCORRECT_RESULT 0x08
#define _EXTREMITY_INCORRECT_RESULT 0x09

#define IZY_MAX_ULPS 10

#define IZY_MIN_VAL 1e-15

#ifdef SLACK_TESTS
#define IZY_MAX_ULPS 100
#endif 

#ifndef SLACK_TESTS
#define SLACK_TESTS 0
#endif

#define DYN_TOL(EXPECTED, ULP_MUL) ((ULP_MUL*(nextafter(EXPECTED, EXPECTED+1.e0)-EXPECTED)) > IZY_MIN_VAL ? (ULP_MUL*(nextafter(EXPECTED, EXPECTED+1.e0)-EXPECTED)) : IZY_MIN_VAL)

#define __PRINT_ERROR(FAIL_CODE, LOOPC)\
          switch(FAIL_CODE)\
          {\
            case _STANDARD_LOOP_INCORRECT_RESULT:\
              printf("Location: Standard loop test, input number %d, line %d\n", LOOPC, __LINE__);\
              break;\
            case _OFFSET_LOOP_INCORRECT_RESULT:\
              printf("Location: Offset loop test, input number %d, line %d\n", LOOPC, __LINE__);\
              break;\
            case _EXTREMITY_INCORRECT_RESULT:\
              printf("Location: Extreme value testing, line %d\n",__LINE__);\
              break;\
            case _INCORRECTRESULT:\
              printf("Location: Unknown, old style _INCORRECTRESULT define used, line %d\n", __LINE__);\
              break;\
            default:\
              printf("ERROR UNKNOWN: (this is a serious problem, all errors should be identified!)\n");\
          }\
 
#define TEST_DOUBLE_EQUALS_SIMPLE(EXPECTED, GOT, ULP_MUL) TEST_DOUBLE_EQUALS_FULL(-1, EXPECTED, GOT, ULP_MUL, _INCORRECTRESULT)

#define TEST_DOUBLE_EQUALS_ERROR_CODE(EXPECTED, GOT, ULP_MUL, FAIL_CODE) TEST_DOUBLE_EQUALS_FULL(-1, EXPECTED, GOT, ULP_MUL, FAIL_CODE)

#define TEST_DOUBLE_EQUALS_FULL(LOOPC, EXPECTED, GOT, ULP_MUL, FAIL_CODE)\
      switch(fpclassify(EXPECTED))\
      {\
        case FP_NAN:\
        if(!isnan(GOT)) \
            {\
              printf("Error: results mismatch in NaN\n");\
              printf("Expected: %24.16f . Got: %24.16f .\n", EXPECTED, GOT);\
              __PRINT_ERROR(FAIL_CODE, LOOPC)\
              return FAIL_CODE;\
            }\
        break;\
        case FP_INFINITE:\
          if(!isinf(GOT)||(isinf(EXPECTED)!=isinf(GOT))) { \
              printf("Error: results mismatch in infinity\n");\
              printf("Expected: %24.16f . Got: %24.16f .\n", EXPECTED, GOT);\
              if(signbit(EXPECTED)&!signbit(GOT)) printf("Sign bits differ\n");\
              __PRINT_ERROR(FAIL_CODE, LOOPC)\
              return FAIL_CODE;\
            }\
        break;\
        case FP_ZERO:\
          if(fpclassify(GOT)!=FP_ZERO)\
          {\
            printf("Error: results mismatch in zeros\n");\
            printf("Expected: %24.16f . Got: %24.16f. FP class: %d\n", EXPECTED, GOT, fpclassify(GOT)==FP_ZERO);\
          __PRINT_ERROR(FAIL_CODE, LOOPC)\
          return FAIL_CODE;\
          }\
          if(!SLACK_TESTS)\
          {\
              if(signbit(EXPECTED)>0&!(signbit(GOT)>0))\
              {\
                printf("Expected: %24.16f . Got: %24.16f. Signbits: %d %d. FP class: %d\n", EXPECTED, GOT, signbit(EXPECTED), signbit(GOT), fpclassify(GOT)==FP_ZERO);\
                union{double d; long long int i;} _dint;\
                  _dint.d=EXPECTED;\
                printf("Bits in EXPECTED 0x%llx\n",_dint.i);\
                  _dint.d=GOT;\
                printf("Bits in GOT 0x%llx\n",_dint.i);\
              __PRINT_ERROR(FAIL_CODE, LOOPC)\
              return FAIL_CODE;\
              }\
          }\
          break;\
        default:\
          if(isnan(GOT))\
          {\
             printf("Error: results mismatch in value due to NaN\n");\
             printf("Expected: %24.16f . Got: %24.16f .\n", EXPECTED, GOT);\
              __PRINT_ERROR(FAIL_CODE, LOOPC)\
              return FAIL_CODE;\
          }\
          else if(isinf(GOT))\
          {\
             printf("Error: results mismatch in value due to Inf\n");\
             printf("Expected: %24.16f . Got: %24.16f .\n", EXPECTED, GOT);\
              __PRINT_ERROR(FAIL_CODE, LOOPC)\
              return FAIL_CODE;\
          }\
          else\
          {\
            if(fabs(GOT-EXPECTED)>=DYN_TOL(EXPECTED,ULP_MUL)) {\
              printf("Error: results mismatch in value\n");\
              printf("Expected: %24.16f . Got: %24.16f .\n Magnitude of error: %24.16f.\n Compared using tolerance: %24.16f\n", EXPECTED, GOT, fabs(EXPECTED-GOT), DYN_TOL(EXPECTED,ULP_MUL));\
              __PRINT_ERROR(FAIL_CODE, LOOPC)\
              printf("Attempting sign invariant match:");\
              if(fabs((GOT<0?-GOT:GOT)-(EXPECTED<0?-EXPECTED:EXPECTED))>=DYN_TOL(EXPECTED,ULP_MUL)) {\
              return FAIL_CODE;\
             }else{\
              printf("Passed sign invariant match. Branch cut problem.");\
             }\
            }\
          }\
        break;\
      }


#define TEST_COMPLEX_DOUBLE_EQUALS_SIMPLE(EXPECTED, GOT, ULP_MUL) TEST_COMPLEX_DOUBLE_EQUALS_FULL(-1, EXPECTED, GOT, ULP_MUL, _INCORRECTRESULT)

#define TEST_COMPLEX_DOUBLE_EQUALS_ERROR_CODE(EXPECTED, GOT, ULP_MUL, FAIL_CODE) TEST_COMPLEX_DOUBLE_EQUALS_FULL(-1, EXPECTED, GOT, ULP_MUL, FAIL_CODE)

#define TEST_COMPLEX_DOUBLE_EQUALS_FULL(LOOPC, EXPECTED, GOT, ULP_MUL, FAIL_CODE)\
  TEST_DOUBLE_EQUALS_FULL(LOOPC, creal(EXPECTED), creal(GOT), ULP_MUL, FAIL_CODE)\
  TEST_DOUBLE_EQUALS_FULL(LOOPC, cimag(EXPECTED), cimag(GOT), ULP_MUL, FAIL_CODE)

#endif


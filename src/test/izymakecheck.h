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

#define IZY_DBL_EPSILON (10 * DBL_EPSILON)

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

#define TEST_DOUBLE_EQUALS_SIMPLE(EXPECTED, GOT, TOLERANCE) TEST_DOUBLE_EQUALS_FULL(-1, EXPECTED, GOT, TOLERANCE, _INCORRECTRESULT) 

#define TEST_DOUBLE_EQUALS_ERROR_CODE(EXPECTED, GOT, TOLERANCE, FAIL_CODE) TEST_DOUBLE_EQUALS_FULL(-1, EXPECTED, GOT, TOLERANCE, FAIL_CODE) 

#define TEST_DOUBLE_EQUALS_FULL(LOOPC, EXPECTED, GOT, TOLERANCE, FAIL_CODE)\
      if(isnan(EXPECTED)&&!isnan(GOT)) \
        {\
          printf("Error: results mismatch in NaN\n");\
          printf("Expected: %24.18f. Got: %24.18f.\n", EXPECTED, GOT);\
          __PRINT_ERROR(FAIL_CODE, LOOPC)\
          return FAIL_CODE;\
        }\
      if(isinf(EXPECTED)) \
        {\
          if(isinf(EXPECTED)!=isinf(GOT))\
          {\
          printf("Error: results mismatch in infinity\n");\
          printf("Expected: %24.18f. Got: %24.18f.\n", EXPECTED, GOT);\
          if(signbit(EXPECTED)&!signbit(GOT)) printf("Sign bits differ\n");\
          __PRINT_ERROR(FAIL_CODE, LOOPC)\
          return FAIL_CODE;\
          }\
        }\
      if(EXPECTED==0.e0) {\
          if((GOT!=0.e0)||(signbit(EXPECTED)&!signbit(GOT)))\
          {\
          printf("Error: results mismatch in zeros\n");\
          printf("Expected: %24.18f. Got: %24.18f.\n", EXPECTED, GOT);\
          if(signbit(EXPECTED)&!signbit(GOT)) printf("Sign bits differ\n");\
          __PRINT_ERROR(FAIL_CODE, LOOPC)\
          return FAIL_CODE;\
          }\
      }\
      if(fabs(GOT-EXPECTED)>=TOLERANCE)\
        {\
          printf("Error: results mismatch in value\n");\
          printf("Expected: %24.18f. Got: %24.18f.\n Magnitude of error: %24.18f.\n Compared using tolerance: %24.18f\n", EXPECTED, GOT, fabs(EXPECTED-GOT), TOLERANCE);\
          __PRINT_ERROR(FAIL_CODE, LOOPC)\
          return FAIL_CODE;\
        }
#endif


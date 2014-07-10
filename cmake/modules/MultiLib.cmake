#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

# Inclusion of this module sets the targets supported by the machine on which
# CMake is running. SUPPORT_${TARGET} is set to TRUE or FALSE for each target in
# dbg, std, sse41, sse42, avx1 and avx2. std and sbg require no special CPU
# support and are always set.

include(CMakeParseArguments)

# Create a library for multiple target instruction sets. Note that this is
# specialised to its use in OG-Maths and does not fully provide all of the
# functionality that can be provided by add_library and set_target_properties.
# One instance of the library is created for each of the TARGETS.

function(add_multitarget_library _TARGET_NAME)
  cmake_parse_arguments(MTLIB
                        ""
                        "VERSION;SOVERSION"
                        "SOURCES;TARGETS;LINK_MULTILIBRARIES;LINK_LIBRARIES;COMPILE_DEFINITIONS;MULTI_DEPENDS;DEPENDS"
                        ${ARGN})
  foreach(TARGET ${MTLIB_TARGETS})
    set(LIBNAME ${_TARGET_NAME}_${TARGET})
    add_library(${LIBNAME} SHARED ${MTLIB_SOURCES})
    set_target_properties(
                          ${LIBNAME} PROPERTIES
                          VERSION ${MTLIB_VERSION}
                          SOVERSION ${MTLIB_SOVERSION}
                          COMPILE_FLAGS ${OPT_FLAGS_${TARGET}}
                          LINK_FLAGS ${OPT_FLAGS_${TARGET}}
                          )
    foreach(LINK_LIB ${MTLIB_LINK_MULTILIBRARIES})
      target_link_libraries(${LIBNAME} ${LINK_LIB}_${TARGET})
    endforeach()
    foreach(LINK_LIB ${MTLIB_LINK_LIBRARIES})
      target_link_libraries(${LIBNAME} ${LINK_LIB})
    endforeach()
    foreach(COMPILE_DEFINITION ${MTLIB_COMPILE_DEFINITIONS})
      set_target_properties(${LIBNAME} PROPERTIES COMPILE_DEFINITIONS ${COMPILE_DEFINITION})
    endforeach()
    foreach(DEPENDENCY ${MTLIB_MULTI_DEPENDS})
      add_dependencies(${LIBNAME} ${DEPENDENCY}_${TARGET})
    endforeach()
    foreach(DEPENDENCY ${MTLIB_DEPENDS})
      add_dependencies(${LIBNAME} ${DEPENDENCY})
    endforeach()
  endforeach()
endfunction()

try_run(CPUID_FLAG CPUID_COMPILE_RESULT
        ${CMAKE_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/cmake/modules/cmcpuid.c)

set(SUPPORT_dbg TRUE)
set(SUPPORT_std TRUE)

# NOTE: These flags must match the numbers in cmcpuid.c
if(${CPUID_FLAG} GREATER 1)
  set(SUPPORT_sse41 TRUE)
  message(STATUS "CPU supports SSE4.1")
else()
  message(STATUS "CPU does not support SSE4.1")
endif()
if(${CPUID_FLAG} GREATER 2)
  set(SUPPORT_sse42 TRUE)
  message(STATUS "CPU supports SSE4.2")
else()
  message(STATUS "CPU does not support SSE4.2")
endif()
if(${CPUID_FLAG} GREATER 3)
  set(SUPPORT_avx1 TRUE)
  message(STATUS "CPU supports AVX1")
else()
  message(STATUS "CPU does not support AVX1")
endif()
if(${CPUID_FLAG} GREATER 4)
  set(SUPPORT_avx2 TRUE)
  message(STATUS "CPU supports AVX2")
else()
  message(STATUS "CPU does not support AVX2")
endif()



# Executes the target as a test once, and then once again with valgrind
# Appropriate flags are added so that GTest outputs JUnit XML for later
# processing. The target is appended to the list of tests that is used in the
# add_gtest_report macro.
macro(add_custom_test TESTNAME)
  get_target_property(TEST_LOC ${TESTNAME} LOCATION)
  add_test(${TESTNAME} ${TEST_LOC})
  if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_test(${TESTNAME}_valgrind valgrind --leak-check=full --error-exitcode=1 ${TEST_LOC})
  endif()
  list(APPEND gtests ${TESTNAME})
  set(tests ${tests} CACHE INTERNAL "Test tests to run")
endmacro()

# Builds a test executable from the specified SOURCES and links
# it to any additional LINK_LIBRARIES. The sources are also
# compiled with the specified COMPILE_DEFINITIONS. Valgrind is run on each test.
macro(add_multitarget_test TESTNAME)
  cmake_parse_arguments(MTGTEST "" ""
                        "SOURCES;LINK_LIBRARIES;COMPILE_DEFINITIONS;TARGETS"
                        ${ARGN})
  foreach(TARGET ${MTGTEST_TARGETS})
    if(SUPPORT_${TARGET})
      set(TEST ${TESTNAME}_${TARGET})
      add_executable(${TEST} ${MTGTEST_SOURCES})
      set_target_properties(${TEST} PROPERTIES COMPILE_FLAGS ${OPT_FLAGS_${TARGET}} LINK_FLAGS ${OPT_FLAGS_${TARGET}})
      foreach(LINK_LIBRARY ${MTGTEST_LINK_LIBRARIES})
        target_link_libraries(${TEST} ${LINK_LIBRARY}_${TARGET})
      endforeach()
      foreach(COMPILE_DEFINITION ${MTGTEST_COMPILE_DEFINITIONS})
        set_target_properties(${TEST} PROPERTIES COMPILE_DEFINITIONS ${COMPILE_DEFINITION})
      endforeach()
      add_custom_test(${TEST})
    endif()
  endforeach()
endmacro()



# appendable export file for multitargets
function(add_multitarget_export _TARGET_NAME)
  cmake_parse_arguments(MT
                        ""
                        "EXPORTNAME"
                        "TARGETS"
                        ${ARGN}
                        )
  foreach(TARGET ${MT_TARGETS})
    set(EXPORTABLE_NAME "${_TARGET_NAME}_${TARGET}")
    export(TARGETS ${EXPORTABLE_NAME} APPEND FILE "${PROJECT_BINARY_DIR}/${MT_EXPORTNAME}.cmake")
  endforeach()
endfunction()

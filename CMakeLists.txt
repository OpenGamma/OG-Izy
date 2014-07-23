#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

cmake_minimum_required (VERSION 2.6)

include(CMakeForceCompiler)

if(APPLE OR WIN32)
  # The apple default compiler, Clang, doesn't support OpenMP so we can't use it.
  # On Windows, we don't want to end up building with Visual Studio.
  CMAKE_FORCE_C_COMPILER(gcc GNU)
endif(APPLE OR WIN32)

project (IZY)

# Set version number
set(IZY_VERSION_MAJOR 0)
set(IZY_VERSION_MINOR 0)
set(IZY_VERSION_PATCH 1)
set(IZY_VERSION
  ${IZY_VERSION_MAJOR}.${IZY_VERSION_MINOR}.${IZY_VERSION_PATCH})


enable_language(C)

# Get Python
find_package(PythonInterp)
message(STATUS "Looking for Python found - ${PYTHONINTERP_FOUND}")
if (PYTHONINTERP_FOUND)
   message(STATUS "Using Python version ${PYTHON_VERSION_STRING}")
endif()

# Construct platform code
if(WIN32)
  set(PLATFORM_CODE win)
else()
  if(APPLE)
    set(PLATFORM_CODE osx)
  else()
    set(PLATFORM_CODE lnx)
  endif()
endif()

if(WIN32)
  set(CMAKE_THREAD_LIBS_INIT -mthreads)
else()
  # we force -pthread in preference to -lpthread because it sets -D_REENTRANT
  set(THREADS_HAVE_PTHREAD_ARG "THREADS_HAVE_PTHREAD_ARG")
  find_package(Threads)
endif()

# Our modules are in cmake/modules
set(CMAKE_MODULE_PATH ${IZY_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

# Use GNU extended C99, other flags for preventing common errors. Also add thread libs.
set(CMAKE_C_FLAGS "-std=gnu99 -Wall -Werror -Wextra -pedantic ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_C_FLAGS}")

# On Linux, add -rdynamic for stack traces
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -rdynamic")
endif()

# Use the native assembler on Apple in order to be able to generate AVX instructions.
if(APPLE)
  set(CMAKE_C_FLAGS "-Wa,-q ${CMAKE_C_FLAGS}")
endif()


# Enable testing with CTest
enable_testing()

# Multi-target libraries need to be built
include(MultiLib)
set(TARGET_TYPES dbg std)
if(BITS64)
  set(TARGET_TYPES ${TARGET_TYPES} sse41 avx1)
endif()


# Tweak flags. These flags are similar to --ffast-math, except:
# -funsafe-math-optimizations is missing as it messes with the FPU control word
# which can cause segfaults when running through the JNI interface.
# -ffinite-math-only is missing as it messes with NaN and Inf in ways that
# break comparison behaviours.
set(FFAST_MATH_SAFE "-fno-math-errno  -fno-rounding-math -fno-signaling-nans -fcx-limited-range")

if (WIN32)
  # We need a larger than default stack to prevent the entrypt test
  # failing, and we need to force the export of all symbols since
  # they were all visible by default in the original implementation.
  set (PLATFORM_FLAGS "-Wl,--export-all-symbols -Wl,--stack,4194304")
  if(BITS32)
    set(PLATFORM_FLAGS "${PLATFORM_FLAGS} -ffloat-store")
  endif()
endif()

set(OPT_FLAGS_dbg "-DDEBUG ${CMAKE_C_FLAGS_DEBUG} ${PLATFORM_FLAGS}")
set(OPT_FLAGS_std "-g ${FFAST_MATH_SAFE} -O2 -funroll-loops -DNDEBUG ${PLATFORM_FLAGS}")
set(OPT_FLAGS_sse41 "-g ${OPT_FLAGS_std} -march=core2 -msse4.1")
set(OPT_FLAGS_avx1 "-g ${OPT_FLAGS_std}  -march=corei7-avx -mavx256-split-unaligned-load -mavx256-split-unaligned-store")


# Coverage - must build underneath the source dir for this to work.
if (NOT WIN32)
  set(DEBUG_TESTS_REGEX "\".*dbg$$\"")
  set(OPT_FLAGS_dbg "--coverage ${OPT_FLAGS_dbg}")
  add_custom_target(gencovinfo
                    COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process -R ${DEBUG_TESTS_REGEX}
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    COMMENT "Running tests to gather C++ coverage information")
  add_custom_target(coverageinfo
                    COMMAND lcov --capture -i -d . --output-file ${CMAKE_BINARY_DIR}/coverage-initial.info --no-external
                    COMMAND lcov --capture -d . --output-file ${CMAKE_BINARY_DIR}/coverage-run.info --no-external
                    COMMAND lcov -a ${CMAKE_BINARY_DIR}/coverage-initial.info -a ${CMAKE_BINARY_DIR}/coverage-run.info --output-file ${CMAKE_BINARY_DIR}/coverage.info --no-external
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    DEPENDS gencovinfo
                    COMMENT "Capturing coverage info")

  add_custom_target(coverageextract
                     DEPENDS coverageinfo
                     COMMAND lcov -o coverage-extract.info --extract coverage.info "\"${CMAKE_SOURCE_DIR}/include/*\"" "\"${CMAKE_SOURCE_DIR}/izy/*\"" "\"${CMAKE_SOURCE_DIR}/reference/*\"" "\"${CMAKE_SOURCE_DIR}/test/*\""
                     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                     COMMENT "Removing external from coverage info")

  add_custom_target(coverage
                    COMMAND genhtml -o lcov.out coverage-extract.info
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    DEPENDS coverageextract
                    COMMENT "Generating coverage report")
endif()


# Copy platform-dependent expected test failure files.
if(WIN32)
  message(STATUS "Copying Windows test suppressions file.")
  if(BITS32)
    configure_file(test/CTestCustom.windows-32 CTestCustom.ctest)
  else()
    configure_file(test/CTestCustom.windows CTestCustom.ctest)
  endif()
endif(WIN32)

if(APPLE)
  add_definitions(-DSLACK_TESTS)
endif(APPLE)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--rpath -Wl,\$ORIGIN")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${IZY_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${IZY_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${IZY_BINARY_DIR}/lib)

# Subdirectories
add_subdirectory (reference)
add_subdirectory (izy)
add_subdirectory (test)
add_subdirectory (include)
add_subdirectory (man)

# Add version info file
if(NOT DEFINED BUILDNUMBER)
  set(BUILDNUMBER local)
endif()
add_custom_target(verinfo ALL
                  ${PYTHON_EXECUTABLE} ${CMAKE_SOURCE_DIR}/cmake/modules/verinfo.py ${CMAKE_BINARY_DIR}/verinfo.yaml ${JAR_VERSION} ${BUILDNUMBER}
                  COMMENT "Generating version info")

# Show user general info about build
message("
  Package " ${CMAKE_PROJECT_NAME} " version " ${IZY_VERSION} " build type: " ${CMAKE_BUILD_TYPE} "
  Prefix.............: " ${CMAKE_INSTALL_PREFIX} "
  C Compiler.........: " ${CMAKE_C_COMPILER} "
  C Flags............: " ${CMAKE_C_FLAGS} "
  C Flags (debug)....: " ${CMAKE_C_FLAGS} ${OPT_FLAGS_dbg} "
  C Flags (std)......: " ${CMAKE_C_FLAGS} ${OPT_FLAGS_std} "
  C Flags (sse41)....: " ${CMAKE_C_FLAGS} ${OPT_FLAGS_sse41} "
  C Flags (avx1).....: " ${CMAKE_C_FLAGS} ${OPT_FLAGS_avx1} "
")

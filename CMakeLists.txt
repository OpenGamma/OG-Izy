# The name of our project is "IZY". CMakeLists files in this project can
# refer to the root source directory of the project as ${IZY_SOURCE_DIR} and
# to the root binary directory of the project as ${IZY_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)

include(CMakeForceCompiler)

if(APPLE OR WIN32)
  # The apple default compiler, Clang, doesn't support OpenMP so we can't use it.
  # On Windows, we don't want to end up building with Visual Studio.
  # Force both C and C++ so that the OpenMP test doesn't show a bunch of errors.
  CMAKE_FORCE_C_COMPILER(gcc GNU)
  CMAKE_FORCE_CXX_COMPILER(g++ GNU)
endif(APPLE OR WIN32)

project (IZY)

# Set version number
set(IZY_VERSION_MAJOR 0)
set(IZY_VERSION_MINOR 0)
set(IZY_VERSION_PATCH 1)
set(IZY_VERSION
  ${IZY_VERSION_MAJOR}.${IZY_VERSION_MINOR}.${IZY_VERSION_PATCH})

# Appends the cmake/modules path inside the MAKE_MODULE_PATH variable which stores the
# directories of additional CMake modules (ie. MacroOutOfSourceBuild.cmake):
set(CMAKE_MODULE_PATH ${IZY_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

# Check for OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# Enable testing with CTest
enable_testing()

# Copy platform-dependent expected test failure files.
include(GlibcDetect)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  glibc_detect(GLIBC_VERSION)
  set(KNOWN_GLIBC_VERSIONS 2.12 2.13 2.14)
  list(FIND KNOWN_GLIBC_VERSIONS ${GLIBC_VERSION} KNOWN_GLIBC)
  if(KNOWN_GLIBC MATCHES -1)
    message(STATUS "Unrecognised glibc version ${GLIBC_VERSION}. Not copying test suppressions file.")
    message(STATUS "You may experience test failures. These may or may not be unexpected.")
  else(KNOWN_GLIBC MATCHES -1)
    message(STATUS "Known glibc version. Copying test suppressions file.")
    configure_file(test/CTestCustom.glibc-${GLIBC_VERSION} CTestCustom.ctest)
  endif(KNOWN_GLIBC MATCHES -1)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(APPLE)
  message(STATUS "Copying Apple test suppressions file.")
  configure_file(test/CTestCustom.apple CTestCustom.ctest)
endif(APPLE)

if(WIN32)
  message(STATUS "Copying Windows test suppressions file.")
  configure_file(test/CTestCustom.windows CTestCustom.ctest)
endif(WIN32)

# Recurse into the "izy", "reference", and "test" subdirectories. This does not
# actually cause another cmake executable to run. The same process will walk
# through the project's entire directory structure.
add_subdirectory (reference)
add_subdirectory (izy)
add_subdirectory (test)
add_subdirectory (include)
add_subdirectory (man)

message("
  Package " ${CMAKE_PROJECT_NAME} " version " ${IZY_VERSION} " build type: " ${CMAKE_BUILD_TYPE} "
  Prefix.............: " ${CMAKE_INSTALL_PREFIX} "
  C Compiler.........: " ${CMAKE_C_COMPILER} "
  C Flags............: " ${CMAKE_C_FLAGS} "
  C Flags (debug)....: " ${CMAKE_C_FLAGS_DEBUG} "
  C Flags (release)..: " ${CMAKE_C_FLAGS_RELEASE} "
")

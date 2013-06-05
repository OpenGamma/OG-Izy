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

# Our modules are in cmake/modules
set(CMAKE_MODULE_PATH ${IZY_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

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

set(CPACK_GENERATOR "DEB" "RPM")
set(CPACK_PACKAGE_NAME "libizy")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The IZY vector maths library")
set(CPACK_PACKAGE_VERSION_MAJOR ${IZY_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${IZY_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${IZY_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT "Graham Markall <graham@opengamma.com>")
set(CPACK_DEBIAN_PACKAGE_NAME "libizy0")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3)")
include(CPack)

# Subdirectories
add_subdirectory (reference)
add_subdirectory (izy)
add_subdirectory (test)
add_subdirectory (include)
add_subdirectory (man)

# Show user general info about build
message("
  Package " ${CMAKE_PROJECT_NAME} " version " ${IZY_VERSION} " build type: " ${CMAKE_BUILD_TYPE} "
  Prefix.............: " ${CMAKE_INSTALL_PREFIX} "
  C Compiler.........: " ${CMAKE_C_COMPILER} "
  C Flags............: " ${CMAKE_C_FLAGS} "
  C Flags (debug)....: " ${CMAKE_C_FLAGS_DEBUG} "
  C Flags (release)..: " ${CMAKE_C_FLAGS_RELEASE} "
  C Flags (relwdbg)..: " ${CMAKE_C_FLAGS_RELWITHDEBINFO} "
")

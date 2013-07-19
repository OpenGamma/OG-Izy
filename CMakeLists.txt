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
if(WIN32)
  message(STATUS "Copying Windows test suppressions file.")
  configure_file(test/CTestCustom.windows CTestCustom.ctest)
endif(WIN32)

if(APPLE)
  add_definitions(-DSLACK_TESTS)
endif(ENDIF)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--rpath, -Wl,.")
endif()

set(CPACK_GENERATOR "TGZ" "DEB" "RPM" "NSIS" "PackageMaker")
set(CPACK_PACKAGE_NAME "libizy")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The IZY vector maths library")
set(CPACK_PACKAGE_VERSION_MAJOR ${IZY_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${IZY_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${IZY_VERSION_PATCH})
set(CPACK_PACKAGE_CONTACT "Graham Markall <graham@opengamma.com>")

set(CPACK_DEBIAN_PACKAGE_NAME "libizy0")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3)")

# Backslashes in names required due to some weird bug in NSIS. See: 
# http://www.cmake.org/pipermail/cmake/2008-June/022085.html
set(ICON "${CMAKE_SOURCE_DIR}/installer/\\\\OpenGamma.ico")
set(BANNER "${CMAKE_SOURCE_DIR}/installer/\\\\opengamma-banner.bmp")

set(CPACK_NSIS_MUI_ICON ${ICON})
set(CPACK_NSIS_MUI_UNIICON ${ICON})
set(CPACK_NSIS_INSTALLED_ICON_NAME ${ICON})
set(CPACK_PACKAGE_ICON ${BANNER})
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_NSIS_DISPLAY_NAME "OpenGamma LibIZY")
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE.txt)

include(CPack)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${IZY_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${IZY_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${IZY_BINARY_DIR}/lib)

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

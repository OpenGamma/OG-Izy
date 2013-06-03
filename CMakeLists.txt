# The name of our project is "IZY". CMakeLists files in this project can
# refer to the root source directory of the project as ${IZY_SOURCE_DIR} and
# to the root binary directory of the project as ${IZY_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)

include(CMakeForceCompiler)

if(APPLE)
  # The apple default compiler, Clang, doesn't support OpenMP so we can't use it.
  # Force both C and C++ so that the OpenMP test doesn't show a bunch of errors.
  CMAKE_FORCE_C_COMPILER(gcc GNU)
  CMAKE_FORCE_CXX_COMPILER(g++ GNU)
endif(APPLE)

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

# Apple linker doesn't like undefined symbols in shared libraries by default.
if(APPLE)
  set(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS} -flat_namespace -undefined suppress")
  set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -flat_namespace -undefined suppress")
endif(APPLE)

# Copy platform-dependent expected test failure files.
include(GlibcDetect)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  message("Lee-nooks!")
  glibc_detect(GLIBC_VERSION)
  configure_file(test/CTestCustom.linux CTestCustom.ctest)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Recurse into the "izy", "reference", and "test" subdirectories. This does not
# actually cause another cmake executable to run. The same process will walk
# through the project's entire directory structure.
add_subdirectory (izy)
add_subdirectory (reference)
add_subdirectory (test)
add_subdirectory (include)
add_subdirectory (man)

message("
  Package " ${CMAKE_PROJECT_NAME} " version " ${IZY_VERSION} "
  Prefix.............: " ${CMAKE_INSTALL_PREFIX} "
  C Compiler.........: " ${CMAKE_C_COMPILER} "
  C Flags............: " ${CMAKE_C_FLAGS} "
  C++ Compiler.......: " ${CMAKE_CXX_COMPILER} "
  C++ Flags..........: " ${CMAKE_CXX_FLAGS} "
  Shared link flags..: " ${CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS} "
")

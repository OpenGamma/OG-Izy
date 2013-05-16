# The name of our project is "IZY". CMakeLists files in this project can
# refer to the root source directory of the project as ${IZY_SOURCE_DIR} and
# to the root binary directory of the project as ${IZY_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (IZY)

# Appends the cmake/modules path inside the MAKE_MODULE_PATH variable which stores the
# directories of additional CMake modules (ie. MacroOutOfSourceBuild.cmake):
set(CMAKE_MODULE_PATH ${IZY_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

# The macro below forces the build directory to be different from source directory:
include(MacroOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build.")

# Recurse into the "izy", "reference", and "test" subdirectories. This does not
# actually cause another cmake executable to run. The same process will walk
# through the project's entire directory structure.
add_subdirectory (izy)
add_subdirectory (reference)
add_subdirectory (test)

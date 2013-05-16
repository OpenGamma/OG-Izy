# The name of our project is "IZY". CMakeLists files in this project can
# refer to the root source directory of the project as ${IZY_SOURCE_DIR} and
# to the root binary directory of the project as ${IZY_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (IZY)

# Recurse into the "izy", "reference", and "test" subdirectories. This does not
# actually cause another cmake executable to run. The same process will walk
# through the project's entire directory structure.
add_subdirectory (izy)
add_subdirectory (reference)
#add_subdirectory (test)

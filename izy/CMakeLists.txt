#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

# Include folder
include_directories (${IZY_SOURCE_DIR}/include)

# We build the static library with a different name since this is recommended on Windows.
# We keep this behaviour on Linux/Apple for consistency across platforms,
add_library (izy SHARED izy.c)
add_dependencies(izy izyreference)
target_link_libraries(izy m izyreference)
set_target_properties(izy PROPERTIES SOVERSION ${IZY_VERSION_MAJOR} VERSION ${IZY_VERSION})
install(TARGETS izy DESTINATION lib)

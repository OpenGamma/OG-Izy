#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

# Include folder
include_directories (${IZY_SOURCE_DIR}/include)

set(IZYSRC izy.c)

# build multilib
add_multitarget_library(izy
                        VERSION ${IZY_VERSION}
                        SOVERSION ${IZY_VERSION_MAJOR}
                        SOURCES ${IZYSRC}
                        LINK_MULTILIBRARIES izyreference
                        TARGETS ${TARGET_TYPES}
                        DEPENDS ${INCLUDE_DIRS_TARGET})

add_multitarget_export(izy
                        EXPORTNAME "IZY_EXPORTS"
                        TARGETS ${TARGET_TYPES}
                       )


FILE(APPEND "${PROJECT_BINARY_DIR}/IZY_EXPORTS.cmake" "# Set IZY_INCLUDE_DIR for future use.\n")
FILE(APPEND "${PROJECT_BINARY_DIR}/IZY_EXPORTS.cmake" "set(IZY_INCLUDE_DIR \"${IZY_SOURCE_DIR}/include\")\n")
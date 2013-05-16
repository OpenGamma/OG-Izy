include_directories (${IZY_SOURCE_DIR}/include)
# Create a library called "IZY" which includes the source file "izy.c".
# The extension is already found. Any number of sources could be listed here.
add_library (izy SHARED izy.c)
add_library (izy_static STATIC izy.c)
target_link_libraries(izy m)
set_target_properties(izy PROPERTIES SOVERSION ${IZY_VERSION_MAJOR} VERSION ${IZY_VERSION})
install(TARGETS izy LIBRARY DESTINATION lib)
install(TARGETS izy_static ARCHIVE DESTINATION lib)

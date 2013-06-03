# Checks for MKL headers and linkge

INCLUDE(CheckIncludeFiles)
INCLUDE(CheckLibraryExists)

MACRO(CHECK_MKL)
  CHECK_INCLUDE_FILES(mkl.h HAVE_MKL_H)
  CHECK_LIBRARY_EXISTS(libmkl vdAdd "" HAVE_MKL)
ENDMACRO(CHECK_MKL)

#
# Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

# Checks for MKL headers and linkage

INCLUDE(CheckIncludeFiles)
INCLUDE(CheckLibraryExists)

MACRO(CHECK_MKL)
  CHECK_INCLUDE_FILES(mkl.h HAVE_MKL_H)
  CHECK_LIBRARY_EXISTS(libmkl vdAdd "" HAVE_MKL)
ENDMACRO(CHECK_MKL)

SUBDIRS = reference/
lib_LTLIBRARIES =  libizy.la 


libizy_la_CPPFLAGS = -I ../include/
libizy_la_LIBADD = reference/libizyreference.la
libizy_la_LDFLAGS = -version-info $(LIBIZY_VERSION)
libizy_la_SOURCES = izy.c

AM_CFLAGS=@CFLAGS@ -fPIC -Wall
AM_LDFLAGS=-no-undefined

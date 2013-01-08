#!/bin/bash
# A quick script to just execute the toolchain commands to save typing!
echo "  aclocal"
aclocal -I m4
echo "  autoconf"
autoconf
echo "  autoheader"
autoheader
echo "  libtoolize --automake"
libtoolize --automake
echo "  automake --add-missing"
automake --add-missing 

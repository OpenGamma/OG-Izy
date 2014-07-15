<!--
 Copyright (C) 2014 - present by OpenGamma Inc. and the OpenGamma group of companies

 Please see distribution for license.
-->
OpenGamma Izy Installation.
========
[![OpenGamma](http://developers.opengamma.com/res/display/default/chrome/masthead_logo.png "OpenGamma")](http://developers.opengamma.com)

### Requirements ###
Generally recent versions of the requirements are preferred:

#### Tools:
 * CMake 2.8 (we test with 2.8.11)
 * GCC (we test with 4.8.2)
 * Python 2.6 or 2.7 with the argparse and yaml modules

#### Operating Systems:
 * Windows 7/8 (we test on Windows 7)
 * Mac OS X 10.9 (we test on 10.9)
 * Linux (we test on CentOS 6, Debian 7, and Fedora 18 and 19)

#### Obtaining the OG-Izy source:
The source code can be cloned from Github:
```
git clone https://github.com/OpenGamma/OG-Izy.git
```

Building
--------
Create an out-of-tree build dir and run CMake:
```
mkdir build
cd build
cmake ..
```

Build with:
```
make -j
```

It is highly recommended that you test your build, since different platforms, compilers, or system math libraries may have an effect on computed results. Test with:
```
export NPROCS=4
make test ARGS=-j${NPROCS}
```



[![Build Status](https://travis-ci.org/stevengj/nlopt.svg?branch=master)](https://travis-ci.org/stevengj/nlopt)

NLopt is a library for nonlinear local and global optimization, for
functions with and without gradient information.  It is designed as
as simple, unified interface and packaging of several free/open-source
nonlinear optimization libraries.

The latest release and a complete manual may be found at the NLopt
home page: http://ab-initio.mit.edu/nlopt

It is compiled and installed with CMake build system:

    cmake .
    sudo make install

See `CMakeLists.txt` file for cmake options.
To build the latest development sources:

    git clone git://github.com/stevengj/nlopt
    cd nlopt
    cmake .
    make

(To build from git, you will need SWIG.)

Once it is installed, `#include <nlopt.h>` in your C/C++ programs and
link it with `-lnlopt -lm`.  You may need to use the C++ compiler to link
in order to include the C++ libraries (which are used internally by NLopt,
even though it has a C API).

The minimization function, `nlopt_minimize`, is described in the [man
page](http://en.wikipedia.org/wiki/Man_page) (`api/nlopt_minimize.3`,
which is installed by `make install`.  See also the manual on our
web page.

There are also interfaces for Fortran, Python, Matlab, Octave, OCaml,
GNU Guile, GNU R, Lua, and Julia.  Interfaces for other languages may
be added in the future.

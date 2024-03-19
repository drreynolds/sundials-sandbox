# sundials-sandbox
Template repostory for codes that utilize SUNDIALS.

This includes simple implementations of customized N_Vector and SUNLinearSolver modules, along with testing routines for each.  It also includes two existing SUNDIALS examples, to serve as templates for codes that utilize the ARKODE and CVODE integrators from SUNDIALS.

This repository provides a simple `CMakeLists.txt` file to compile each of the above codes against a given SUNDIALS installation.

This setup assumes out-of-source builds, and requires that the path for the installed `SUNDIALSConfig.cmake` file be held in the CMake variable  `SUNDIALS_DIR`.  For example, from within this directory:

```
mkdir build
cd build
cmake -DSUNDIALS_DIR=/usr/local/sundials/lib/cmake/sundials ..
make
```

This has been tested using SUNDIALS v7.0.

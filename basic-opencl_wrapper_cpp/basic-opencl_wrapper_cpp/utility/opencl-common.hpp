#ifndef OPENCL_COMMON_HPP
#define OPENCL_COMMON_HPP

#include <iostream>
#include <memory>
#include <dbg.h>

#define __CL_ENABLE_EXCEPTIONS


// mac files
#ifdef MAC
    #include <OpenCL/cl.hpp>
#else
    #include <CL/cl.hpp>
    #define __NO_STD_VECTOR
    #define __NO_STD_STRING
#endif

#endif

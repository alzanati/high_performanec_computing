# project name
project(basic-opencl_wrapper_cpp)

# minimum version
cmake_minimum_required(VERSION 2.8)

### Add the CMAKE directory into the source tree
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# include opencl
include(OpenCL)

# add compiler version
add_compile_options(-std=c++11)

# add utility header files
SET(UTILITY_HDR_FILES
    utility/cmdutility.h
    utility/dbg.h
    utility/opencl-common.hpp
    utility/matrix.h)

# add src files
SET(SRC_FILES
    src/cmdqueue.cpp
    src/context.cpp
    src/device.cpp
    src/kernel.cpp
    src/platform.cpp
    src/program.cpp)

# add header files
SET(HDR_FILES
    hdr/cmdqueue.h
    hdr/context.h
    hdr/device.h
    hdr/kernel.h
    hdr/platform.h
    hdr/program.h
    hdr/pexception.h)

# add kernels
SET(KERNELS
    kernels/add_one.cl
    kernels/matrix_multiplication.cl)

# set sources
aux_source_directory(. SRC_LIST)

# include dir to make include in files done without spacify folder name
include_directories(utility)
include_directories(src)
include_directories(hdr)
include_directories(kernels)

#link library
target_link_libraries(${OPENCL_LIBRARY})

# create executable
add_executable(${PROJECT_NAME} ${SRC_LIST} ${UTILITY_HDR_FILES}
    ${SRC_FILES} ${HDR_FILES} ${KERNELS})

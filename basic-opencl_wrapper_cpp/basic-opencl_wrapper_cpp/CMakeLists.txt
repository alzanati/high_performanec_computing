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

# set sources
aux_source_directory(. SRC_LIST)

# add utility folder
include_directories(utility)

#link library
target_link_libraries(${OPENCL_LIBRARY})

# create executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

# minimum version
cmake_minimum_required( VERSION 2.8 )

# project name
project( omp_assignment_1 )

# inlude directories
include_directories( 
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/include )

# sources files
set( SRC_FILES
    src/main.cpp
    src/Example.cpp )

# header files
set( HDR_FILES
    include/Example.h )

# add library
set( LIBRARY_NAME assignment_1_omp )

# find open mp packages 
find_package( OpenMP )
if ( OPENMP_FOUND )
    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}" )
    set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}" )
    set ( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall" )
    set ( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall" )
endif()

# add library
add_library( ${LIBRARY_NAME} ${SRC_FILES} ${HDR_FILES})

# create executable
add_executable( ${PROJECT_NAME} ${SRC_FILES} )





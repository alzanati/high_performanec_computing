#include <iostream>
#include <memory>
#include <typeinfo>
#include <CL/cl.h>
#include <CL/cl.hpp>

template< class T >
const inline void println(T data) {
    std::cout << "\033[1;32m" << data << "\033[0m\n";
}

const inline void printError(int err) {
    std::cout << "\033[1;31m"\
              << "Error code : "\
              << err << "\033[0m\n";
}

int main (int argc, char *argv[]) {

    VECTOR_CLASS<cl::Platform> platforms;
    int err = cl::Platform::get(&platforms);
    if (err < 0 )
        printError(err);
    println("Ahmed");
    return 0;
}

#include <iostream>
#include <memory>
#include <typeinfo>
#include <dbg.h>
#include <cmdutility.h>
#include <platform.h>

template< class T >
const inline void println (T data, utility::color::Code code) {
    utility::Modifier color(code);
    std::cout << color << data << CLOSE "\n";
}

int main (int argc, char *argv[]) {
    opencl::ClPlatform platform;
    println(platform.name(), utility::color::Code::BG_GREEN);
    return 0;
}

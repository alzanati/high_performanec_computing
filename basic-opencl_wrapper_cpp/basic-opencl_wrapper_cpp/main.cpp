#include <iostream>
#include <cmdutility.h>

#include <device.h>

using utility::color::Code;

template< class T >
const inline void println (T data, Code code) {
    utility::Modifier color(code);
    std::cout << color << data << CLOSE "\n";
}

int main (int argc, char *argv[]) {
    short int index(0);
    opencl::ClPlatform platform;
    println(platform.name(), Code::FG_DEFAULT);

    opencl::ClDevice device(platform.getPlatform());
    println(device.name(), Code::FG_BLUE);
    VECTOR_CLASS<size_t> dimensions = device.maxWorkItemsSize();
    for (auto itr = dimensions.begin(); itr != dimensions.end(); itr++) {
        std::cout << "dim[" << index++ << "]"; println(*itr, Code::BG_GREEN);
    }

    return 0;
}

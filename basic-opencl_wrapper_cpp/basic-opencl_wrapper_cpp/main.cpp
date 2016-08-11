#include <iostream>
#include <cmdutility.h>

#include <device.h>
#include <context.h>

using utility::color::Code;

template< class T >
const inline void println (T data, Code code) {
    utility::Modifier color(code);
    std::cout << color << data << CLOSE "\n";
}

int main (int argc, char *argv[]) {

    /* platform */
    opencl::ClPlatform platform;
    println(platform.name(), Code::FG_DEFAULT);

    /* device */
    opencl::ClDevice device(platform.getPlatform());
    println(device.name(), Code::FG_BLUE);
    short int index(0);
    VECTOR_CLASS<size_t> dimensions = device.maxWorkItemsSize();
    for (auto itr = dimensions.begin(); itr != dimensions.end(); itr++) {
        std::cout << "dim[" << index++ << "]"; println(*itr, Code::BG_GREEN);
    }

    /* context */
    opencl::ClContext context( CL_DEVICE_TYPE_GPU, NULL );
    VECTOR_CLASS<cl::Device> devices = context.getContextDevices();
    for (auto itr = devices.begin(); itr != devices.end(); itr++) {
        cl::STRING_CLASS name = (*itr).getInfo<CL_DEVICE_NAME>();
        println(name, Code::FG_PURPPLE);
    }

    return 0;
}

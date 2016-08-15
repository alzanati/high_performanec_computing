#include <iostream>
#include <cmdutility.h>
#include <device.h>
#include <context.h>
#include <pexception.h>
#include <program.h>

#define BASE "/projects/image-processing/basic-opencl_wrapper_cpp/basic-opencl_wrapper_cpp/"
using utility::color::Code;

template< class T >
const inline void println (T data, Code code) {
    utility::Modifier color(code);
    std::cout << color << data << CLOSE "\n";
}

struct data {
    int A[100];
    int B[100];
    int C[100];
};

int main (int argc, char *argv[]) {

    int err;
    cl::STRING_CLASS s = "";
    struct data* input = new struct data;

    /* create data */
    for (int i = 0; i < 100; i++) {
        input->A[i] = i;
        input->B[i] = i;
        input->C[i] = 0;
    }

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

    /* test exception class */
    cl::Program myProg;
    opencl::ClProgram* prog;
    try {
        prog = new opencl::ClProgram (context.getContext(), BASE "add_one.cl");
        log_info("kernel name: %s", prog->getKernelNames().c_str());
        myProg = prog->getClProgram();
    } catch (exceptions::ClException e) {
        log_err("%s", e.message());
    }

    /* create kernel objects*/
    cl::Kernel* add_one;
    try {
        add_one = new cl::Kernel(myProg, prog->getKernelNames().c_str(), &err);
        add_one->getInfo<cl::STRING_CLASS>(CL_KERNEL_FUNCTION_NAME, &s);
        log_info("%s", s.c_str());
    } catch (exceptions::ClException e) {
        log_err("%s", e.message());
    }

    /* create memory objects */
    cl::Buffer bufA( context.getContext(),
                     CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                     sizeof(input->A), input->A, &err );
    add_one->setArg(0, bufA);
    std::cout << "bufA : ";println(bufA.getInfo<CL_MEM_SIZE>(), Code::FG_PURPPLE);

    cl::Buffer bufB( context.getContext(),
                     CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                     sizeof(input->B), input->B, &err );
    add_one->setArg(1, bufB);
    std::cout << "bufB : ";println(bufA.getInfo<CL_MEM_SIZE>(), Code::FG_PURPPLE);

    cl::Buffer bufC( context.getContext(),
                     CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR,
                     sizeof(input->C), input->C, &err );
    add_one->setArg(2, bufC);
    std::cout << "bufC : ";println(bufA.getInfo<CL_MEM_SIZE>(), Code::FG_PURPPLE);

    /* create commandqueue */
    cl::CommandQueue cmdQueue(context.getContext(), device.getDevice(), 0, &err);
    if (err != CL_SUCCESS) {
        exceptions::ClException e(err);
        log_err("%s", e.message());
    }
    cl::NDRange offset(0, 0);
    cl::NDRange global_size(100, 1);
    cl::NDRange local_size(100, 1);

    err = cmdQueue.enqueueNDRangeKernel(*add_one, offset, global_size);
    if (err != CL_SUCCESS) {
        exceptions::ClException e(err);
        log_err("%s", e.message());
    }
    err = cmdQueue.enqueueReadBuffer(bufC, CL_TRUE, 0, sizeof(input->C), input->C);
    for (int i = 0; i < 100; i++) {
        std::cout << input->C[i] << ", ";
    }
    std::cout << "\n";

    /* free system */
    delete(input);

    return 0;
}

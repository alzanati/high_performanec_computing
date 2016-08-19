#include <iostream>
#include <cmdutility.h>
#include <device.h>
#include <context.h>
#include <pexception.h>
#include <program.h>
#include <matrix.h>

#define ROOT "/projects/image-processing/basic-opencl_wrapper_cpp/basic-opencl_wrapper_cpp/"
#define PATH(x) { ROOT "kernels/" x }
#define N 4
using utility::color::Code;

template< class T >
const inline void println (T data, Code code) {
    utility::Modifier color(code);
    std::cout << color << data << CLOSE "\n";
}

struct data {
    int A[N * N];
    int B[N * N];
    int C[N * N];
};

void unit_test (int argc, char** argv) {
    int err;
    cl::STRING_CLASS s = "";
    struct data* input = new struct data;

    /* create data */
    int a[N * N] = {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15, 16};
    int b[N * N] = {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15, 16};

    int c[N * N] = {0, 0, 0, 0,
                    0, 0, 0, 0,
                    0, 0, 0, 0,
                    0, 0, 0, 0};

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
        prog = new opencl::ClProgram (context.getContext(), PATH("matrix_transpose.cl"));
        log_info("kernel name: %s", prog->getKernelNames().c_str());
        myProg = prog->getClProgram();
    } catch (exceptions::ClException e) {
        log_err("%s", e.message());
    }

    /* create kernel objects*/
    cl::Kernel* matrix_multiplication;
    try {
        matrix_multiplication = new cl::Kernel(myProg, "matrix_transpose", &err);
        matrix_multiplication->getInfo<cl::STRING_CLASS>(CL_KERNEL_FUNCTION_NAME, &s);
        log_info("%s", s.c_str());
    } catch (exceptions::ClException e) {
        log_err("%s", e.message());
    }

    /* create memory objects */
    int size = 4;
    matrix_multiplication->setArg(0, sizeof(int), &size);
    matrix_multiplication->setArg(1, sizeof(int), &size);

    cl::Buffer bufA( context.getContext(),
                     CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                     sizeof(a), a, &err );
    matrix_multiplication->setArg(2, bufA);
    std::cout << "bufA : ";println(bufA.getInfo<CL_MEM_SIZE>(), Code::FG_PURPPLE);

//    cl::Buffer bufB( context.getContext(),
//                     CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
//                     sizeof(b), b, &err );
//    matrix_multiplication->setArg(2, bufB);
//    std::cout << "bufB : ";println(bufA.getInfo<CL_MEM_SIZE>(), Code::FG_PURPPLE);

    cl::Buffer bufC( context.getContext(),
                     CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR,
                     sizeof(c), c, &err );
    matrix_multiplication->setArg(3, bufC);
    std::cout << "bufC : ";println(bufA.getInfo<CL_MEM_SIZE>(), Code::FG_PURPPLE);

//    matrix_multiplication->setArg(4, sizeof(int)*N, NULL);

    /* create commandqueue */
    cl::CommandQueue cmdQueue(context.getContext(), device.getDevice(), 0, &err);
    if (err != CL_SUCCESS) {
        exceptions::ClException e(err);
        log_err("%s", e.message());
    }

    /* execute program */
    cl::NDRange offset(0, 0);
    cl::NDRange global_size(N, 1); // allocate only 4 work-items for optimized kernel
    err = cmdQueue.enqueueNDRangeKernel(*matrix_multiplication, offset, global_size);
    if (err != CL_SUCCESS) {
        exceptions::ClException e(err);
        log_err("%s", e.message());
    }

    /* read to cpu */
    std::cout << "\n";
    err = cmdQueue.enqueueReadBuffer(bufC, CL_TRUE, 0, sizeof(c), c);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int index = (i * N + j);
            std::cout << c[index] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
    /* free system */
}

int main (int argc, char *argv[]) {
    int a[N * N] = {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15, 16};
    int b[N * N] = {1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15, 16};
    calculations::Matrix<int> multi(a, b, N);
    multi.multiplay();
    multi.printResult();
    unit_test(argc, argv);
    return 0;
}

#ifndef PROGRAM_H
#define PROGRAM_H

#include <opencl-common.hpp>
#include <memory.h>
#include <pexception.h>

namespace opencl {

class ClProgram {
public:
    ClProgram(const cl::Context&,
              const cl::Program::Sources&source);

    ~ClProgram();

private:
    std::shared_ptr<cl::Program> programe;
};
}
#endif

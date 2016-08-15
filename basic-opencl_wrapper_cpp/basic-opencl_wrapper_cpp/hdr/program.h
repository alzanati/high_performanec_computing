#ifndef PROGRAM_H
#define PROGRAM_H

#include <opencl-common.hpp>
#include <memory.h>
#include <pexception.h>
#include <context.h>
#include <fstream>

namespace opencl {

class ClProgram {
public:
    ClProgram();

    ClProgram(const cl::Context &context,
              const char *name);

    const cl::Program getClProgram() const;

    cl::Program createProgram_(const char* name, cl::Context context);

    const cl::STRING_CLASS getKernelNames() const;

private:
    using progPtr = std::unique_ptr<cl::Program>;
    progPtr uniquePtr = progPtr(nullptr);
    cl::Program program_;
};
}
#endif

#include <program.h>

namespace opencl {

ClProgram::ClProgram (const cl::Context& context ,
                      const char *name) {
    int err = 0;
    ClContext con = ClContext(context);
    VECTOR_CLASS<cl::Device> devices = con.getContextDevices();
    program_ = this->createProgram_(name, context);
    err = program_.build(devices);

    if (err != CL_SUCCESS) {
        throw(exceptions::ClException(err));
        cl::STRING_CLASS s = "";
        program_.getBuildInfo<cl::STRING_CLASS>(devices[0], CL_PROGRAM_BUILD_LOG, &s);
        log_err("%s", s.c_str());
    }
}

cl::Program ClProgram::createProgram_(const char *name, cl::Context context) {
    int err;
    std::ifstream programFile(name);
    std::string programString(
                std::istreambuf_iterator<char>(programFile),
                (std::istreambuf_iterator<char>()));
    cl::Program::Sources source(1,
                                std::make_pair(programString.c_str(),
                                programString.length()+1));
    uniquePtr = progPtr(new cl::Program(context, source, &err));
    if (err != CL_SUCCESS) {
        throw(exceptions::ClException(err));
        return static_cast<cl::Program>(nullptr);
    }
    else {
        return *uniquePtr;
    }
}

const cl::STRING_CLASS ClProgram::getKernelNames() const {
    cl::STRING_CLASS s = "";
    program_.getInfo<cl::STRING_CLASS>(CL_PROGRAM_KERNEL_NAMES, &s);
    return s;
}
const cl::Program ClProgram::getClProgram() const {
    return program_;
}

}

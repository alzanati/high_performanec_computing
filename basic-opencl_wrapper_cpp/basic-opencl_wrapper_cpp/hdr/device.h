#ifndef DEVICE_H
#define DEVICE_H

#include <platform.h>

namespace opencl {

class ClDevice {
public:
    ClDevice();

    ClDevice(const cl::Platform &platform);

    virtual const cl::Device getDevice() const;

    const cl::STRING_CLASS builtInKernels() const;

    const cl::STRING_CLASS extensions() const;

    const VECTOR_CLASS<size_t> maxWorkItemsSize() const;

    const cl::STRING_CLASS name() const;

    const cl::STRING_CLASS cVersion() const;

    const cl::STRING_CLASS profile() const;

    const cl::STRING_CLASS vendor() const;

    const cl::STRING_CLASS version() const;

    const cl::STRING_CLASS driver() const;

    ~ClDevice();

protected:
    const cl::STRING_CLASS queryInfo_(const cl::Device& device,
                                      const cl_device_info& info ) const;
private:
    using deviceVector = VECTOR_CLASS<cl::Device>;
    using devicePtr = std::shared_ptr<deviceVector>;

protected:
    devicePtr devices_ = std::make_shared<deviceVector>();
};
}

#endif

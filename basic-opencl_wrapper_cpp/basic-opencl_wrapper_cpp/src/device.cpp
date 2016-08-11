#include <device.h>

namespace opencl {

ClDevice::ClDevice (const cl::Platform &platform) {
    try {
        platform.getDevices(CL_DEVICE_TYPE_ALL, devices_.get());
    } catch (cl::Error e) {
        log_err("%s", e.what());
    }
}

const cl::Device ClDevice::getDevice () const {
    auto lastDevice = *devices_.get();
    auto device = *lastDevice.begin();
    return device;
}

const cl::STRING_CLASS ClDevice::queryInfo_ (const cl::Device &device,
                                             const cl_device_info &info) const {
    cl::STRING_CLASS tempInfo("");
    try {
        device.getInfo( info, &tempInfo);
    } catch (cl::Error e) {
        log_err("%s", e.what());
    }
    return tempInfo;
}

const cl::STRING_CLASS ClDevice::name() const {
    return this->queryInfo_(this->getDevice(), CL_DEVICE_NAME);
}

const cl::STRING_CLASS ClDevice::version() const {
    return this->queryInfo_(this->getDevice(), CL_DEVICE_VERSION);
}

const cl::STRING_CLASS ClDevice::vendor() const {
    return this->queryInfo_(this->getDevice(), CL_DEVICE_VENDOR);
}

const cl::STRING_CLASS ClDevice::profile() const {
    return this->queryInfo_(this->getDevice(), CL_DEVICE_PROFILE);
}

const cl::STRING_CLASS ClDevice::extensions() const {
    return this->queryInfo_(this->getDevice(), CL_DEVICE_EXTENSIONS);
}

const cl::STRING_CLASS ClDevice::cVersion() const {
    return this->queryInfo_(this->getDevice(), CL_DEVICE_OPENCL_C_VERSION);
}

const cl::STRING_CLASS ClDevice::builtInKernels() const {
    return this->queryInfo_(this->getDevice(), CL_DEVICE_BUILT_IN_KERNELS);
}

const cl::STRING_CLASS ClDevice::driver() const {
    return this->queryInfo_(this->getDevice(), CL_DRIVER_VERSION);
}

const VECTOR_CLASS<size_t> ClDevice::maxWorkItemsSize() const {
    VECTOR_CLASS<size_t> dimensions;
    try {
        this->getDevice().getInfo(CL_DEVICE_MAX_WORK_ITEM_SIZES, &dimensions);
    } catch (cl::Error e) {
        log_err("%s", e.what());
    }
    return dimensions;
}

ClDevice::~ClDevice() {

}
}

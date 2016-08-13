#include <context.h>

namespace opencl {

ClContext::ClContext (const cl_device_type type,
                      cl_context_properties* properities) {
    try {
        cl::Context context(type, properities);
        context_ = *sharedContext.get();
        context_ = context;
    } catch (cl::Error e) {
        log_err("%s, Error Code: %d", e.what(), e.err());
    }
}

ClContext::ClContext (const std::vector<cl::Device> &devices,
                      cl_context_properties* properities) {
    try {
        cl::Context context(devices, properities);
        context_ = *sharedContext.get();
        context_ = context;
    } catch (cl::Error e) {
        log_err("%s, Error Code: %d", e.what(), e.err());
    }
}

const cl::Context ClContext::getContext() const {
    return context_;
}

VECTOR_CLASS<cl::Device> ClContext::getContextDevices () const {
    VECTOR_CLASS<cl::Device> devices;
    context_.getInfo(CL_CONTEXT_DEVICES, &devices);
    return devices;
}

VECTOR_CLASS<cl_context_properties> ClContext::getContextProperties() const {
    VECTOR_CLASS<cl_context_properties> properties;
    context_.getInfo(CL_CONTEXT_PROPERTIES, &properties);
    return properties;
}

ClContext::~ClContext() {

}
}

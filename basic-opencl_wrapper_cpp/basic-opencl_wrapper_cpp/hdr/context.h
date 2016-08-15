#ifndef CONTEXT_H
#define CONTEXT_H

#include <opencl-common.hpp>


namespace opencl {

class ClContext {
public:
    ClContext();

    ClContext (cl::Context context ) : context_(context) {}

    ClContext (const VECTOR_CLASS<cl::Device>& devices,
               cl_context_properties* properities);

    ClContext (const cl_device_type type,
               cl_context_properties* properities );

    const cl::Context getContext() const;

    VECTOR_CLASS<cl::Device> getContextDevices () const;

    VECTOR_CLASS<cl_context_properties> getContextProperties () const;

    ~ClContext();

private:
    using contextPtr = std::shared_ptr<cl::Context>;

private:
    contextPtr sharedContext = std::make_shared<cl::Context>();
    cl::Context context_;

};
}

#endif

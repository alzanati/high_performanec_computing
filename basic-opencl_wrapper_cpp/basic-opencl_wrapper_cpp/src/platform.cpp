#include <platform.h>

namespace opencl {

ClPlatform::ClPlatform() {
    try{
        cl::Platform::get(platforms_.get());
    } catch (cl::Error e) {
        log_err("%s, Error Code: %d", e.what(), e.err());
    }
}

ClPlatform::ClPlatform (const ClPlatform& plat)
    :platforms_(plat.platforms_) {
    log_info("Constructor is copied");
}

cl::Platform ClPlatform::getPlatform () const{
    auto lastElement = *platforms_.get();
    auto platform = *lastElement.begin();
    return platform;
}

const cl::STRING_CLASS ClPlatform::name() const {
    return this->queuryInfo_(this->getPlatform(), CL_PLATFORM_NAME);
}

const cl::STRING_CLASS ClPlatform::extensions() const {
    return this->queuryInfo_(this->getPlatform(), CL_PLATFORM_EXTENSIONS);
}

const cl::STRING_CLASS ClPlatform::profile() const {
    return this->queuryInfo_(this->getPlatform(), CL_PLATFORM_PROFILE);
}

const cl::STRING_CLASS ClPlatform::vendor() const {
    return this->queuryInfo_(this->getPlatform(), CL_PLATFORM_VENDOR);
}

const cl::STRING_CLASS ClPlatform::version() const {
    return this->queuryInfo_(this->getPlatform(), CL_PLATFORM_VERSION);
}

const cl::STRING_CLASS ClPlatform::queuryInfo_(cl::Platform platform,
                                               cl_platform_info platformInfo) const {
    cl::STRING_CLASS info("");
    try {
        platform.getInfo(platformInfo, &info);
    } catch (cl::Error e) {
        log_err("%s, Error Code: %d", e.what(), e.err());
    }
    return info;
}

ClPlatform::~ClPlatform() {
    log_info("ClPlaform destructor");
}
}

#ifndef PLATFORM_H
#define PLATFROM_H

#include <opencl-common.hpp>

namespace opencl {

class ClPlatform {
public:
    /**
     * @brief query platforms in vector class
     */
    ClPlatform();

    /**
     * @brief copy constructor
     * @param plat
     */
    ClPlatform (const ClPlatform& plat);

    /**
      virtual: because if we need to deal with many platforms we should override this function
     * @brief getPlatform
     * @return cl platform class to use it in further processes
     */
    virtual cl::Platform getPlatform() const;

    /**
     * @brief extensions
     * @return platform supported extensions
     */
    const cl::STRING_CLASS extensions () const;

    /**
     * @brief name
     * @return platform name
     */
    const cl::STRING_CLASS name () const;

    /**
     * @brief vendor
     * @return  platform vendor name
     */
    const cl::STRING_CLASS vendor () const;

    /**
     * @brief profile
     * @return platform profile
     */
    const cl::STRING_CLASS profile () const;

    /**
     * @brief version
     * @return platform version
     */
    const cl::STRING_CLASS version () const;

    ~ClPlatform();

protected:
    /**
     * @brief queuryInfo_
     * @param platformInfo
     * @return info relted to specific platform
     */
    virtual const cl::STRING_CLASS queuryInfo_ (cl::Platform platform,
                                                cl_platform_info platformInfo) const;

private:
    /**
     *  re-declaration to make it easy to use
     */
    using platformVector = VECTOR_CLASS <cl::Platform>;

    /**
     *  re-declaration to make it easy to use
     */
    using platformPtr = std::shared_ptr<platformVector>;

protected:
    /**
     * @brief smart pointer to platforms vector class
     */
    platformPtr platforms_ = std::make_shared<platformVector>();
};

}

#endif

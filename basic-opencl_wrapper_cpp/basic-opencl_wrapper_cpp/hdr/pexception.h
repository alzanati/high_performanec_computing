#ifndef P_EXCEPTION_H
#define P_EXCEPTION_H

#include <opencl-common.hpp>
#include <map>

namespace exceptions {
class ClException {
public:
    /**
     * @brief ClException
     * @param err
     */
    ClException (const int& err)
        : errCode_(err) {
        errorMap_.insert(paired(CL_INVALID_CONTEXT, "CL_INVALID_CONTEXT"));
        errorMap_.insert(paired(CL_INVALID_VALUE, "CL_INVALID_VALUE"));
        errorMap_.insert(paired(CL_INVALID_DEVICE, "CL_INVALID_DEVICE"));
        errorMap_.insert(paired(CL_INVALID_BINARY, "CL_INVALID_BINARY"));
        errorMap_.insert(paired(CL_OUT_OF_RESOURCES, "CL_OUT_OF_RESOURCES"));
        errorMap_.insert(paired(CL_OUT_OF_HOST_MEMORY, "CL_OUT_OF_HOST_MEMORY"));
        errorMap_.insert(paired(CL_DEVICE_NOT_FOUND, "CL_DEVICE_NOT_AVAILABLE"));
        errorMap_.insert(paired(CL_COMPILER_NOT_AVAILABLE, "CL_COMPILER_NOT_AVAILABLE"));
        errorMap_.insert(paired(CL_MEM_OBJECT_ALLOCATION_FAILURE, "CL_MEM_OBJECT_ALLOCATION_FAILURE"));
        errorMap_.insert(paired(CL_OUT_OF_RESOURCES , "CL_OUT_OF_RESOURCES"));
        errorMap_.insert(paired(CL_DEVICE_NOT_FOUND, "CL_DEVICE_NOT_FOUND"));
        errorMap_.insert(paired(CL_PROFILING_INFO_NOT_AVAILABLE, "CL_PROFILING_INFO_NOT_AVAILABLE"));
        errorMap_.insert(paired(CL_MEM_COPY_OVERLAP, "CL_MEM_COPY_OVERLAP"));
        errorMap_.insert(paired(CL_IMAGE_FORMAT_MISMATCH, "CL_IMAGE_FORMAT_MISMATCH"));
        errorMap_.insert(paired(CL_IMAGE_FORMAT_NOT_SUPPORTED, "CL_IMAGE_FORMAT_NOT_SUPPORTED"));
        errorMap_.insert(paired(CL_BUILD_PROGRAM_FAILURE , "CL_BUILD_PROGRAM_FAILURE"));
        errorMap_.insert(paired(CL_MAP_FAILURE, "CL_MAP_FAILURE"));
        errorMap_.insert(paired(CL_MISALIGNED_SUB_BUFFER_OFFSET , "CL_MISALIGNED_SUB_BUFFER_OFFSET"));
        errorMap_.insert(paired(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, "CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST"));
        errorMap_.insert(paired(CL_COMPILE_PROGRAM_FAILURE, "CL_COMPILE_PROGRAM_FAILURE"));
        errorMap_.insert(paired(CL_MAP_FAILURE, "CL_MAP_FAILURE"));
        errorMap_.insert(paired(CL_LINKER_NOT_AVAILABLE, "CL_LINKER_NOT_AVAILABLE"));
        errorMap_.insert(paired(CL_LINK_PROGRAM_FAILURE, "CL_LINK_PROGRAM_FAILURE"));
        errorMap_.insert(paired(CL_DEVICE_PARTITION_FAILED, "CL_DEVICE_PARTITION_FAILED"));
        errorMap_.insert(paired(CL_KERNEL_ARG_INFO_NOT_AVAILABLE , "CL_KERNEL_ARG_INFO_NOT_AVAILABLE"));
        errorMap_.insert(paired(CL_INVALID_VALUE, "CL_INVALID_VALUE"));
        errorMap_.insert(paired(CL_INVALID_DEVICE_TYPE, "CL_INVALID_DEVICE_TYPE"));
        errorMap_.insert(paired(CL_INVALID_PLATFORM , "CL_INVALID_PLATFORM"));
        errorMap_.insert(paired(CL_INVALID_DEVICE , "CL_INVALID_DEVICE"));
        errorMap_.insert(paired(CL_INVALID_CONTEXT, "CL_INVALID_CONTEXT"));
        errorMap_.insert(paired(CL_INVALID_QUEUE_PROPERTIES, "CL_INVALID_QUEUE_PROPERTIES"));
        errorMap_.insert(paired(CL_INVALID_COMMAND_QUEUE, "CL_INVALID_COMMAND_QUEUE"));
        errorMap_.insert(paired(CL_INVALID_HOST_PTR, "CL_INVALID_HOST_PTR"));
        errorMap_.insert(paired(CL_INVALID_MEM_OBJECT, "CL_INVALID_MEM_OBJECT"));
        errorMap_.insert(paired(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR, "CL_INVALID_IMAGE_FORMAT_DESCRIPTOR"));
        errorMap_.insert(paired(CL_INVALID_IMAGE_SIZE, "CL_INVALID_IMAGE_SIZE"));
        errorMap_.insert(paired(CL_INVALID_SAMPLER, "CL_INVALID_SAMPLER"));
        errorMap_.insert(paired(CL_INVALID_BINARY , "CL_INVALID_BINARY"));
        errorMap_.insert(paired(CL_INVALID_BUILD_OPTIONS, "CL_INVALID_BUILD_OPTIONS"));
        errorMap_.insert(paired(CL_INVALID_PROGRAM, "CL_INVALID_PROGRAM"));
        errorMap_.insert(paired(CL_INVALID_PROGRAM_EXECUTABLE, "CL_INVALID_PROGRAM_EXECUTABLE"));
        errorMap_.insert(paired(CL_INVALID_KERNEL_NAME , "CL_INVALID_KERNEL_NAME"));
        errorMap_.insert(paired(CL_INVALID_KERNEL_DEFINITION , "CL_INVALID_KERNEL_DEFINITION"));
        errorMap_.insert(paired(CL_INVALID_KERNEL, "CL_INVALID_KERNEL"));
        errorMap_.insert(paired(CL_INVALID_ARG_INDEX , "CL_INVALID_ARG_INDEX"));
        errorMap_.insert(paired(CL_INVALID_ARG_VALUE, "CL_INVALID_ARG_VALUE"));
        errorMap_.insert(paired(CL_INVALID_ARG_SIZE, "CL_INVALID_ARG_SIZE"));
        errorMap_.insert(paired(CL_INVALID_KERNEL_ARGS, "CL_INVALID_KERNEL_ARGS"));
        errorMap_.insert(paired(CL_INVALID_WORK_DIMENSION, "CL_INVALID_WORK_DIMENSION"));
        errorMap_.insert(paired(CL_INVALID_WORK_GROUP_SIZE, "CL_INVALID_WORK_GROUP_SIZE"));
        errorMap_.insert(paired(CL_INVALID_WORK_ITEM_SIZE, "CL_INVALID_WORK_ITEM_SIZE"));
        errorMap_.insert(paired(CL_INVALID_GLOBAL_OFFSET , "CL_INVALID_GLOBAL_OFFSET"));
        errorMap_.insert(paired(CL_INVALID_EVENT_WAIT_LIST, "CL_INVALID_EVENT_WAIT_LIST"));
        errorMap_.insert(paired(CL_INVALID_EVENT, "CL_INVALID_EVENT"));
        errorMap_.insert(paired(CL_INVALID_OPERATION , "CL_INVALID_OPERATION"));
        errorMap_.insert(paired(CL_INVALID_GL_OBJECT , "CL_INVALID_GL_OBJECT"));
        errorMap_.insert(paired(CL_INVALID_BUFFER_SIZE, "CL_INVALID_BUFFER_SIZE"));
        errorMap_.insert(paired(CL_INVALID_MIP_LEVEL, "CL_INVALID_MIP_LEVEL"));
        errorMap_.insert(paired(CL_INVALID_GLOBAL_WORK_SIZE, "CL_INVALID_GLOBAL_WORK_SIZE"));
        errorMap_.insert(paired(CL_INVALID_PROPERTY, "CL_INVALID_PROPERTY"));
        errorMap_.insert(paired(CL_INVALID_COMPILER_OPTIONS, "CL_INVALID_COMPILER_OPTIONS"));
        errorMap_.insert(paired(CL_INVALID_LINKER_OPTIONS, "CL_INVALID_LINKER_OPTIONS"));
        errorMap_.insert(paired(CL_INVALID_DEVICE_PARTITION_COUNT, "CL_INVALID_DEVICE_PARTITION_COUNT"));
    }
    /**
     * @brief errCode
     * @return error code
     */
    const int errCode() const { return errorMap_.find(errCode_)->first; }

    /**
     * @brief message
     * @return error message
     */
    const char* message() const { return errorMap_.find(errCode_)->second; }

private:
    /**
     * @brief exceptionName_
     */
    const char* exceptionName_;
    /**
     * @brief errCode_
     */
    int errCode_;
    /**
     * @brief errorMap_
     */
    std::map<const int, const char*> errorMap_;
    /**
     * @brief paired
     */
    typedef std::pair<const int, const char*> paired;
};
}

#endif

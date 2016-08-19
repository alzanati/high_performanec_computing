/* this kernel is used for multiplications but allocate redunant work items*/
__kernel void mat_multi (int dim,
                         __global int *A,
                         __global int *B,
                         __global int *C) {

    int indxRow = get_global_id(0);
    int indxCol = get_global_id(1);
    int tmpResult = 0;
    for (int i = 0; i < dim; ++i) {
        tmpResult += A[indxRow * dim + i] * B[indxCol + i * dim];
    }
    C[indxRow * dim + indxCol] = tmpResult;
}

/* this kernel is used for multiplications but only width of matrix as work items*/
__kernel void mat_multi_opt (int dim,
                             __global int *A,
                             __global int *B,
                             __global int*C) {

    int indx = get_global_id(0);
    for (int j = 0; j < dim; ++j) {
        int tmpResult = 0;
        for (int i = 0; i < dim; ++i) {
            tmpResult += A[indx * dim + i] * B[j + i * dim];
        }
        C[indx * dim + j] = tmpResult;
    }
}

/* this kernel is used for multiplications but with register tilling */
__kernel void mat_mutli_tilling (int dim,
                                 __global int *A,
                                 __global int *B,
                                 __global int *C) {

    int indx = get_global_id(0);
    int tmpData[1024];
    int tmpResult = 0;
    for (int i = 0; i < dim; i++) {
        tmpData[i] = A[indx * dim + i];
    }
    for (int j = 0; j < dim; j++) {
        tmpResult = 0;
        for (int i = 0; i < dim; i++) {
            tmpResult += tmpData[i] * B[dim * i + j];
        }
        C[indx * dim + j] = tmpResult;
    }
}

__kernel void mat_multi_shared (int dim,
                                __global int *A,
                                __global int *B,
                                __global int *C,
                                __local int *shared) {

    int indx = get_global_id(0);
    int lindx = get_local_id(0);
    int size = get_local_size(0);
    int tmpData[1024];
    int tmpResult = 0;

    // register tilling
    for (int i = 0; i < dim; i++) {
        tmpData[i] = A[indx * dim + i];
    }

    // fetch shared data
    for(int i = 0; i < dim; i++) {
        int localIndx = i * dim + lindx;
        shared[localIndx] = B[localIndx];
    }
    // this block operation is used to wirte all data to shared memory
    // so if work item need to access data the data will be shared between all work items
    barrier(CLK_LOCAL_MEM_FENCE);

    for (int j = 0; j < dim; j++) {
        tmpResult = 0;
        for (int i = 0; i < dim; i++) {
            tmpResult += tmpData[i] * shared[i * dim + j];
        }
        C[indx * dim + j] = tmpResult;
    }
}

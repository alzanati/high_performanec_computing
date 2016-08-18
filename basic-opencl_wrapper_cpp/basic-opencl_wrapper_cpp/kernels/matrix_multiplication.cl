/* this kernel is used for multiplications but allocate redunant work items*/
__kernel void mat_multi
(int dim, __global *A, __global *B, __global *C) {

    int indxRow = get_global_id(0);
    int indxCol = get_global_id(1);
    int tmpResult = 0;
    for (int i = 0; i < dim; ++i) {
        tmpResult += A[indxRow * dim + i] * B[indxCol + i * dim];
    }
    C[indxRow * dim + indxCol] = tmpResult;
}

/* this kernel is used for multiplications but only width of matrix as work items*/
__kernel void mat_multi_opt
(int dim, __global *A, __global *B, __global *C) {

    int indx = get_global_id(0);
    for (int j = 0; j < dim; ++j) {
        int tmpResult = 0;
        for (int i = 0; i < dim; ++i) {
            tmpResult += A[indx * dim + i] * B[j + i * dim];
        }
        C[indx * dim + j] = tmpResult;
    }
}


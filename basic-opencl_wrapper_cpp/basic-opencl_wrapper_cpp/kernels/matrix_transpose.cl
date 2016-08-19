__kernel void matrix_transpose
(int width, int height, __global *A, __global *C) {
    int indx = get_global_id(0);
    for (int i = 0; i < width; i++) {
        C[i * height + indx] = A[indx * height + i];
    }
}

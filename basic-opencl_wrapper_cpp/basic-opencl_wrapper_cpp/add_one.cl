__kernel void add_one (__global int* A, __global int* B, global int* C)
{
	int index = get_global_id( 0 );
        C[index] = A[index] + B[index];
}

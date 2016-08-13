__kernel void add_one( __global float* buffer )
{
	int index = get_global_id( 0 );
	buffer[ index ] = index;
}

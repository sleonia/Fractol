__kernel void test(__global float const *arr_x,
					__global float const *arr_y,
					int const *repeats,
					__global int *res)
{
	unsigned int i = get_global_id(0);	

	float x = arr_x[i];
	float y = arr_y[i];
	int n = 0;

	while (x * x + y * y <= 4 && n < repeats)
	{
		float temp = x * x - y - y + arr_x[i];
		y = 2 * x * y + arr_y[i];
		x = temp;
		n++;
	}
	res[i] = x * x + y * y <= 4 ? -1 : n;
}

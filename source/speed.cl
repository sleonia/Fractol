__kernel void fractol(__global int *res
						// int   color,
						// int   height,
						// int   width,
						// float max_y,
						// float min_x,
						// float shift_x,
						// float shift_y,
						// float move_x,
						// float move_y
						)
{
	int pixel = get_global_id(0);
	res[pixel] = 0;
}

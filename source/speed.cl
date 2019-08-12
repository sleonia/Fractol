int color(int i, int color_key, int fractol)
{
	int n = i;
	int s = 100;

	if (color_key == 0)
		return (((n * 255 / s) << 16) + ((n * 255 / s) << 16) + n * 255 / s);
	else if (color_key == 1)
		return (((n * 255 / s) << 16) + ((n * 255 / s) << 8) + n * 255 / s);
	return (((n * 255 / s) << 16) + ((n * 255 / s) << 8) + n * 255 / s);
}

__kernel void fractol(	__global int	*data,
						__global int	*i_arg,
						__global float	*f_arg)
{
	int			x;
	int			y;
	int			i;
	double		start_x;
	double		start_y;
	double		new_x;
	double		new_y;
	double		sqr_x;
	double		sqr_y;

	int pixel = get_global_id(0);
	y = pixel / i_arg[1];
	x = pixel % i_arg[1];
	i = -1;
	start_y = f_arg[0] - y * f_arg[2] - f_arg[4];
	start_x = f_arg[1] + x * f_arg[3] - f_arg[5];
	new_x = start_x;
	new_y = start_y;
	sqr_x = 0.0;
	sqr_y = 0.0;
	while ((sqr_x + sqr_y <= 4) && (i < i_arg[3]))
	{
		sqr_x = new_x * new_x;
		sqr_y = new_y * new_y;
		new_y = 2 * new_x * new_y + start_y;
		new_x = sqr_x - sqr_y + start_x;
		++i;
	}
	if (i == i_arg[3])
		data[pixel] = 0x0;
	else
		data[pixel] = color(i, i_arg[4], i_arg[2]);
}

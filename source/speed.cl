# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define ABS(a)(a <= 0.0) ? -a : a
# define SQR(n) n * n

int color(int i, int color_key, int fractol)
{
	int n = i;
	int s = 100;

	if (color_key == 0)
		return (((n * 255 / s) << 8) + ((n * 255 / s) << 8) + n * 255 / s);
	if (color_key == 1)
		return (((n * 255 / 10) << 16) + ((n * 255 / 10) << 8) + n * 25 / 10);
	if (color_key == 2)
		return (((n * 255 / 40) << 16) + ((n * 255 / 10) << 8) + n * 255 / 300);
	if (color_key == 3)
		return (RGB((115.5 *  0.6 *(n) + 1), (125.5 *  0.4 *(n) + 1), (94.5 * (1 - 0.1 * (n)))));
	if (color_key == 4)
		return (((n * 56 / s) << 8) + ((n * 255 / s) << 16) + n * 145 / s);
	if (color_key == 5)
		return (RGB((75.5 *  0.1 *(n) + 1), (125.5 *  0.1 *(n) + 1), (34.5 * (1 - 0.1 * (n)))));
	if (color_key == 6)
		return (((n * 255 / s) << 2) + ((n * 255 / s) << 16) + n * 255 / s);
	if (color_key == 7)
		return (RGB((127.5 *  0.4 *(n) + 1), (127.5 *  0.1 *(n) + 1), (127.5 * (1 - 0.7 * (n)))));
	if (color_key == 8)
		return (RGB((127.5 *  0.1 *(n) + 1), (127.5 *  0.2 *(n) + 1), (127.5 * (1 - 0.1 * (n)))));
}

__kernel void fractol(	__global int	*data,
						__global int	*i_arg,
						__global double	*f_arg)
{
	int			x;
	int			y;
	int			i;
	double		tmp;
	double		start_x;
	double		start_y;
	double		new_x;
	double		new_y;

	int pixel = get_global_id(0);
	y = pixel / i_arg[1];
	x = pixel % i_arg[1];
	i = -1;
	start_y = f_arg[0] - y * f_arg[2] - f_arg[4];
	start_x = f_arg[1] + x * f_arg[3] - f_arg[5];
	new_x = start_x;
	new_y = start_y;
	while ((SQR(new_x) + SQR(new_y) < 4) && (i < i_arg[3]))
	{
		if (i_arg[2] == 0)
		{
			tmp = SQR(new_x) - SQR(new_y) + start_x;
			new_y = 2 * new_x * new_y + start_y;
			new_x = tmp;
		}
		if (i_arg[2] == 1)
		{
			//
		}
		if (i_arg[2] == 2)
		{
			tmp = SQR(new_x) - SQR(new_y) - start_x;
			new_y = 2 * ABS(new_x * new_y) - start_y;
			new_x = ABS(tmp);
		}
		++i;
	}
	if (i == i_arg[3])
		data[pixel] = 0x0;
	else
		// data[pixel] = 0xFFF * i_arg[2];
		data[pixel] = color(i, i_arg[4], i_arg[2]);
}

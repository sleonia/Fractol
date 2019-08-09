__kernel void fractol(__global int	*res,
						int			hight,
						int			width,
						short int	key,
						int			color,
						double		max_y,
						double		min_x,
						double		shift_x,
						double		shift_y,
						double		move_x,
						double		move_y,
						int			repeats
						)
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
	y = pixel / width;
	x = pixel % width;
	i = -1;
	start_y = max_y - y * shift_y - move_y;
	start_x = min_x + x * shift_x - move_x;
	new_x = start_x;
	new_y = start_y;
	sqr_x = 0.0;
	sqr_y = 0.0;
	while (i < repeats)
	{
		sqr_x = new_x * new_x;
		sqr_y = new_y * new_y;
		new_y = 2 * new_x * new_y + start_y;
		new_x = sqr_x - sqr_y + start_x;
		++i;
	}
	if (sqr_x + sqr_y < 4.0)
		res[pixel] = 0;
	else
		res[pixel] = color;
}

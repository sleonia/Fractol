/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:17:45 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/28 23:52:26 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			calculate_cmplx(int x, int y, t_fractol *fractol)
{
	int				i;

	i = 0;
	fractol->cmplx->key = 0;
	fractol->cmplx->z_x = fractol->cmplx->c_x;
	fractol->cmplx->z_y = fractol->cmplx->c_y;
	while (i < fractol->crdn->repeats)
	{
		fractol->cmplx->sqr_z_x = fractol->cmplx->z_x * fractol->cmplx->z_x;
		fractol->cmplx->sqr_z_y = fractol->cmplx->z_y * fractol->cmplx->z_y;
		if (fractol->cmplx->sqr_z_x + fractol->cmplx->sqr_z_y > 4)
		{
			fractol->cmplx->key = 1;
			break ;
		}
		fractol->cmplx->z_y = 2 * fractol->cmplx->z_x * \
					fractol->cmplx->z_y + fractol->cmplx->c_y;
		fractol->cmplx->z_x = fractol->cmplx->sqr_z_x - \
					fractol->cmplx->sqr_z_y + fractol->cmplx->c_x;
		i++;
	}
	if (fractol->cmplx->key == 1)
		main_draw(x, y, fractol);
}

void				mandelbrot(t_fractol *fractol)
{
	int				x;
	int				y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		fractol->cmplx->c_y = fractol->crdn->max_x - y * \
				fractol->crdn->shift_y + fractol->crdn->move_y;
		while (x < WIDTH)
		{
			fractol->cmplx->c_x = fractol->crdn->min_x + x * \
				fractol->crdn->shift_x + fractol->crdn->move_x;
			calculate_cmplx(x, y, fractol);
			x++;
		}
		y++;
	}
}

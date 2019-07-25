/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:17:45 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/25 18:23:52 by sleonia          ###   ########.fr       */
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
	while (i < REPEATS)
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
		main_drow(x, y, fractol);
}

void				mandelbrot(t_fractol *fractol)
{
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		fractol->cmplx->c_y = MAX_Y - y * SHIFT_Y;
		while (x < WIDTH)
		{
			fractol->cmplx->c_x = MIN_X + x * SHIFT_X;
			calculate_cmplx(x, y, fractol);
			x++;
		}
		y++;
	}
}

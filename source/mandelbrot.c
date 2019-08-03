/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:17:45 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/03 11:16:33 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			calculate_cmplx(int x, int y, t_fractol *fractol)
{
	int				i;
	int				key;

	i = 0;
	key = 0;
	fractol->cmplx->new_x = fractol->cmplx->start_x;
	fractol->cmplx->new_y = fractol->cmplx->start_y;
	while (i < fractol->cmplx->repeats)
	{
		fractol->cmplx->sqr_x = fractol->cmplx->new_x * fractol->cmplx->new_x;
		fractol->cmplx->sqr_y = fractol->cmplx->new_y * fractol->cmplx->new_y;
		if (fractol->cmplx->sqr_x + fractol->cmplx->sqr_y > 4)
		{
			key = 1;
			break ;
		}
		fractol->cmplx->new_y = 2 * fractol->cmplx->new_x * \
							fractol->cmplx->new_y + fractol->cmplx->start_y;
		fractol->cmplx->new_x = fractol->cmplx->sqr_x - \
							fractol->cmplx->sqr_y + fractol->cmplx->start_x;
		i++;
	}
	if (key == 1)
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
		fractol->cmplx->start_y = fractol->crdn->max_y - y * fractol->crdn->shift_y - fractol->crdn->move_y;
		while (x < WIDTH)
		{
			fractol->cmplx->start_x = fractol->crdn->min_x + x * fractol->crdn->shift_x - fractol->crdn->move_x;
			calculate_cmplx(x, y, fractol);
			x++;
		}
		y++;
	}
}

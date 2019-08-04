/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:17:45 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/04 06:40:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			calculate_cmplx(int x, int y, t_fractol *f)
{
	int				i;
	int				key;

	i = 0;
	key = 0;
	f->cmplx->new_x = f->cmplx->start_x;
	f->cmplx->new_y = f->cmplx->start_y;
	while (i < f->cmplx->repeats)
	{
		f->cmplx->sqr_x = f->cmplx->new_x * f->cmplx->new_x;
		f->cmplx->sqr_y = f->cmplx->new_y * f->cmplx->new_y;
		if (f->cmplx->sqr_x + f->cmplx->sqr_y > 4)
		{
			key = 1;
			break ;
		}
		f->cmplx->new_y = 2 * f->cmplx->new_x * \
							f->cmplx->new_y + f->cmplx->start_y;
		f->cmplx->new_x = f->cmplx->sqr_x - \
							f->cmplx->sqr_y + f->cmplx->start_x;
		i++;
	}
	if (key == 1)
		main_draw(x, y, f);
}

void				mandelbrot(t_fractol *f)
{
	int				x;
	int				y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		f->cmplx->start_y = f->crdn->max_y - y * f->crdn->shift_y - f->crdn->move_y;
		while (x < WIDTH)
		{
			f->cmplx->start_x = f->crdn->min_x + x * f->crdn->shift_x - f->crdn->move_x;
			calculate_cmplx(x, y, f);
			x++;
		}
		y++;
	}
}

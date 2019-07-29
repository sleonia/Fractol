/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:09:30 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/29 07:06:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_pixel(int x, int y, int color, t_fractol *fractol)
{
	fractol->mlx->data[y * WIDTH + x] = color;
}

void				gradient(int x, int y, t_fractol *fractol)
{
	double			percent;

	if (x <= 600)
	{
		percent = (double)x / 600.0;
		put_pixel(x, y, (int)fractol->color * percent, fractol);
	}
	if (x > 600 && x <= 1200)
	{
		percent = (double)x / 100;
		put_pixel(x, y, fractol->color * percent, fractol);
	}
}

void				fill_backgound(int color, t_fractol *fractol)
{
	int				x;
	int				y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			gradient(x, y, fractol);
			// put_pixel(x, y, color, fractol);
			x++;
		}
		y++;
	}
}


void				main_draw(int x, int y, t_fractol *fractol)
{
	if  (fractol->color != 1)
		gradient(x, y, fractol);
		// put_pixel(x, y, fractol->color, fractol);
	if  (fractol->color >= 1 && fractol->color <= 4)
		drow_strips(x, y, fractol);
}

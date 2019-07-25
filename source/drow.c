/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:09:30 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/25 20:12:41 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_pixel(int x, int y, int color, t_fractol *fractol)
{
	fractol->mlx->data[y * WIDTH + x] = color;
}

void				fill_backgound(int color, t_fractol *fractol)
{
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, color, fractol);
			x++;
		}
		y++;
	}
}

// void				gradient()

void				main_drow(int x, int y, t_fractol *fractol)
{
	if  (fractol->color != 1)
		put_pixel(x, y, fractol->color, fractol);
	if  (fractol->color >= 1 && fractol->color <= 4)
		drow_strips(x, y, fractol);
}

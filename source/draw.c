/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:09:30 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/04 06:42:29 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_pixel(int x, int y, int color, t_fractol *f)
{
	f->mlx->data[y * WIDTH + x] = color;
}

void				fill_backgound(int color, t_fractol *f)
{
	int				x;
	int				y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, color, f);
			x++;
		}
		y++;
	}
}

void				main_draw(int x, int y, t_fractol *f)
{
	if (f->color != 1)
		put_pixel(x, y, f->color, f);
	if (f->color >= 1 && f->color <= 4)
		drow_strips(x, y, f);
}

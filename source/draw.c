/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:09:30 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/26 21:59:01 by sleonia          ###   ########.fr       */
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
	while (y < HIGHT)
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

void				main_draw(int x, int y, t_fractol *fractol)
{
	if  (fractol->color != 1)
		put_pixel(x, y, fractol->color, fractol);
	if  (fractol->color >= 1 && fractol->color <= 4)
		drow_strips(x, y, fractol);
}

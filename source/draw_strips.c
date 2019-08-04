/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_strips.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:57:21 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/04 06:43:13 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			vertical_strips(int x, int y, t_fractol *f)
{
	int				location_x;

	location_x = x / X_STEP;
	if (location_x % 5 == 0)
		put_pixel(x, y, 0x37FF02, f);
	else if (location_x % 5 == 1)
		put_pixel(x, y, 0xFF1E00, f);
	else if (location_x % 5 == 2)
		put_pixel(x, y, 0x114DD5, f);
	else if (location_x % 5 == 3)
		put_pixel(x, y, 0xFFFF00, f);
	else if (location_x % 5 == 4)
		put_pixel(x, y, 0xFF00FF, f);
}

static void			horizontal_strips(int x, int y, t_fractol *f)
{
	int				location_y;

	location_y = y / Y_STEP;
	if (location_y % 5 == 0)
		put_pixel(x, y, 0x37FF02, f);
	else if (location_y % 5 == 1)
		put_pixel(x, y, 0xFF1E00, f);
	else if (location_y % 5 == 2)
		put_pixel(x, y, 0x114DD5, f);
	else if (location_y % 5 == 3)
		put_pixel(x, y, 0xFFFF00, f);
	else if (location_y % 5 == 4)
		put_pixel(x, y, 0xFF00FF, f);
}

static void			random_strips(int x, int y, t_fractol *f)
{
	int				location_x;
	int				location_y;

	location_x = x / X_STEP;
	location_y = y / Y_STEP;
	if (location_y % 5 == 0 && location_x % 5 == 0)
		put_pixel(x, y, 0xFF00FF, f);
	else if (location_y % 5 == 1 && location_x % 5 == 1)
		put_pixel(x, y, 0x37FF02, f);
	else if (location_y % 5 == 2 && location_x % 5 == 2)
		put_pixel(x, y, 0x114DD5, f);
	else if (location_y % 5 == 3 || location_x % 5 == 3)
		put_pixel(x, y, 0xFF1E00, f);
	else if (location_y % 5 == 4 || location_x % 5 == 4)
		put_pixel(x, y, 0xFFFF00, f);
}

void				drow_strips(int x, int y, t_fractol *f)
{
	if (f->color == 1)
		vertical_strips(x, y, f);
	if (f->color == 2)
		horizontal_strips(x, y, f);
	if (f->color == 3)
		random_strips(x, y, f);
}

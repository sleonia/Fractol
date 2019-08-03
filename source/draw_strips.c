/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strips.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:57:21 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/26 19:34:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			vertical_strips(int x, int y, t_fractol *fractol)
{
	int				location_x;

	location_x = x / X_STEP;
	if (location_x % 5 == 0)
		put_pixel(x, y, 0x37FF02, fractol);
	else if (location_x % 5 == 1)
		put_pixel(x, y, 0xFF1E00, fractol);
	else if (location_x % 5 == 2)
		put_pixel(x, y, 0x114DD5, fractol);
	else if (location_x % 5 == 3)
		put_pixel(x, y, 0xFFFF00, fractol);
	else if (location_x % 5 == 4)
		put_pixel(x, y, 0xFF00FF, fractol);
}

static void			horizontal_strips(int x, int y, t_fractol *fractol)
{
	int				location_y;

	location_y = y / Y_STEP;
	if (location_y % 5 == 0)
		put_pixel(x, y, 0x37FF02, fractol);
	else if (location_y % 5 == 1)
		put_pixel(x, y, 0xFF1E00, fractol);
	else if (location_y % 5 == 2)
		put_pixel(x, y, 0x114DD5, fractol);
	else if (location_y % 5 == 3)
		put_pixel(x, y, 0xFFFF00, fractol);
	else if (location_y % 5 == 4)
		put_pixel(x, y, 0xFF00FF, fractol);
}

static void			random_strips(int x, int y, t_fractol *fractol)
{
	int				location_x;
	int				location_y;

	location_x = x / X_STEP;
	location_y = y / Y_STEP;
	if (location_y % 5 == 0 && location_x % 5 == 0)
		put_pixel(x, y, 0xFF00FF, fractol);
	else if (location_y % 5 == 1 && location_x % 5 == 1)
		put_pixel(x, y, 0x37FF02, fractol);
	else if (location_y % 5 == 2 && location_x % 5 == 2)
		put_pixel(x, y, 0x114DD5, fractol);
	else if (location_y % 5 == 3 || location_x % 5 == 3)
		put_pixel(x, y, 0xFF1E00, fractol);
	else if (location_y % 5 == 4 || location_x % 5 == 4)
		put_pixel(x, y, 0xFFFF00, fractol);
}

void				drow_strips(int x, int y, t_fractol *fractol)
{
	if (fractol->color == 1)
		vertical_strips(x, y, fractol);
	if (fractol->color == 2)
		horizontal_strips(x, y, fractol);
	if (fractol->color == 3)
		random_strips(x, y, fractol);
}

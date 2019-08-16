/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:19:59 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/16 20:39:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_move(int x, int y, t_fractol *f)
{
	f->crdn->rotation_y = (y + f->crdn->shift_y) / (double)f->hight;
	f->crdn->rotation_x = (x + f->crdn->shift_x) / (double)f->width;
	run_fractol(f);
	return (0);
}

int					mouse_press(int button, int x, int y, t_fractol *f)
{
	if (button == 1)
	{
		if ((x >= 10 && x <= 110) && (y >= 230 && y <= 250))
			f->fractol = 0;
		if ((x >= 10 && x <= 60) && (y >= 255 && y <= 280))
			f->fractol = 1;
		if ((x >= 10 && x <= 131) && (y >= 285 && y <= 305))
			f->fractol = 2;
		if ((x >= 10 && x <= 70) && (y >= 310 && y <= 330))
			f->fractol = 3;
		if ((x >= 10 && x <= 70) && (y >= 335 && y <= 355))
			f->fractol = 4;
		if ((x >= 10 && x <= 70) && (y >= 360 && y <= 380))
			f->fractol = 5;
		if ((x >= 8 && x <= 183) && (y >= 385 && y <= 403))
			f->fractol = 6;
	}
	default_value(f);
	run_fractol(f);
	return (0);
}

int					mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == 4)
		zoom(MINUS, f);
	if (keycode == 5)
	{
		if (y < f->hight / 2)
			f->crdn->move_y -= (f->crdn->max_y - f->crdn->min_y) / 0.1;
		if (y > f->hight / 2)
			f->crdn->move_y += (f->crdn->max_y - f->crdn->min_y) / 0.1;
		if (x < f->width / 2 + 200)
			f->crdn->move_x += (f->crdn->max_x - f->crdn->min_x) / 0.1;
		if (x > f->width / 2 + 200)
			f->crdn->move_x -= (f->crdn->max_x - f->crdn->min_x) / 0.1;
		zoom(PLUS, f);
	}
	fill_struct(f);
	run_fractol(f);
	return (0);
}

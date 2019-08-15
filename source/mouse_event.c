/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:19:59 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/15 20:51:26 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_move(int x, int y, t_fractol *f)
{
	// zoom(PLUS, f);
	// if (y < f->hight / 2)
	// 	f->crdn->move_y -= (f->crdn->max_y - f->crdn->min_y) / 0.1;
	// if (y > f->hight / 2)
	// 	f->crdn->move_y += (f->crdn->max_y - f->crdn->min_y) / 0.1;
	// if (x < f->width / 2)
	// 	f->crdn->move_x += (f->crdn->max_x - f->crdn->min_x) / 0.1;
	// if (x > f->width / 2)
	// 	f->crdn->move_x -= (f->crdn->max_x - f->crdn->min_x) / 0.1;
	// if (f->move_flag == 0)
	// {
		
	// 	// f->crdn->rotation_y = ((double)y - 100) / 500;
	// 	// f->crdn->rotation_x = ((double)x - 2000) / 500;
	// 	f->crdn->rotation_y = (double)y / (double)f->hight;
	// 	f->crdn->rotation_x = (double)x / (double)f->width;
	// printf("%f  %f\n", f->crdn->rotation_x, f->crdn->rotation_y);
	// }
	f->move_flag = 0;
	run_fractol(f);
	return (0);
}

int					mouse_press(int button, int x, int y, t_fractol *f)
{
	// printf("%d  %d\n", x, y);
	if (button == 1)
	{
		if ((x >= 10 && x <= 110) && (y >= 230 && y <= 250))
			f->fractol = 0;
		if ((x >= 10 && x <= 60) && (y >= 255 && y <= 280))
			f->fractol = 1;
		if ((x >= 10 && x <= 131) && (y >= 285 && y <= 305))
			f->fractol = 2;
		if ((x >= 10 && x <= 100) && (y >= 310 && y <= 330))
			f->fractol = 3;
		// if ((x >= 10 && x <= 250) && (y >= 235 && y <= 252))
		// 	f->fractol = 4;
		// if ((x >= 10 && x <= 250) && (y >= 235 && y <= 252))
		// 	f->fractol = 5;
	}
	if (button == 2)
		f->move_flag = f->move_flag == 0 ? 1 : 0;
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
		if (x < f->width / 2 + 180)
			f->crdn->move_x += (f->crdn->max_x - f->crdn->min_x) / 0.1;
		if (x > f->width / 2 + 180)
			f->crdn->move_x -= (f->crdn->max_x - f->crdn->min_x) / 0.1;
		zoom(PLUS, f);
	}
	fill_struct(f);
	run_fractol(f);
	return (0);
}

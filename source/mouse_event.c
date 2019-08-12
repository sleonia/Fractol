/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:19:59 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 13:05:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_move(int x, int y, t_fractol *f)
{
	if (f->move_flag == 0)
		return (0);
	if (y < 400)
		f->crdn->move_y += 0.01;
	else if (y > 400)
		f->crdn->move_y -= 0.01;
	if (x > 600)
		f->crdn->move_x += 0.01;
	else if (x < 600)
		f->crdn->move_x -= 0.01;
	run_fractol(f);
	return (0);
}

int					mouse_press(int button, int x, int y, t_fractol *f)
{
	if (button == 1)
	{
		zoom(PLUS, f);
		if (y < 400)
			f->crdn->move_y += 0.01;
		if (y > 400)
			f->crdn->move_y -= 0.01;
		if (x > 600)
			f->crdn->move_x += 0.01;
		if (x < 600)
			f->crdn->move_x -= 0.01;
	}
	if (button == 2)
		f->move_flag = f->move_flag == 0 ? 1 : 0;
	run_fractol(f);
	return (0);
}

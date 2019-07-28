/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 16:19:59 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/28 02:43:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_move(int x, int y, t_fractol *fractol)
{
	if (fractol->move_flag == 0)
		return (0);
	if (y < 400)
		fractol->crdn->move_y -= 0.05;
	else if (y > 400)
		fractol->crdn->move_y += 0.05;
	if (x > 600)
		fractol->crdn->move_x -= 0.05;
	else if (x < 600)
		fractol->crdn->move_x += 0.05;
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	change_fractol(fractol);
	fill_backgound(0, fractol);
	return (0);
}

int					mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 1)
	{
		zoom(PLUS, fractol);
		if (y < 400)
			fractol->crdn->move_y += 0.3;
		if (y > 400)
			fractol->crdn->move_y -= 0.3;
		if (x > 600)
			fractol->crdn->move_x += 0.1;
		if (x < 600)
			fractol->crdn->move_x -= 0.1;
	}
	if (button == 2)
		fractol->move_flag = fractol->move_flag == 0 ? 1 : 0;
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	change_fractol(fractol);
	fill_backgound(0, fractol);
	return (0);
}

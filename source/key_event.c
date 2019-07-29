/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:38:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/29 06:07:21 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				zoom(int keycode, t_fractol *fractol)
{
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;

	min_x = fractol->crdn->min_x;
	max_x = fractol->crdn->max_x;
	min_y = fractol->crdn->min_y;
	if (keycode == MINUS)
		fill_crdn(min_x - 0.02, max_x + 0.02, min_y - 0.02, max_y + 0.02, fractol);
	if (keycode == PLUS)
		fill_crdn(min_x + 0.02, max_x - 0.02, min_y + 0.02, max_y - 0.02, fractol);
}

static void			move(int keycode, t_fractol *fractol)
{
	if (keycode == 2)
		fractol->crdn->move_x -= 0.02;
	if (keycode == 0)
		fractol->crdn->move_x += 0.02;
	if (keycode == 1)
		fractol->crdn->move_y += 0.02;
	if (keycode == 13)
		fractol->crdn->move_y -= 0.02;
}

static void			recolor(int keycode, t_fractol *fractol)
{
	if (keycode == 82)
		fractol->color = WHITE;
	else if (keycode == 83)
		fractol->color = BLOOD;
	else if (keycode == 84)
		fractol->color = YELLOW;
	else if (keycode == 85)
		fractol->color = PURPLE;
	else if (keycode == 86)
		fractol->color = BLUE;
	else if (keycode == 87)
		fractol->color = GREEN;
	else if (keycode == 88)
		fractol->color = 1;
	else if (keycode == 89)
		fractol->color = 2;
	else if (keycode == 91)
		fractol->color = 3;
}

int					key_event(int keycode, t_fractol *fractol)
{
	if (keycode == EXIT)
		exit(0);
	if ((keycode >= 82 && keycode <= 89) || keycode == 91)
		recolor(keycode, fractol);
	if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, fractol);
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		move(keycode, fractol);
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	change_fractol(fractol);
	fill_backgound(0, fractol);
	return (0);
}

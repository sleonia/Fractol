/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:38:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/04 06:44:41 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				zoom(int keycode, t_fractol *f)
{
	if (keycode == MINUS)
		return ;
	if (keycode == PLUS)
		return ;
}

static void			move(int keycode, t_fractol *f)
{
	if (keycode == 2)
		f->crdn->move_x -= 0.02;
	if (keycode == 0)
		f->crdn->move_x += 0.02;
	if (keycode == 1)
		f->crdn->move_y += 0.02;
	if (keycode == 13)
		f->crdn->move_y -= 0.02;
}

static void			recolor(int keycode, t_fractol *f)
{
	if (keycode == 82)
		f->color = WHITE;
	else if (keycode == 83)
		f->color = BLOOD;
	else if (keycode == 84)
		f->color = YELLOW;
	else if (keycode == 85)
		f->color = PURPLE;
	else if (keycode == 86)
		f->color = BLUE;
	else if (keycode == 87)
		f->color = GREEN;
	else if (keycode == 88)
		f->color = 1;
	else if (keycode == 89)
		f->color = 2;
	else if (keycode == 91)
		f->color = 3;
}

int					key_event(int keycode, t_fractol *f)
{
	if (keycode == EXIT)
		exit(0);
	if ((keycode >= 82 && keycode <= 89) || keycode == 91)
		recolor(keycode, f);
	if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, f);
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		move(keycode, f);
	mlx_clear_window(f->mlx->ptr, f->mlx->win);
	change_fractol(f);
	fill_backgound(0, f);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:38:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/24 20:21:34 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			recolor(int keycode, t_fractol *fractol)
{
	if (keycode == 83)
		fractol->color = WHITE;
	else if (keycode == 84)
		fractol->color = BLOOD;
	else if (keycode == 85)
		fractol->color = YELLOW;
	else if (keycode == 86)
		fractol->color = PURPLE;
	else if (keycode == 87)
		fractol->color = BLUE;
	else if (keycode == 88)
		fractol->color = GREEN;
}

int					key_event(int keycode, t_fractol *fractol)
{
	if (keycode == EXIT)
		exit(0);
	if (keycode >= 83 && keycode <= 88)
		recolor(keycode, fractol);
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	change_fractol(fractol);
	fill_backgound(0, fractol);
	return (0);
}

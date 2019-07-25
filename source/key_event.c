/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:38:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/25 20:25:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_clear_window(fractol->mlx->ptr, fractol->mlx->win);
	change_fractol(fractol);
	fill_backgound(0, fractol);
	return (0);
}

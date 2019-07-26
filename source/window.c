/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:34:25 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/26 22:30:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			close_window(void *param)
{
	(void)param;
	exit(0);
}

int					create_window(t_fractol *fractol)
{
	if (!(fractol->mlx->ptr = mlx_init()))
		return (delete_struct(3, fractol));
	if (!(fractol->mlx->win = mlx_new_window(fractol->mlx->ptr, \
						WIDTH, HIGHT, "Can you feel it?!")))
		return (delete_struct(3, fractol));
	if (!(fractol->mlx->img = mlx_new_image(fractol->mlx->ptr, WIDTH, HIGHT)))
		return (delete_struct(3, fractol));
	if (!(fractol->mlx->data = (int *)mlx_get_data_addr(fractol->mlx->img, \
		&(fractol->mlx->bpp), &(fractol->mlx->size_l), &(fractol->mlx->endn))))
		return (delete_struct(3, fractol));
	change_fractol(fractol);
	mlx_hook(fractol->mlx->win, 17, 0, close_window, fractol);
	mlx_hook(fractol->mlx->win, 2, 0, key_event, fractol);
	mlx_hook(fractol->mlx->win, 5, 0, mouse_move, fractol);
	mlx_loop(fractol->mlx->ptr);
	return (0);
}

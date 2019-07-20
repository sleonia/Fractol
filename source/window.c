/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:34:25 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/20 13:34:01 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			close_window(void *param)
{
	(void)param;
	exit(0);
}

int					window(t_fractol *fractol)
{
	fractol->mlx->ptr = mlx_init();
	fractol->mlx->win = mlx_new_window(fractol->mlx->ptr, \
						HEIGHT, WIDTH, "Can you fill it?!");
	fractol->mlx->img = mlx_new_image(fractol->mlx->ptr, HEIGHT, WIDTH);
	fractol->mlx->data = mlx_get_data_addr(fractol->mlx->ptr, &(fractol->mlx->bpp), \
							&(fractol->mlx->size_line), &(fractol->mlx->endian));
    //i cant work with fractol->mlx->data. Maybe i must cast it in int.
	mlx_put_image_to_window(fractol->mlx->ptr, fractol->mlx->win, fractol->mlx->img, 0, 0);
	mlx_hook(fractol->mlx->win, 17, 0, close_window, fractol);
	mlx_hook(fractol->mlx->win, 2, 0, key_event, fractol);
	mlx_loop(fractol->mlx->ptr);
	return (0);
}
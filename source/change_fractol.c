/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:09:39 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/29 06:59:44 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				change_fractol(t_fractol *fractol)
{
	// if (fractol->arg == MANDELBROT_KEY)
	// 	mandelbrot(fractol);
	// if (key == JULIA_KEY)
	// 	julia(fractol);
	fill_backgound(0, fractol);
	mlx_put_image_to_window(fractol->mlx->ptr, fractol->mlx->win, \
										fractol->mlx->img, 0, 0);
	fill_backgound(0, fractol);
}

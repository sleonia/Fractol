/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:09:39 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/03 11:57:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				change_fractol(t_fractol *fractol)
{
	if ((fractol->arg ^ MANDELBROT) == 0)
		mandelbrot(fractol);
	if ((fractol->arg ^ JULIA) == 0)
		// julia(fractol);
	mlx_put_image_to_window(fractol->mlx->ptr, fractol->mlx->win, \
										fractol->mlx->img, 0, 0);
	fill_backgound(0, fractol);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:09:39 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/04 07:06:54 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				change_fractol(t_fractol *f)
{
	if ((f->arg ^ MANDELBROT) == 0)
		init(f);
		// mandelbrot(f);
	if ((f->arg ^ JULIA) == 0)
		// julia(fractol);
	mlx_put_image_to_window(f->mlx->ptr, f->mlx->win, f->mlx->img, 0, 0);
	fill_backgound(0, f);
}

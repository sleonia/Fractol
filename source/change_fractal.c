/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:27:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/15 20:50:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void                change_fractal(t_fractol *f)
{
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 200, \
	16737970, "Change fractal:");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 230, \
	65280, "Mandelbrot");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 252, \
	9055202, "Julia");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 280, \
	720895, "Burning Ship");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 305, \
	806806, "Mandelbar");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 330, \
	16777215, " ");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 355, \
	16711680, " ");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 380, \
	50565202, " ");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 405, \
	4567832, " ");
}

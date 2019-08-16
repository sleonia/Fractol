/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:27:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/16 20:28:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				menu_fractal(t_fractol *f)
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
	16711680, "Spider");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 355, \
	50565202, "Celtic Mandelbrot");
	mlx_string_put(f->mlx->ptr, f->mlx->win, 10, 380, \
	0xFFFF00, "Butterfly");
}

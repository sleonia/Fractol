/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:17:45 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/24 09:24:14 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot(t_fractol *fractol)
{
	int A, B = 100, i;
	double a, b, x, y, t, n = 250;
	while (B <= 4 * n)
	{
		b = 2 - (B/n);
		A = 100;
		while (A <= 4 * n)
		{
			a = -2 + (A / n);
			x = 0;
			y = 0;
			i = 1;
			while (i <= 1000)
			{
				t = x;
				x = (x * x) - (y * y) + a;
				y = (2 * t * y) + b;
				if ((x * x) + (y * y) > 4)
					break ;
				i++;
			}
			if (i == 1001)
				put_pixel(A, B,  0xFFFFFF, fractol);
			A++;
		}
		B++;
	}
	return ;
}

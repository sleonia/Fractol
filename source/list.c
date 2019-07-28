/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:55:26 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/28 02:51:57 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					delete_struct(int key, t_fractol *fractol)
{
	if (key == 0 || key == 3)
	{
		free(fractol->crdn);
		fractol->crdn = NULL;
	}
	if (key == 0 || key == 1 || key == 3)
	{
		free(fractol->mlx);
		fractol->mlx = NULL;
	}
	if (key == 0 || key == 1 || key == 2 || key == 3)
	{
		free(fractol->cmplx);
		fractol->cmplx = NULL;
	}
	if (key == 0 || key == 1 || key == 2)
	{
		free(fractol);
		fractol = NULL;
	}
	return (1);
}

void				fill_crdn(double min_x, double max_x, \
						double min_y, double max_y, t_fractol *fractol)
{
	fractol->crdn->min_x = min_x;
	fractol->crdn->max_x = max_x;
	fractol->crdn->min_y = min_y;
	fractol->crdn->max_y = max_y;
	// fractol->crdn->max_y = fractol->crdn->min_y + \
	// 	(fractol->crdn->max_x - fractol->crdn->min_x) * HIGHT / WIDTH;
	fractol->crdn->shift_x = (fractol->crdn->max_x - fractol->crdn->min_x) / (WIDTH - 1);
	fractol->crdn->shift_y = (fractol->crdn->max_y - fractol->crdn->min_y) / (HIGHT - 1);
	fractol->crdn->move_x = 0.0;
	fractol->crdn->move_y = 0.0;	
	fractol->crdn->repeats = 30;
}

t_fractol			*create_struct(void)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	fractol->move_flag = 0;
	if (!(fractol->crdn = (t_crdn *)malloc(sizeof(t_crdn))))
	{
		delete_struct(0, fractol);
		return (NULL);
	}
	fill_crdn(-2.0, 1.0, -1.0, 1.0, fractol);
	if (!(fractol->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		delete_struct(1, fractol);
		return (NULL);
	}
	if (!(fractol->cmplx = (t_cmplx *)malloc(sizeof(t_cmplx))))
	{
		delete_struct(2, fractol);
		return (NULL);
	}
	fractol->color = BLOOD;
	return (fractol);
}

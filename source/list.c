/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:55:26 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/03 11:56:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					delete_struct(int key, t_fractol *fractol)
{
	if (key == 1 || key == 2 || key == 3 || key == 4)
	{
		ft_strdel(&(fractol->opencl->cl));	
		ft_memdel((void *)(fractol->opencl));
	}
	if (key == 2 || key == 3 || key == 4)
		ft_memdel((void *)(fractol->crdn));
	if (key == 3 || key == 4)
		ft_memdel((void *)(fractol->mlx));
	if (key == 4)
		ft_memdel((void *)(fractol->cmplx));
	if (key == 0 || key == 1 || key == 2 || key == 3 || key == 4)
		ft_memdel((void *)fractol);
	return (0);
}

void				fill_crdn(t_fractol *fractol)
{
	fractol->crdn->min_x = -2.0;
	fractol->crdn->max_x = 1.0;
	fractol->crdn->min_y = -1.0;
	fractol->crdn->max_y = 1.0;
	fractol->crdn->shift_x = (fractol->crdn->max_x - \
								fractol->crdn->min_x) / (WIDTH - 1);
	fractol->crdn->shift_y = (fractol->crdn->max_y - \
								fractol->crdn->min_y) / (HIGHT - 1);
	fractol->crdn->move_x = 0.0;
	fractol->crdn->move_y = 0.0;
}

t_fractol			*create_struct(void)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	fractol->move_flag = 0;
	if (!(fractol->opencl = (t_opencl *)malloc(sizeof(t_opencl))))
		delete_struct(0, fractol);
	fractol->opencl->size = 500;
	if (!(fractol->crdn = (t_crdn *)malloc(sizeof(t_crdn))))
		delete_struct(1, fractol);
	fill_crdn(fractol);
	if (!(fractol->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		delete_struct(2, fractol);
	if (!(fractol->cmplx = (t_cmplx *)malloc(sizeof(t_cmplx))))
		delete_struct(3, fractol);
	fractol->cmplx->repeats = 30;
	fractol->color = BLOOD;
	return (fractol);
}

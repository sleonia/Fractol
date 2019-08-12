/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:55:26 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 08:41:58 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					delete_struct(int key, t_fractol *f)
{
	if (key == 1 || key == 2 || key == 3)
	{
		clReleaseMemObject(f->cl->cl_data);
		clReleaseMemObject(f->cl->cl_i_arg);
		clReleaseMemObject(f->cl->cl_f_arg);
		clReleaseProgram(f->cl->program);
		clReleaseKernel(f->cl->kernel);
		clReleaseCommandQueue(f->cl->queue);
		clReleaseContext(f->cl->context);
		ft_memdel((void *)(f->cl->i_arg));
		ft_memdel((void *)(f->cl->f_arg));
		ft_strdel(&f->cl->file);
		ft_memdel((void *)(f->cl));
	}
	if (key == 2 || key == 3)
		ft_memdel((void *)(f->crdn));
	if (key == 3)
		ft_memdel((void *)(f->mlx));
	if (key == 0 || key == 1 || key == 2 || key == 3)
		ft_memdel((void *)f);
	return (0);
}

void				fill_struct(t_fractol *f)
{
	f->size = f->hight * f->width;
	f->crdn->min_x = -2.0;
	f->crdn->max_x = 1.0;
	f->crdn->min_y = -1.0;
	f->crdn->max_y = f->crdn->min_y + (f->crdn->max_x - f->crdn->min_x) \
		* f->hight / f->width;
	f->crdn->shift_x = (f->crdn->max_x - f->crdn->min_x) / (f->width - 1);
	f->crdn->shift_y = (f->crdn->max_y - f->crdn->min_y) / (f->hight - 1);
	f->crdn->move_x = 0.0;
	f->crdn->move_y = 0.0;
	f->repeats = 300;
	f->color_key = 0;
}

t_fractol			*create_struct(void)
{
	t_fractol		*f;

	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	f->hight = 600;
	f->width = 1000;
	f->move_flag = 0;
	if (!(f->cl = (t_cl *)malloc(sizeof(t_cl))))
		delete_struct(0, f);
	if (!(f->cl->i_arg = (int *)malloc(sizeof(int) * 10)))
		delete_struct(1, f);
	if (!(f->cl->f_arg = (float *)malloc(sizeof(float) * 10)))
	{
		ft_memdel((void *)(f->cl->i_arg));
		delete_struct(1, f);
	}
	if (!(f->crdn = (t_crdn *)malloc(sizeof(t_crdn))))
		delete_struct(1, f);
	if (!(f->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		delete_struct(2, f);
	fill_struct(f);
	return (f);
}

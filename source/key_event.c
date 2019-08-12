/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:38:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 08:53:20 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				zoom(int keycode, t_fractol *f)
{
	if (keycode == MINUS)
		return ;
	if (keycode == PLUS)
		return ;
}

static void			move(int keycode, t_fractol *f)
{
	if (keycode == 2)
		f->crdn->move_x += 0.02;
	if (keycode == 0)
		f->crdn->move_x -= 0.02;
	if (keycode == 1)
		f->crdn->move_y -= 0.02;
	if (keycode == 13)
		f->crdn->move_y += 0.02;
}

static void			recolor(int keycode, t_fractol *f)
{
	if (keycode == 82)
		f->color_key = 0;
	else if (keycode == 83)
		f->color_key = 1;
	else if (keycode == 84)
		f->color_key = 2;
	else if (keycode == 85)
		f->color_key = 3;
	else if (keycode == 86)
		f->color_key = 4;
	else if (keycode == 87)
		f->color_key = 5;
	else if (keycode == 88)
		f->color_key = 6;
	else if (keycode == 89)
		f->color_key = 7;
	else if (keycode == 91)
		f->color_key = 8;
}

static void			*resize(int keycode, t_fractol *f)
{
	if (keycode == 24)
	{
		f->hight += 10;
		f->width += 10;
	}
	if (keycode == 27)
	{
		f->hight -= 10;
		f->width -= 10;
	}
	mlx_destroy_image(f->mlx->ptr, f->mlx->img);
	mlx_destroy_window(f->mlx->ptr, f->mlx->win);
	f->mlx->data = NULL;
	f->size = f->hight * f->width;
	clReleaseMemObject(f->cl->cl_data);
	clReleaseMemObject(f->cl->cl_i_arg);
	clReleaseMemObject(f->cl->cl_f_arg);
	clReleaseProgram(f->cl->program);
	clReleaseKernel(f->cl->kernel);
	clReleaseCommandQueue(f->cl->queue);
	clReleaseContext(f->cl->context);
	ft_strdel(&f->cl->file);
	fill_struct(f);
	create_window(f);
	return (NULL);
}

int					key_event(int keycode, t_fractol *f)
{
	if (keycode == EXIT)
		exit(0);
	if ((keycode >= 82 && keycode <= 89) || keycode == 91)
		recolor(keycode, f);
	if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, f);
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		move(keycode, f);
	if (keycode == 24 || keycode == 27)
	{
		if (!resize(keycode, f))
			return (1);
	}
	run_fractol(f);
	return (0);
}

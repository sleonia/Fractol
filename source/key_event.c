/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:38:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/15 20:15:05 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				zoom(int keycode, t_fractol *f)
{
	if (keycode == PLUS)
	{
		f->crdn->min_x *= 0.95;
		f->crdn->max_x *= 0.95;
		f->crdn->min_y *= 0.95;
		f->repeats += 2;
	}
	if (keycode == MINUS)
	{
		f->crdn->min_x *= 1.1;
		f->crdn->max_x *= 1.1;
		f->crdn->min_y *= 1.1;
		f->repeats -= 2;
	}
}

static void			move(int keycode, t_fractol *f)
{
	if (keycode == RIGHT)
		f->crdn->move_x -= (f->crdn->max_x - f->crdn->min_x) / 0.1;
	if (keycode == LEFT)
		f->crdn->move_x += (f->crdn->max_x - f->crdn->min_x) / 0.1;
	if (keycode == DOWN)
		f->crdn->move_y += (f->crdn->max_y - f->crdn->min_y) / 0.1;
	if (keycode == TOP)
		f->crdn->move_y -= (f->crdn->max_y - f->crdn->min_y) / 0.1;
}

static void			recolor(int keycode, t_fractol *f)
{
	if (keycode == NUMPAD_0)
		f->color_key = 0;
	else if (keycode == NUMPAD_1)
		f->color_key = 1;
	else if (keycode == NUMPAD_2)
		f->color_key = 2;
	else if (keycode == NUMPAD_3)
		f->color_key = 3;
	else if (keycode == NUMPAD_4)
		f->color_key = 4;
	else if (keycode == NUMPAD_5)
		f->color_key = 5;
	else if (keycode == NUMPAD_6)
		f->color_key = 6;
	else if (keycode == NUMPAD_7)
		f->color_key = 7;
	else if (keycode == NUMPAD_8)
		f->color_key = 8;
	else if (keycode == NUMPAD_9)
		f->color_key = 9;
}

static void			*resize(int keycode, t_fractol *f)
{
	if (keycode == INC_WIN)
	{
		f->hight += 10;
		f->width += 10;
	}
	if ((keycode == DEC_WIN) && (f->hight > 20 && f->width))
	{
		f->hight -= 10;
		f->width -= 10;
	}
	mlx_destroy_image(f->mlx->ptr, f->mlx->img);
	mlx_destroy_window(f->mlx->ptr, f->mlx->win);
	f->mlx->data = NULL;
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
	{
		if (((t_fractol *)f)->song_key == 1)
			system("killall afplay");
		exit(0);
	}
	if ((keycode >= NUMPAD_0 && keycode <= NUMPAD_7) || keycode == NUMPAD_8 \
	|| keycode == NUMPAD_9)
		recolor(keycode, f);
	if ((keycode >= LEFT && keycode <= RIGHT) || keycode == TOP)
		move(keycode, f);
	if (keycode == INC_WIN || keycode == DEC_WIN)
	{
		if (!resize(keycode, f))
			return (1);
	}
	if (keycode == REPEAT_BUF)
		f->repeats += 2;
	if (keycode == REPEAT_DEBUF)
		f->repeats -= 2;
	if (keycode == PLAY_SONG || keycode == STOP_SONG)
		music(keycode, f);
	run_fractol(f);
	return (0);
}

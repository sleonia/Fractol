/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:34:25 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 13:32:02 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			close_window(void *f)
{
	clReleaseProgram(((t_fractol *)f)->cl->program);
	clReleaseKernel(((t_fractol *)f)->cl->kernel);
	clReleaseCommandQueue(((t_fractol *)f)->cl->queue);
	clReleaseContext(((t_fractol *)f)->cl->context);
	mlx_destroy_image(((t_fractol *)f)->mlx->ptr, ((t_fractol *)f)->mlx->img);
	(void)f;
	exit(0);
}

void				fill_background(int color, t_fractol *f)
{
	int				x;
	int				y;
	int				i;

	i = -1;
	while (++i < f->size)
	{
		x = i % f->width;
		y = i / f->width;
		f->mlx->data[y * f->width + x] = color;
	}
}

void				*run_fractol(t_fractol *f)
{
	fill_background(0, f);
	if (!(create_buf(f)))
		return (NULL);
	mlx_put_image_to_window(f->mlx->ptr, f->mlx->win, f->mlx->img, 0, 0);
	return (f);
}

int					create_window(t_fractol *f)
{
	if (!(f->mlx->ptr = mlx_init()))
		return (delete_struct(3, f));
	if (!(f->mlx->win = mlx_new_window(f->mlx->ptr, \
						f->width, f->hight, "fractol")))
		return (delete_struct(3, f));
	if (!(f->mlx->img = mlx_new_image(f->mlx->ptr, f->width, f->hight)))
		return (delete_struct(3, f));
	if (!(f->mlx->data = (int *)mlx_get_data_addr(f->mlx->img, \
		&(f->mlx->bpp), &(f->mlx->size_l), &(f->mlx->endn))))
		return (delete_struct(3, f));
	if (!init_cl(f))
		return (1);
	if (!run_fractol(f))
		return (1);
	mlx_hook(f->mlx->win, 17, 0, close_window, f);
	mlx_hook(f->mlx->win, 2, 0, key_event, f);
	mlx_hook(f->mlx->win, 5, 0, mouse_press, f);
	mlx_hook(f->mlx->win, 6, 0, mouse_move, f);
	mlx_loop(f->mlx->ptr);
	return (0);
}

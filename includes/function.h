/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:52:08 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/04 09:24:22 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
** Main header file
*/
# include "fractol.h"

/*
** main.c
*/
static	int			error_prosessing(int key);
static	int			arg_prosessing(char *arg);
int					main();

/*
** window.c
*/
static int			close_window(void *param);
int					create_window(t_fractol *f);

/*
** list.c
*/
int					delete_struct(int key, t_fractol *f);
void				fill_crdn(t_fractol *f);
t_fractol			*create_struct(void);

/*
** key_event.c
*/
void				zoom(int keycode, t_fractol *f);
static void			recolor(int keycode, t_fractol *f);
int					key_event(int keycode, t_fractol *f);

/*
** mandelbrot.c
*/
static void			calculate_cmplx(int x, int y, t_fractol *f);
void				mandelbrot(t_fractol *f);

/*
** draw.c
*/
void				put_pixel(int x, int y, int color, t_fractol *f);
void				fill_backgound(int color, t_fractol *f);
void				main_draw(int x, int y, t_fractol *f);

/*
** change_fractol.c
*/
void				change_fractol(t_fractol *f);

/*
** strips.c
*/
void				drow_strips(int x, int y, t_fractol *f);

/*
** mouse_event.c
*/
int					mouse_move(int x, int y, t_fractol *f);
int					mouse_press(int button, int x, int y, t_fractol *f);

/*
** opencl.c
*/
void				*send_arg(t_fractol *f);
void				*processing_arg(t_fractol *f);
void				*init(t_fractol *f);

#endif

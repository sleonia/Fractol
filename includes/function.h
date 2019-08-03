/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:52:08 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/03 12:00:57 by sleonia          ###   ########.fr       */
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
int					create_window(t_fractol *fractol);

/*
** list.c
*/
int					delete_struct(int key, t_fractol *fractol);
void				fill_crdn(t_fractol *fractol);
t_fractol			*create_struct(void);

/*
** key_event.c
*/
void				zoom(int keycode, t_fractol *fractol);
static void			recolor(int keycode, t_fractol *fractol);
int					key_event(int keycode, t_fractol *fractol);

/*
** mandelbrot.c
*/
static void			calculate_cmplx(int x, int y, t_fractol *fractol);
void				mandelbrot(t_fractol *fractol);

/*
** draw.c
*/
void				put_pixel(int x, int y, int color, t_fractol *fractol);
void				fill_backgound(int color, t_fractol *fractol);
void				main_draw(int x, int y, t_fractol *fractol);

/*
** change_fractol.c
*/
void				change_fractol(t_fractol *fractol);

/*
** strips.c
*/
void				drow_strips(int x, int y, t_fractol *fractol);

/*
** mouse_event.c
*/
int					mouse_move(int x, int y, t_fractol *fractol);
int					mouse_press(int button, int x, int y, t_fractol *fractol);

/*
** opencl.c
*/
void					calculate(t_fractol *fractol);
void					init(t_fractol *fractol);

#endif

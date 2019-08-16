/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:52:08 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/16 15:38:18 by sleonia          ###   ########.fr       */
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
int					error_prosessing(int key);
static	int			arg_prosessing(char *arg);
int					main(int ac, char **av);

/*
** window.c
*/
static int			close_window(void *param);
void				fill_background(int color, t_fractol *f);
void				*run_fractol(t_fractol *f);
int					create_window(t_fractol *f);

/*
** list.c
*/
int					delete_struct(int key, t_fractol *f);
void				fill_struct(t_fractol *f);
void				default_value(t_fractol *f);
t_fractol			*create_struct(void);

/*
** key_event.c
*/
void				zoom(int keycode, t_fractol *f);
static void			recolor(int keycode, t_fractol *f);
static void			move(int keycode, t_fractol *f);
static void			*resize(int keycode, t_fractol *f);
int					key_event(int keycode, t_fractol *f);

/*
** mouse_event.c
*/
int					mouse_move(int x, int y, t_fractol *f);
int					mouse_press(int button, int x, int y, t_fractol *f);
int					mouse_event(int keycode, int x, int y, t_fractol *f);

/*
** music.c
*/
void				music(int keycode, t_fractol *f);

/*
** menu_fractal.c
*/
void				menu_fractal(t_fractol *f);

/*
** opencl.c
*/
static void			*error_cl(int key);
void				fill_arg(t_fractol *f);
void				*create_buf(t_fractol *f);
static void			*init_buf_cl(t_fractol *f);
void				*init_cl(t_fractol *f);

#endif

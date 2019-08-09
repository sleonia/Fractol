/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:52:08 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/09 09:57:56 by sleonia          ###   ########.fr       */
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
int	        		error_prosessing(int key);
static	int			arg_prosessing(char *arg);
int					main(int ac, char **av);

/*
** window.c
*/
static int			close_window(void *param);
void				fill_backgound(int color, t_fractol *f);
void				*start_fractol(t_fractol *f);
int					create_window(t_fractol *f);

/*
** list.c
*/
int					delete_struct(int key, t_fractol *f);
static void			fill_crdn(t_fractol *f);
t_fractol			*create_struct(void);

/*
** key_event.c
*/
void				zoom(int keycode, t_fractol *f);
static void			recolor(int keycode, t_fractol *f);
int					key_event(int keycode, t_fractol *f);

/*
** mouse_event.c
*/
int					mouse_move(int x, int y, t_fractol *f);
int					mouse_press(int button, int x, int y, t_fractol *f);

/*
** opencl.c
*/
static void			*error_cl(int key);
void				*fill_buf(t_fractol *f);
void				*create_buf(t_fractol *f);
void				*init2_cl(char *file, t_fractol *f);
void				*init_cl(t_fractol *f);

/*
** choose_color.c
*/

#endif

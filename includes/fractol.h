/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:13:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/24 09:47:32 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Map size
*/
# define WIDTH		1200
# define HEIGHT		800

/*
** Event`s
*/
# define EXIT  		53

/*
** Key of fractol`s
*/
# define MANDELBROT "mandelbrot"
# define JULIA     	"julia"

/*
** Key of fractol`s
*/
# define MANDELBROT_KEY 1
# define JULIA_KEY 		2

/*
** Library`s
*/
# include <math.h>
# include "./libft/includes/libft.h"
# include "./mlx/mlx.h"

/*
** Struct`s
*/

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_l;
	int				endn;
}					t_mlx;

typedef struct		s_crdt
{
	double			x;
	double			y;
}					t_crdt;

typedef struct		s_fractol
{
	t_mlx			*mlx;
	t_crdt			*crdt;
}					t_fractol;

/*
** Function`s
*/

/*
** main.c
*/
static	int			error_prosessing(void);
static	int			arg_prosessing(char *arg);
int					main();

/*
** window.c
*/
static int			close_window(void *param);
int					create_window(int key, t_fractol *fractol);

/*
** list.c
*/
t_fractol			*create_struct(void);

/*
** key_event.c
*/
int					key_event(int keycode, t_fractol *fractol);

/*
** mandelbrot.c
*/
void				mandelbrot(t_fractol *fractol);

/*
** drow.c
*/
void				put_pixel(int x, int y, int color, t_fractol *fractol);
void				fill_backgound(int color, t_fractol *fractol);

/*
** change_fractol.c
*/
void				change_fractol(int key, t_fractol *fractol);

#endif

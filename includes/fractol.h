/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:13:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/25 19:17:58 by sleonia          ###   ########.fr       */
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
** Table for calculate complex numbers
*/
# define MAX_X		1.0
# define MIN_X		-2.0
# define MIN_Y		-1.0
# define MAX_Y		MIN_Y + (MAX_X - MIN_X) * HEIGHT / WIDTH
# define SHIFT_X	(MAX_X - MIN_X) / (WIDTH - 1)
# define SHIFT_Y	(MAX_Y - MIN_Y) / (HEIGHT - 1)
# define REPEATS	30

/*
** Event`s
*/
# define EXIT  		53

/*
** List of fractol`s
*/
# define MANDELBROT "mandelbrot"
# define JULIA     	"julia"

/*
** Key of fractol`s
*/
# define MANDELBROT_KEY 1
# define JULIA_KEY 		2

/*
** Colors
*/
# define WHITE 		0xFFFFFF
# define BLOOD 		0x630101
# define YELLOW		0xA18B28
# define PURPLE 	0x9303A7
# define BLUE 		0x0B61A4
# define GREEN 		0x58E000

/*
** Strip`s step
*/
# define X_STEP 	10
# define Y_STEP 	10

/*
** Library`s
*/
# include <time.h>
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

typedef struct		s_cmplx
{
	int				key;
	double			c_x;
	double			c_y;
	double			z_x;
	double			z_y;
	double			sqr_z_x;
	double			sqr_z_y;
}					t_cmplx;

typedef struct		s_fractol
{
	int				key;
	int				color;
	t_mlx			*mlx;
	t_cmplx			*cmplx;
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
int					create_window(t_fractol *fractol);

/*
** list.c
*/
int					delete_struct(int key, t_fractol *fractol);
t_fractol			*create_struct(void);

/*
** key_event.c
*/
static void			recolor(int keycode, t_fractol *fractol);
int					key_event(int keycode, t_fractol *fractol);

/*
** mandelbrot.c
*/
static void			calculate_cmplx(int x, int y, t_fractol *fractol);
void				mandelbrot(t_fractol *fractol);

/*
** drow.c
*/
void				put_pixel(int x, int y, int color, t_fractol *fractol);
void				fill_backgound(int color, t_fractol *fractol);
void				main_drow(int x, int y, t_fractol *fractol);

/*
** change_fractol.c
*/
void				change_fractol(t_fractol *fractol);

/*
** strips.c
*/
void				drow_strips(int x, int y, t_fractol *fractol);

#endif

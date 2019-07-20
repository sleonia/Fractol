/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:13:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/07/20 13:04:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Map size
*/
# define HEIGHT		1300
# define WIDTH		1300

/*
** Event`s
*/
# define EXIT  		53

/*
** List of fractol`s
*/



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
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct		s_fractol
{
	t_mlx			*mlx;
}					t_fractol;

/*
** Function`s
*/

/*
** main.c
*/
static	int			error_prosessing(void);
int					main(int ac, char **av);

/*
** window.c
*/
static int			close_window(void *param);
int					window(t_fractol *fractol);

/*
** list.c
*/
t_fractol			*create_struct();

/*
** key_event.c
*/
int                 key_event(int keycode, t_fractol *fractol);

/*
** drow.c
*/
void				put_pixel(t_fractol *fractol, int x, int y, int color);


#endif

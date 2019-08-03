/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:13:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/03 11:13:29 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Map size
*/
# define WIDTH		1200
# define HIGHT		800

/*
** Event`s
*/
# define EXIT  		53
# define PLUS  		69
# define MINUS		78

/*
** List of fractol`s
*/
# define MANDELBROT 0
# define JULIA     	1

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
# include <OpenCL/cl.h>

/*
** Struct`s
*/
# include "struct.h"

/*
** Function`s
*/
# include "function.h"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:13:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 12:18:02 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Event`s
*/
# define EXIT  		53
# define PLUS  		69
# define MINUS		78

/*
** Strip`s step
*/
# define X_STEP 	10
# define Y_STEP 	10

/*
** For calculate fractol`s
*/
# define PROGRAM_FILE "./source/speed.cl"

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

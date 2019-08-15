/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 09:13:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/14 21:23:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Event`s
*/
# define EXIT			53

# define PLUS			69
# define MINUS			78

# define REPEAT_BUF		75
# define REPEAT_DEBUF	67

# define PLAY_SONG		35
# define STOP_SONG		31

# define NUMPAD_0		82
# define NUMPAD_1		83
# define NUMPAD_2		84
# define NUMPAD_3		85
# define NUMPAD_4		86
# define NUMPAD_5		87
# define NUMPAD_6		88
# define NUMPAD_7		89
# define NUMPAD_8		91
# define NUMPAD_9		92

# define TOP			13
# define RIGHT			2
# define LEFT			0
# define DOWN			1

# define INC_WIN		24
# define DEC_WIN		27

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

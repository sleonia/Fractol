/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:56:00 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 08:55:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** Main header file
*/
# include "fractol.h"

typedef struct			s_cl
{
	char				*file;
	int					*i_arg;
	float				*f_arg;
	cl_mem				cl_data;
	cl_mem				cl_i_arg;
	cl_mem				cl_f_arg;
	cl_platform_id		p_id;
	cl_device_id		d_id;
	cl_uint				ret_num_platforms;
	cl_context			context;
	cl_command_queue	queue;
	cl_program			program;
	cl_kernel			kernel;
}						t_cl;

typedef struct			s_crdn
{
	float				max_x;
	float				min_x;
	float				max_y;
	float				min_y;
	float				shift_x;
	float				shift_y;
	float				move_x;
	float				move_y;
}						t_crdn;

typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	void				*img;
	int					*data;
	int					bpp;
	int					size_l;
	int					endn;
}						t_mlx;

typedef struct			s_cmplx
{
	float				start_x;
	float				start_y;
	float				new_x;
	float				new_y;
	float				sqr_x;
	float				sqr_y;
}						t_cmplx;

typedef struct			s_fractol
{
	int					hight;
	int					width;
	int					size;
	short int			fractol;
	short int			move_flag;
	int					color_key;
	int					repeats;
	t_cl				*cl;
	t_crdn				*crdn;
	t_mlx				*mlx;
}						t_fractol;

#endif

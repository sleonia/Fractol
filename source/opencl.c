/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:46:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/12 08:40:42 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			*error_cl(int key)
{
	if (key == 1)
		ft_putendl("\033[31mMalloc return null\033[0m");
	else if (key == 1)
		ft_putendl("\033[31mError in clGetPlatformIDs\033[0m");
	else if (key == 2)
		ft_putendl("\033[31mError in clGetDeviceIDs\033[0m");
	else if (key == 3)
		ft_putendl("\033[31mError in clCreateContext\033[0m");
	else if (key == 4)
		ft_putendl("\033[31mError in clCreateCommandQueue\033[0m");
	else if (key == 5)
		ft_putendl("\033[31mError in clCreateProgramWithSource\033[0m");
	else if (key == 6)
		ft_putendl("\033[31mError in clBuildProgram\033[0m");
	else if (key == 7)
		ft_putendl("\033[31mError in clCreateKernel\033[0m");
	else if (key == 8)
		ft_putendl("\033[31mError in clSetKernelArg\033[0m");
	else if (key == 9)
		ft_putendl("\033[31mError in clCreateBuffer\033[0m");
	return (NULL);
}

void				fill_arg(t_fractol *f)
{
	f->cl->i_arg[0] = f->hight;
	f->cl->i_arg[1] = f->width;
	f->cl->i_arg[2] = f->fractol;
	f->cl->i_arg[3] = f->repeats;
	f->cl->i_arg[4] = f->color_key;
	f->cl->f_arg[0] = f->crdn->max_y;
	f->cl->f_arg[1] = f->crdn->min_x;
	f->cl->f_arg[2] = f->crdn->shift_y;
	f->cl->f_arg[3] = f->crdn->shift_x;
	f->cl->f_arg[4] = f->crdn->move_y;
	f->cl->f_arg[5] = f->crdn->move_x;
}

void				*create_buf(t_fractol *f)
{
	size_t			local;
	size_t			global;
	cl_int			err;

	local = 64;
	fill_arg(f);
	global = ceil(f->size / (int)local) * local;
	if ((err = clEnqueueWriteBuffer(f->cl->queue, f->cl->cl_i_arg, CL_TRUE, 0, \
		10 * sizeof(int), f->cl->i_arg, 0, NULL, NULL)) != 0)
		return (error_cl(9));
	if ((err = clEnqueueWriteBuffer(f->cl->queue, f->cl->cl_f_arg, CL_TRUE, 0, \
		10 * sizeof(float), f->cl->f_arg, 0, NULL, NULL)) != 0)
		return (error_cl(9));
	err = clSetKernelArg(f->cl->kernel, 0, sizeof(cl_mem), &f->cl->cl_data);
	err |= clSetKernelArg(f->cl->kernel, 1, sizeof(cl_mem), &f->cl->cl_i_arg);
	err |= clSetKernelArg(f->cl->kernel, 2, sizeof(cl_mem), &f->cl->cl_f_arg);
	err = clEnqueueNDRangeKernel(f->cl->queue, \
		f->cl->kernel, 1, NULL, &global, &local, 0, NULL, NULL);
	clFinish(f->cl->queue);
	err = clEnqueueReadBuffer(f->cl->queue, f->cl->cl_data, CL_TRUE, 0, \
		f->size * sizeof(int), f->mlx->data, 0, NULL, NULL);
	return (f);
}

void				*init_buf_cl(t_fractol *f)
{
	cl_int			err;

	f->cl->cl_data = clCreateBuffer(f->cl->context, CL_MEM_WRITE_ONLY, \
		f->size * sizeof(int), NULL, &err);
	if (err != 0)
		return (error_cl(9));
	f->cl->cl_i_arg = clCreateBuffer(f->cl->context, CL_MEM_READ_ONLY, \
		10 * sizeof(int), NULL, &err);
	if (err != 0)
		return (error_cl(9));
	f->cl->cl_f_arg = clCreateBuffer(f->cl->context, CL_MEM_READ_ONLY, \
		10 * sizeof(float), NULL, &err);
	if (err != 0)
		return (error_cl(9));
	return (f);
}

void				*init_cl(t_fractol *f)
{
	cl_int			err;

	if (!(f->cl->file = read_file(1100, PROGRAM_FILE)))
		return (error_cl(0));
	if ((err = clGetPlatformIDs(1, &f->cl->p_id, NULL) != 0))
		return (error_cl(1));
	if ((err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, \
		&f->cl->d_id, NULL) != 0))
		return (error_cl(2));
	f->cl->context = clCreateContext(0, 1, &(f->cl->d_id), NULL, NULL, &err);
	if (err != 0)
		return (error_cl(3));
	f->cl->queue = clCreateCommandQueue(f->cl->context, f->cl->d_id, 0, &err);
	if (err != 0)
		return (error_cl(4));
	f->cl->program = clCreateProgramWithSource(f->cl->context, 1, \
		(const char **)&f->cl->file, NULL, &err);
	if (err != 0)
		return (error_cl(5));
	if ((err = clBuildProgram(f->cl->program, 0, NULL, NULL, NULL, NULL) != 0))
		return (error_cl(6));
	f->cl->kernel = clCreateKernel(f->cl->program, "fractol", &err);
	if (err != 0)
		return (error_cl(8));
	return (init_buf_cl(f) == NULL ? NULL : f);
}

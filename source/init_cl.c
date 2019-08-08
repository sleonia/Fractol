/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:46:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/08 17:02:17 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					*error_cl(int key)
{
	if (key == 0)
		ft_putendl("\033[31mMalloc return null\033[0m");
	else if (key == 1)
		ft_putendl("\033[31mError in clGetDeviceIDs\033[0m");
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
	return (NULL);
}

void					*fill_buf(t_fractol *f)
{
	int					hight;
	int					width;
	cl_int				err;

	hight = HIGHT;
	width = WIDTH;
	err = clSetKernelArg(f->cl->kernel, 0, sizeof(cl_mem), &f->cl->res);
	err |= clSetKernelArg(f->cl->kernel, 1, sizeof(int), &hight);
	err |= clSetKernelArg(f->cl->kernel, 2, sizeof(int), &width);
	err |= clSetKernelArg(f->cl->kernel, 3, sizeof(short int), &f->fractol);
	err |= clSetKernelArg(f->cl->kernel, 4, sizeof(int), &f->color);
	err |= clSetKernelArg(f->cl->kernel, 5, sizeof(double), &f->crdn->max_y);
	err |= clSetKernelArg(f->cl->kernel, 6, sizeof(double), &f->crdn->min_x);
	err |= clSetKernelArg(f->cl->kernel, 7, sizeof(double), &f->crdn->shift_x);
	err |= clSetKernelArg(f->cl->kernel, 8, sizeof(double), &f->crdn->shift_y);
	err |= clSetKernelArg(f->cl->kernel, 9, sizeof(double), &f->crdn->move_x);
	err |= clSetKernelArg(f->cl->kernel, 10, sizeof(double), &f->crdn->move_y);
	err |= clSetKernelArg(f->cl->kernel, 11, sizeof(int), &f->cmplx->repeats);
	if (err != CL_SUCCESS)
		return (error_cl(8));
	return (f);
}

void					*create_buf(t_fractol *f)
{
	cl_int				err;
	size_t				global_work_size;

	f->cl->res = clCreateBuffer(f->cl->context, CL_MEM_READ_WRITE, \
		SIZE * sizeof(cl_int), NULL, &err);
	err = clEnqueueWriteBuffer(f->cl->queue, f->cl->res, CL_TRUE, 0, \
		SIZE * sizeof(cl_int), (cl_int *)f->mlx->data, 0, NULL, NULL);
	global_work_size = SIZE;
	fill_buf(f);
	err = clEnqueueNDRangeKernel(f->cl->queue, \
		f->cl->kernel, 1, NULL, &global_work_size, NULL, 0, NULL, NULL);
	clFlush(f->cl->queue);
	err = clEnqueueReadBuffer(f->cl->queue, f->cl->res, CL_TRUE, 0, \
		SIZE * sizeof(float), (cl_int *)f->mlx->data, 0, NULL, NULL);
	return (f);
}

void					*init2_cl(char *file, t_fractol *f)
{
	cl_int				err;

	f->cl->program = clCreateProgramWithSource(f->cl->context, 1, \
		(const char **)&file, NULL, &err);
	if (err != CL_SUCCESS)
		return (error_cl(5));
	if ((err = clBuildProgram(f->cl->program, 0, NULL, NULL, NULL, \
		NULL) != CL_SUCCESS))
		return (error_cl(6));
	f->cl->kernel = clCreateKernel(f->cl->program, "fractol", &err);
	if (!(create_buf(f)) || err != CL_SUCCESS)
		return (error_cl(0));
	return (f);
}

void					*init_cl(t_fractol *f)
{
	cl_int				err;
	char				*file;
	size_t				size;

	size = 1100;
	if (!(file = read_file(size, PROGRAM_FILE)))
		return (error_cl(0));
	if ((err = clGetPlatformIDs(1, &f->cl->p_id, NULL) != CL_SUCCESS))
		return (error_cl(1));
	if ((err = clGetDeviceIDs(f->cl->p_id, CL_DEVICE_TYPE_GPU, 1, \
		&f->cl->d_id, NULL) != CL_SUCCESS))
		return (error_cl(2));
	f->cl->context = clCreateContext(NULL, 1, &f->cl->d_id, NULL, NULL, &err);
	if (err != CL_SUCCESS)
		return (error_cl(3));
	f->cl->queue = clCreateCommandQueue(f->cl->context, f->cl->d_id, 0, &err);
	if (err != CL_SUCCESS)
		return (error_cl(4));
	if (!(init2_cl(file, f)))
		return (NULL);
	ft_strdel(&file);
	return (f);
}

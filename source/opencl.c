/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:46:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/04 09:30:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				*send_arg(t_fractol *f)
{
	cl_mem			arr_x;
	cl_mem			arr_y;
	cl_mem			arr_output;
	size_t			local_size;
	size_t			global_size;

	arr_x = clCreateBuffer(f->opencl->context, CL_MEM_READ_ONLY, \
		sizeof(float) * WIDTH, NULL, NULL);
	arr_y = clCreateBuffer(f->opencl->context, CL_MEM_READ_ONLY, \
		sizeof(float) * HIGHT, NULL, NULL);
	arr_output = clCreateBuffer(f->opencl->context, CL_MEM_WRITE_ONLY, \
		sizeof(int) * WIDTH, NULL, NULL);
	f->opencl->ret = clEnqueueWriteBuffer(f->opencl->command_queue, arr_x, \
		CL_TRUE, 0, sizeof(float) * WIDTH, f->opencl->arr_x, 0, NULL, NULL);
	f->opencl->ret |= clEnqueueWriteBuffer(f->opencl->command_queue, arr_y, \
		CL_TRUE, 0, sizeof(float) * HIGHT, f->opencl->arr_y, 0, NULL, NULL);
	f->opencl->kernel = clCreateKernel(f->opencl->program, "test", \
		&(f->opencl->ret));
	f->opencl->ret = clSetKernelArg(f->opencl->kernel, 0, \
		sizeof(cl_mem), &(arr_x));
	f->opencl->ret |= clSetKernelArg(f->opencl->kernel, 1, \
		sizeof(cl_mem), &(arr_y));
	f->opencl->ret |= clSetKernelArg(f->opencl->kernel, 2, \
		sizeof(int), &(f->cmplx->repeats));
	f->opencl->ret |= clSetKernelArg(f->opencl->kernel, 3, \
		sizeof(cl_mem), &(arr_output));
	local_size = 256;
	global_size = ceil(WIDTH / local_size) * local_size;
	f->opencl->ret = clEnqueueNDRangeKernel(f->opencl->command_queue, \
		f->opencl->kernel, 1, NULL,  &global_size, &local_size, 0, NULL, NULL);
	clFinish(f->opencl->command_queue);
	clEnqueueReadBuffer(f->opencl->command_queue, arr_output, CL_TRUE, 0, \
		sizeof(int) * WIDTH, f->opencl->arr_output, 0, NULL, NULL);
	clReleaseKernel(f->opencl->kernel);
	clReleaseMemObject(arr_x);
	clReleaseMemObject(arr_y);
	clReleaseMemObject(arr_output);
	clReleaseCommandQueue(f->opencl->command_queue);
	clReleaseProgram(f->opencl->program);
	clReleaseContext(f->opencl->context);
	return (f);
}

void				*processing_arg(t_fractol *f)
{
	int				i;

	i = 0;
	if (!(f->opencl->arr_output = (int *)malloc(sizeof(int) * WIDTH)))
		return (NULL);
	if (!(f->opencl->arr_x = (float *)malloc(sizeof(float) * WIDTH)))
		return (NULL);
	if (!(f->opencl->arr_y = (float *)malloc(sizeof(float) * HIGHT)))
		return (NULL);
	while (i < WIDTH)
	{
		f->opencl->arr_y[i] = f->crdn->min_x + i \
			* f->crdn->shift_x - f->crdn->move_x;
		i++;
	}
	i = 0;
	while (i < HIGHT)
	{
		f->opencl->arr_y[i] = f->crdn->max_y - i \
			* f->crdn->shift_y - f->crdn->move_y;
		i++;
	}
	return (send_arg(f) == NULL ? NULL : f);
}

void				*init(t_fractol *f)
{
	int				fd;

	fd = open("./paralleling.cl", O_RDONLY);
	f->opencl->cl = (char *)malloc(sizeof(char) * f->opencl->size);
	read(fd, f->opencl->cl, f->opencl->size);
	f->opencl->cl[f->opencl->size] = '\0';
	f->opencl->ret = clGetPlatformIDs(1, \
		&(f->opencl->p_id), &(f->opencl->ret_num_platforms));
	f->opencl->ret = clGetDeviceIDs(f->opencl->p_id, \
		CL_DEVICE_TYPE_DEFAULT, 1, &(f->opencl->d_id), \
			&(f->opencl->ret_num_platforms));
	f->opencl->context = clCreateContext(NULL, 1, \
		&(f->opencl->d_id), NULL, NULL, &(f->opencl->ret));
	f->opencl->command_queue = clCreateCommandQueue(\
		f->opencl->context, f->opencl->d_id, 0, &(f->opencl->ret));
	f->opencl->program = clCreateProgramWithSource(\
		f->opencl->context, 1, (const char **)&(f->opencl->cl), \
			(const size_t *)&(f->opencl->size), &(f->opencl->ret));
	f->opencl->ret = clBuildProgram(f->opencl->program, 1, \
		&(f->opencl->d_id), NULL, NULL, NULL);
	return (processing_arg(f) == NULL ? NULL : f);
}

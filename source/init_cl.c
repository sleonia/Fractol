/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:46:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/06 08:33:53 by sleonia          ###   ########.fr       */
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
		ft_putendl("\033[31mError in clCreateContext\033[0m");
	else if (key == 3)
		ft_putendl("\033[31mError in clCreateCommandQueue\033[0m");
	else if (key == 4)
		ft_putendl("\033[31mError in clCreateProgramWithSource\033[0m");
	else if (key == 5)
		ft_putendl("\033[31mError in clBuildProgram\033[0m");
	else if (key == 6)
		ft_putendl("\033[31mError in clCreateKernel\033[0m");
	else if (key == 7)
		ft_putendl("\033[31mError in clSetKernelArg\033[0m");
	return (NULL);
}

void					*create_buf(t_fractol *f)
{
	size_t				global_work_size;

	f->opencl->result = clCreateBuffer(f->opencl->context, CL_MEM_READ_WRITE, \
		SIZE * sizeof(cl_int), NULL, &f->opencl->ret);
	f->opencl->ret = clEnqueueWriteBuffer(f->opencl->queue, f->opencl->result,\
		CL_TRUE, 0, SIZE * sizeof(cl_int), \
			(cl_int *)f->mlx->data, 0, NULL, NULL);
	f->opencl->ret = clSetKernelArg(f->opencl->kernel, 0, sizeof(cl_mem), \
		(void *)&f->opencl->result);
	global_work_size = SIZE;
	f->opencl->ret = clEnqueueNDRangeKernel(f->opencl->queue, \
		f->opencl->kernel, 1, NULL, &global_work_size, NULL, 0, NULL, NULL);
	clFinish(f->opencl->queue);
	f->opencl->ret = clEnqueueReadBuffer(f->opencl->queue, f->opencl->result, \
		CL_TRUE, 0, SIZE * sizeof(float), \
			(cl_int *)f->mlx->data, 0, NULL, NULL);
	return (f);
}

void					*init_cl(t_fractol *f)
{
	char				*file;
	size_t				size = 500;

	if (!(file = read_file(size, "/Users/sleonia/Desktop/fractol/source/speed.cl")))
		return (error_cl(0));
	f->opencl->ret = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, \
		&(f->opencl->device_id), NULL);
	f->opencl->context = clCreateContext(NULL, 1, &(f->opencl->device_id), \
		NULL, NULL, &(f->opencl->ret));
	f->opencl->queue = clCreateCommandQueue(f->opencl->context, \
		f->opencl->device_id, 0, &(f->opencl->ret));
	f->opencl->program = clCreateProgramWithSource(f->opencl->context, 1, \
		(const char **)&file, (const size_t *)&size, &(f->opencl->ret));
	f->opencl->ret = clBuildProgram(f->opencl->program, 0, \
		NULL, NULL, NULL, NULL);
	f->opencl->kernel = clCreateKernel(f->opencl->program, \
		KERNEL_FUNC, &(f->opencl->ret));
	if (!(create_buf(f)))
		return (error_cl(0));
	return (f);
}

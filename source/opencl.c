/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:46:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/03 12:09:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					calculate(t_fractol *fractol)
{
	cl_mem				mem_obj;
	int					mem_len = 10;
	cl_int				*mem = (int *)malloc(sizeof(int) * mem_len);

	for(int i = 0; i < 10; i++)
		mem[i] = 0;
	mem_obj = clCreateBuffer(fractol->opencl->context, CL_MEM_READ_WRITE, mem_len, NULL, mem);
	fractol->opencl->ret = clEnqueueWriteBuffer(fractol->opencl->command_queue, mem_obj, CL_TRUE, 0, mem_len * sizeof(cl_int), mem, 0, NULL, NULL);
	fractol->opencl->ret = clSetKernelArg(fractol->opencl->kernel, 0, sizeof(cl_mem), (void *)&mem_obj);
	
	for(int i = 0; i < 10; i++)
		printf("%d\n", mem[i]);
	//

	size_t				global_work_size[1] = { 10 };
	fractol->opencl->ret = clEnqueueNDRangeKernel(fractol->opencl->command_queue, fractol->opencl->kernel, 1, NULL, global_work_size, NULL, 0, NULL, NULL);
	fractol->opencl->ret = clEnqueueReadBuffer(fractol->opencl->command_queue, mem_obj, CL_TRUE, 0, mem_len * sizeof(float), mem, 0, NULL, NULL);

}

void					init(t_fractol *fractol)
{
	int					fd;

	fd = open("./paralleling.cl", O_RDONLY);
	fractol->opencl->cl = (char *)malloc(sizeof(char) * fractol->opencl->size);
	read(fd, fractol->opencl->cl, fractol->opencl->size);
	fractol->opencl->cl[fractol->opencl->size] = '\0';
	fractol->opencl->ret = clGetPlatformIDs(1, \
		&(fractol->opencl->p_id), &(fractol->opencl->ret_num_platforms));
	fractol->opencl->ret = clGetDeviceIDs(fractol->opencl->p_id, \
		CL_DEVICE_TYPE_DEFAULT, 1, &(fractol->opencl->d_id), \
			&(fractol->opencl->ret_num_platforms));
	fractol->opencl->context = clCreateContext(NULL, 1, \
		&(fractol->opencl->d_id), NULL, NULL, &(fractol->opencl->ret));
	fractol->opencl->command_queue = clCreateCommandQueue(\
		fractol->opencl->context, fractol->opencl->d_id, 0, \
			&(fractol->opencl->ret));
	fractol->opencl->program = clCreateProgramWithSource(\
		fractol->opencl->context, 1, (const char **)&(fractol->opencl->cl), \
			(const size_t *)&(fractol->opencl->size), \
				&(fractol->opencl->ret));
	fractol->opencl->ret = clBuildProgram(fractol->opencl->program, 1, \
		&(fractol->opencl->d_id), NULL, NULL, NULL);
	fractol->opencl->kernel = clCreateKernel(fractol->opencl->program, \
		"test", &(fractol->opencl->ret));
	calculate(fractol);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:31:34 by sleonia           #+#    #+#             */
/*   Updated: 2019/08/08 05:49:44 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*read_file(int size, char *name)
{
	int				fd;
	char			*str;

	if (size <= 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_strdel(&str);		
		return (NULL);
	}
	if ((read(fd, str, 0)) < 0)
		return (NULL);
	read(fd, str, size);
	str[size] = '\0';
	return (str);
}

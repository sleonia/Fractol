/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:05:58 by sleonia           #+#    #+#             */
/*   Updated: 2019/04/17 16:06:00 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n_list;

	n_list = (t_list *)malloc(sizeof(t_list));
	if (!n_list)
		return (NULL);
	if (content)
	{
		if (!(n_list->content = (void *)ft_memalloc(content_size)))
		{
			free(n_list);
			return (NULL);
		}
		ft_memcpy(n_list->content, content, content_size);
		n_list->content_size = content_size;
	}
	else
	{
		n_list->content = NULL;
		n_list->content_size = 0;
	}
	n_list->next = NULL;
	return (n_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:30:43 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/15 21:57:46 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*link;

	link = ft_memalloc(sizeof(t_list));
	if (!(link))
		return (NULL);
	(*link).content = ft_memalloc(content_size);
	if (!((*link).content))
		return (NULL);
	if (content == NULL)
	{
		(*link).content = NULL;
		(*link).content_size = 0;
	}
	else
	{
		ft_memcpy((*link).content, content, content_size);
		(*link).content_size = content_size;
	}
	(*link).next = NULL;
	return (link);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:34:44 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 16:24:38 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr;

	if ((ptr = (char *)ft_memalloc(size + 1)) != NULL)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	return (NULL);
}

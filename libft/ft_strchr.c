/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:56:05 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/01 11:16:00 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	while (i <= ft_strlen(s))
	{
		if ((char)c == ptr[i])
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}

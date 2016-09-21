/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:24:30 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/03 12:49:08 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*ptr;

	i = ft_strlen(s) + 1;
	ptr = (char *)s;
	while (i > 0)
	{
		i--;
		if ((char)c == ptr[i])
		{
			return (&ptr[i]);
		}
	}
	return (NULL);
}

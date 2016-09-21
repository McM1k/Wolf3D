/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:39:47 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/04 17:10:11 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		len_dst;

	j = size;
	i = 0;
	len_dst = ft_strlen(dst);
	while (dst[i] && j)
	{
		j--;
		i++;
	}
	if (j == 0)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && j - 1)
	{
		dst[i + len_dst] = src[i];
		j--;
		i++;
	}
	if (src[i] == '\0')
		dst[i + len_dst] = '\0';
	return (len_dst + ft_strlen(src));
}

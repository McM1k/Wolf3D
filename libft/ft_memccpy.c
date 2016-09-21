/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:46:12 by gboudrie          #+#    #+#             */
/*   Updated: 2015/11/30 22:47:49 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = dst;
	src_tmp = (void *)src;
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		if (dst_tmp[i] == (unsigned char)c)
		{
			return (&dst_tmp[i + 1]);
		}
		i++;
	}
	return (NULL);
}

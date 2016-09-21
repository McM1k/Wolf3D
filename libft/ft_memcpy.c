/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:55:39 by gboudrie          #+#    #+#             */
/*   Updated: 2015/11/26 14:05:14 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	dst_tmp = dst;
	src_tmp = src;
	while (n > 0)
	{
		n--;
		dst_tmp[n] = src_tmp[n];
	}
	return (dst);
}

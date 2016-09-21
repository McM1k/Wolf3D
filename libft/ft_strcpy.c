/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:25:17 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/20 18:08:25 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcpy(char *dst, const char *src)
{
	size_t	n;

	n = ft_strlen(src);
	dst = ft_memcpy(dst, src, n + 1);
	return (dst);
}

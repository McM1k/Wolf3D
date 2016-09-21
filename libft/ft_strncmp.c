/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:50:28 by gboudrie          #+#    #+#             */
/*   Updated: 2015/11/28 10:52:00 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n >= ft_strlen(s1) && n >= ft_strlen(s2))
		return (ft_strcmp(s1, s2));
	else
	{
		if (n < ft_strlen(s1))
		{
			if (n < ft_strlen(s2))
				return (ft_memcmp(s1, s2, n));
			else
				return (ft_memcmp(s1, s2, ft_strlen(s2)));
		}
		else
			return (ft_memcmp(s1, s2, ft_strlen(s1)));
	}
}

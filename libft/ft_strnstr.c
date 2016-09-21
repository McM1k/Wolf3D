/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:41:23 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/03 16:12:45 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	char		*s1_tmp;
	char		*s2_tmp;

	s1_tmp = (char *)s1;
	s2_tmp = (char *)s2;
	i = 0;
	if (!(s2_tmp[0]))
	{
		return (s1_tmp);
	}
	while ((s1_tmp[i]) && (i < n))
	{
		j = 0;
		while ((s2_tmp[j] == s1_tmp[i + j]) && (i + j < n))
		{
			j++;
			if (!(s2_tmp[j]))
				return (&s1_tmp[i]);
		}
		i++;
	}
	return (NULL);
}

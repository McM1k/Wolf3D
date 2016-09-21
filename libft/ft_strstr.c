/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:37:47 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/02 22:59:36 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	char		*s1_tmp;
	char		*s2_tmp;

	s1_tmp = (char *)s1;
	s2_tmp = (char *)s2;
	i = 0;
	if (!(s2_tmp[0]))
		return (s1_tmp);
	while (s1_tmp[i])
	{
		j = 0;
		while (s2_tmp[j] == s1_tmp[i + j])
		{
			j++;
			if (!(s2_tmp[j]))
				return (&s1_tmp[i]);
		}
		i++;
	}
	return (NULL);
}

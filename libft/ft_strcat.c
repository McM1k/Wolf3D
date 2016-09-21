/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:09:57 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/04 13:11:07 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char		*s2_tmp;
	size_t		i;
	size_t		len;

	s2_tmp = (char *)s2;
	i = 0;
	len = ft_strlen(s1);
	while (s2_tmp[i])
	{
		s1[len + i] = s2_tmp[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}

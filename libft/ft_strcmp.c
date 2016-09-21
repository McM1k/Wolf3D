/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:13:08 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/02 17:08:51 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char		*s1_tmp;
	unsigned char		*s2_tmp;
	size_t				i;

	i = 0;
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	while (s1_tmp[i] == s2_tmp[i])
	{
		if ((s1_tmp[i] == '\0') || (s2_tmp[i] == '\0'))
			return (0);
		i++;
	}
	return (s1_tmp[i] - s2_tmp[i]);
}

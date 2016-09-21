/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:35:45 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/04 12:15:25 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*s2;

	s2 = ft_strnew(ft_strlen(s1));
	if (!s2)
		return (NULL);
	else
	{
		s2 = ft_memcpy(s2, s1, ft_strlen(s1));
		return (s2);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:57:26 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 16:48:35 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s_new;

	i = 0;
	if ((s_new = ft_strnew(ft_strlen(s))) != NULL)
	{
		while (s[i])
		{
			s_new[i] = f(i, s[i]);
			i++;
		}
		return (s_new);
	}
	return (NULL);
}

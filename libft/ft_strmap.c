/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:40:13 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 16:46:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s_new;

	i = 0;
	if ((s_new = ft_strnew(ft_strlen(s))) != NULL)
	{
		while (s[i])
		{
			s_new[i] = f(s[i]);
			i++;
		}
		return (s_new);
	}
	return (NULL);
}

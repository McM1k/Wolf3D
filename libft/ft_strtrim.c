/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:12:28 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 17:37:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issemispace(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t'))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char		*str;
	char		*ptr;
	size_t		i;

	ptr = (char *)s;
	while ((ft_issemispace(*ptr) == 1) && (*ptr))
		ptr++;
	i = ft_strlen(ptr);
	if (i == 0)
		return ("");
	while (ft_issemispace(ptr[i - 1]) == 1)
		i--;
	if ((str = ft_strnew(i)) != NULL)
	{
		str[i] = '\0';
		while (i)
		{
			str[i - 1] = ptr[i - 1];
			i--;
		}
		return (str);
	}
	return (NULL);
}

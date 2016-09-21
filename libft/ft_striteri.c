/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:22:28 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 16:31:34 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = s;
	while (*ptr != '\0')
	{
		f(i, ptr);
		ptr++;
		i++;
	}
}

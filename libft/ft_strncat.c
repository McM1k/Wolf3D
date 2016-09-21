/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:06:16 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 16:04:33 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*ptr1;
	char		*ptr2;

	ptr1 = s1;
	ptr2 = (char *)s2;
	if ((n != 0) && (*ptr2 != '\0'))
	{
		while (*ptr1 != '\0')
			ptr1++;
		while ((n > 0) && (*ptr2 != '\0'))
		{
			*ptr1 = *ptr2;
			ptr1++;
			ptr2++;
			n--;
		}
		if (*ptr1 != '\0')
			*ptr1 = '\0';
	}
	return (s1);
}

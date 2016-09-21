/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:44:26 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 17:50:04 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstlast(t_list **alst)
{
	t_list		*ptr;

	if ((ptr = *alst) != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		return (ptr);
	}
	return (NULL);
}

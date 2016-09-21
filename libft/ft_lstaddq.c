/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:42:00 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 18:05:23 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddq(t_list **alst, t_list *new)
{
	t_list		*ptr;

	if ((ptr = ft_lstlast(alst)) != NULL)
		ptr->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:51:10 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/15 22:41:41 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lst_new;
	t_list		*ptr_new;
	t_list		*ptr;

	ptr = lst;
	lst_new = (*f)(ptr);
	ptr_new = lst_new;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		ptr_new->next = (*f)(ptr);
		ptr_new = ptr_new->next;
	}
	return (lst_new);
}

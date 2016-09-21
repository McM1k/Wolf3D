/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:03:54 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/15 16:43:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*nxt;

	tmp = *alst;
	while (tmp)
	{
		nxt = tmp->next;
		ft_lstdelone(&tmp, (*del));
		tmp = nxt;
	}
	*alst = NULL;
}

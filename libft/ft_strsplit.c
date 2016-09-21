/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:54:26 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/26 19:27:14 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_howmuchrow(char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		if (j)
			k++;
	}
	return (k);
}

static char		**ft_cutter(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j)
		{
			if ((tab[k] = ft_strsub(s, i, j)) == NULL)
			{
				ft_memdel((void **)tab);
				return (NULL);
			}
			i = i + j;
			k++;
		}
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			row;

	row = ft_howmuchrow(s, c);
	if (!(tab = ft_memalloc(sizeof(*tab) * (row + 1))))
		return (NULL);
	ft_cutter(tab, s, c);
	tab[row] = NULL;
	return (tab);
}

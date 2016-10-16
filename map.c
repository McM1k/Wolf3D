/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 18:26:30 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/15 20:49:39 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void fill1(int ***tab)
{
	(*tab)[2][4] = 1;
	(*tab)[2][5] = 1;
	(*tab)[2][8] = 1;
	(*tab)[2][9] = 1;
	(*tab)[3][9] = 1;
	(*tab)[5][2] = 1;
	(*tab)[5][3] = 1;
	(*tab)[5][4] = 1;
	(*tab)[5][7] = 1;
	(*tab)[5][8] = 1;
	(*tab)[8][3] = 1;
	(*tab)[8][5] = 1;
	(*tab)[8][7] = 1;
	(*tab)[8][9] = 1;
	(*tab)[9][2] = 1;
}

static void	edge(int ***tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < 11)
	{
		j = 1;
		while (j < 12)
		{
			if (i == 0 || j == 1 || i == 10 || j == 11)
				(*tab)[i][j] = 1;
			j++;
		}
		i++;
	}
	fill1(tab);
}

int			map(int ***tab)
{
	int		i;

	if (!(*tab = (int **)ft_memalloc(sizeof(int *) * 12)))
		return (0);
	i = 0;
	while (i < 11)
	{
		if (!((*tab)[i] = (int *)ft_memalloc(sizeof(int) * 12)))
		{
			while (--i >= 0)
				ft_memdel((void **)(&(*tab)[i]));
			ft_memdel((void **)(tab));
			return (0);
		}
		else
			(*tab)[i][0] = 11;
		i++;
	}
	(*tab)[11] = NULL;
	edge(tab);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:20:29 by gboudrie          #+#    #+#             */
/*   Updated: 2016/05/18 17:03:50 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		**ft_mat_id(int size)
{
	double		**mat;
	int			i;
	int			j;

	if (!(mat = (double **)ft_memalloc(sizeof(double **) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(mat[i] = (double *)ft_memalloc(sizeof(double *) * size)))
		{
			while (--i >= 0)
				ft_memdel((void **)(&mat[i]));
			return (NULL);
		}
		j = 0;
		while (j < size)
		{
			mat[i][j] = (i == j ? 1 : 0);
			j++;
		}
		i++;
	}
	mat[size] = NULL;
	return (mat);
}

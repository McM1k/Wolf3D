/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:26:29 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/08 18:22:24 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sizinator(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while ((n > 9) || (n < (-9)))
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char		*ft_asciinator(char *nbr, unsigned int nb, int len)
{
	len--;
	while (nb > 9)
	{
		nbr[len] = '0' + (nb % 10);
		nb = nb / 10;
		len--;
	}
	nbr[len] = '0' + nb;
	return (nbr);
}

char			*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	nb;
	int				len;
	int				i;

	i = 0;
	len = ft_sizinator(n);
	nbr = ft_strnew(len);
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		nbr[i] = '-';
		i++;
		nb = n * (-1);
	}
	else
		nb = n;
	nbr = ft_asciinator(nbr, nb, len);
	return (nbr);
}

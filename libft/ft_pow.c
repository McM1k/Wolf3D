/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 22:51:29 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/17 18:06:25 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_pow(double x, double pow)
{
	int			sign;
	int			tmp;

	sign = 0;
	tmp = x;
	if (pow < 0)
	{
		pow = pow * (-1);
		sign++;
	}
	while (pow > 1)
	{
		x *= tmp;
		pow--;
	}
	if (pow == 0)
		return (1);
	if (sign == 1)
		return (1 / x);
	return (x);
}

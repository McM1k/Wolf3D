/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:08:53 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/07 16:11:30 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_neg;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_neg = n * (-1);
	}
	else
		n_neg = n;
	if (n_neg >= 10)
	{
		ft_putnbr_fd(n_neg / 10, fd);
		ft_putnbr_fd(n_neg % 10, fd);
	}
	else
		ft_putchar_fd('0' + n_neg, fd);
}

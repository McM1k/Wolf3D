/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:36:07 by gboudrie          #+#    #+#             */
/*   Updated: 2016/09/20 16:31:11 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int			color(t_dot a, t_dot b, t_dot tmp)
{
	double			diff;
	unsigned char	*pa;
	unsigned char	*pb;
	unsigned char	*ptr;
	int				res;

	if (a.color == b.color)
		return (b.color);
	diff = (ft_abs(b.x - a.x) > ft_abs(b.y - a.y) ?
			(double)(tmp.x) / (double)(b.x - a.x) :
			(double)(tmp.y) / (double)(b.y - a.y));
	ptr = (unsigned char *)&res;
	pa = (unsigned char *)&a.color;
	pb = (unsigned char *)&b.color;
	ptr[0] = (pa[0] < pb[0] ? pa[0] + (pb[0] - pa[0]) * diff :
			pb[0] + (pa[0] - pb[0]) * (1 - diff));
	ptr[1] = (pa[3] < pb[1] ? pa[1] + (pb[1] - pa[1]) * diff :
			pb[1] + (pa[1] - pb[1]) * (1 - diff));
	ptr[2] = (pa[2] < pb[2] ? pa[2] + (pb[2] - pa[2]) * diff :
			pb[2] + (pa[2] - pb[2]) * (1 - diff));
	ptr[3] = (pa[1] < pb[3] ? pa[3] + (pb[3] - pa[3]) * diff :
			pb[3] + (pa[3] - pb[3]) * (1 - diff));
	return (res);
}

static void			x_dir(t_env env, t_dot a, t_dot b, double div)
{
	t_dot		tmp;

	tmp.x = 0;
	tmp.y = 0;
	while (a.x + tmp.x <= b.x)
	{
		img_addr(env, a.x + tmp.x, a.y + tmp.y, color(a, b, tmp));
		tmp.x++;
		tmp.y = tmp.x * div;
	}
}

static void			y_dir(t_env env, t_dot a, t_dot b, double div)
{
	t_dot		tmp;

	tmp.x = 0;
	tmp.y = 0;
	while (a.y + tmp.y != b.y)
	{
		img_addr(env, a.x + tmp.x, a.y + tmp.y, color(a, b, tmp));
		tmp.y = (a.y < b.y ? tmp.y + 1 : tmp.y - 1);
		tmp.x = tmp.y / div;
		if (a.y + tmp.y == b.y)
			img_addr(env, a.x + tmp.x, a.y + tmp.y, b.color);
	}
}

void				segment(t_env env, t_dot a, t_dot b)
{
	double		div;

	if ((a.x > SIZE_X && b.x > SIZE_X) || (a.x <= 0 && b.x <= 0) ||
		(a.y > SIZE_Y && b.y > SIZE_Y) || (a.y <= 0 && b.y <= 0))
		return ;
	(a.x > b.x ? ft_swap(&a.color, &b.color) : (void)0);
	(a.x > b.x ? ft_swap(&a.y, &b.y) : (void)0);
	(a.x > b.x ? ft_swap(&a.x, &b.x) : (void)0);
	div = (double)(b.y - a.y) / (double)(b.x - a.x);
	if (div >= -1 && div <= 1)
		x_dir(env, a, b, div);
	else
		y_dir(env, a, b, div);
}

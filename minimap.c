/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 20:45:50 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/05 22:25:07 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz - 1 || x <= 0 || y <= 0
		  || x > SIZE_X - 1 || y > SIZE_Y - 1))
		ft_memcpy(&env.img[(x - 1) * 4 + (y - 1) * env.siz], &color, 4);
}

static void		cursor(t_env env)
{
	t_dot	a;
	t_dot	b;

	a.x = (int)(env.pos_x * 20);
	a.y = (int)(env.pos_y * 20);
	a.color = 0x00FF0000;
	img_addr(env, a.x + 1, a.y - 1, 0x11FF0000);
	img_addr(env, a.x - 1, a.y + 1, 0x11FF0000);
	img_addr(env, a.x + 1, a.y + 1, 0x11FF0000);
	img_addr(env, a.x - 1, a.y - 1, 0x11FF0000);
	b.x = a.x + 8 * cos(env.orientation);
	b.y = a.y + 8 * sin(env.orientation);
	b.color = 0x5577AA00;
	segment(env, a, b);
	dda(env);
}

void			minimap(t_env env)
{
	int		x;
	int		y;

	x = 0;
	while (env.tab[(int)(x / 20)] != NULL)
	{
		y = 20;
		while ((int)(y / 20) <= env.tab[(int)(x / 20)][0])
		{
			if (x % 20 == 0 || y % 20 == 0)
				img_addr(env, y - 20, x, 0xBB4F4F4F);
			else if (env.tab[(int)(x / 20)][(int)(y / 20)] == 1)
				img_addr(env, y - 20, x, 0xBB7F7F7F);
			else
				img_addr(env, y - 20, x, 0xBBFFFFFF);
			y++;
		}
		x++;
	}
	cursor(env);
	dda(env);
}

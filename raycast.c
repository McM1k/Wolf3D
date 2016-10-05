/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:48:18 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/05 22:35:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	init_dda(t_coor *start, t_coor *step, t_coor *flag, t_env env)
{
	flag->x = 1;
	flag->y = 1;
	step->x = 1 / cos(env.orientation);
	step->y = 1 / sin(env.orientation);
	if (env.orientation > PI)
	{
		start->x = (env.pos_x - (int)(env.pos_x)) * step->x;
		flag->x = -1;
	}
	else
		start->x = (env.pos_x * (-1) + 1.0 + (int)(env.pos_x)) * step->x;
	if (env.orientation < (PI / 2) && env.orientation >= PI * (3 / 2))
	{
		start->y = (env.pos_y - (int)(env.pos_y)) * step->y;
		flag->y = -1;
	}
	else
		start->y = (env.pos_y * (-1) + 1.0 + (int)(env.pos_y)) * step->y;
	return (0);
}

void		dda(t_env env)
{
	t_coor	dist;
	t_coor	step;
	t_coor	flag;
	t_dot	cell;
	int		hit;

	hit = init_dda(&dist, &step, &flag, env);
	cell.x = (int)(env.pos_x);
	cell.y = (int)(env.pos_y);
	while (hit == 0)
	{
		if (dist.x < dist.y)
		{
			dist.x += step.x;
			cell.x += flag.x;
			img_addr(env, (cell.x + 0.5) * 20, (cell.y + 0.5) * 20, 0x000000FF);
		}
		else
		{
			dist.y += step.y;
			cell.y += flag.y;
			img_addr(env, (cell.x + 0.5) * 20, (cell.y + 0.5) * 20, 0x000000FF);
		}
		if (env.tab[cell.y][cell.x + 1] > 0)
			hit = 1;
	}
	img_addr(env, (cell.x + 0.5) * 20, (cell.y + 0.5) * 20, 0x0000DD30);
}

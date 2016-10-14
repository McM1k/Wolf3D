/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:48:18 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/14 18:27:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** The only purpose of this function is to initialise 7 variables
** Start for the first distance before one collision
** Step for the dstance between each collision after start
** Flag to keep in memory which direction the ray is going (E,W,S,N)
** And the hit value, which is a sorta bool that will be true after collision
*/

static void	init_dda(t_coor *start, t_coor *step, t_coor *flag, t_env env)
{
	flag->x = 1;
	flag->y = 1;
	step->x = (1.0 / cos(env.ray) > 1000 ? 1000 : 1.0 / cos(env.ray));
	step->y = (1.0 / sin(env.ray) > 1000 ? 1000 : 1.0 / sin(env.ray));
	if (step->x < 0)
		step->x *= -1.0;
	if (step->y < 0)
		step->y *= -1.0;
	if ((env.ray > PI && env.ray <= 2 * PI) || env.ray < 0)
	{
		start->y = (env.pos_y - (int)(env.pos_y)) * step->y;
		flag->y = -1;
	}
	else
		start->y = (env.pos_y * (-1) + 1.0 + (int)(env.pos_y)) * step->y;
	if ((env.ray > PI / 2) && (env.ray <= (PI * 3) / 2))
	{
		start->x = (env.pos_x - (int)(env.pos_x)) * step->x;
		flag->x = -1;
	}
	else
		start->x = (env.pos_x * (-1) + 1.0 + (int)(env.pos_x)) * step->x;
	start->x = (start->x > 1000 ? 1000 : start->x);
	start->y = (start->y > 1000 ? 1000 : start->y);
}

static void	colour_walls(t_env *env, t_coor dist)
{
	if (dist.x > (int)env->pos_x)
		env->col = 0x00FF0000;
	else
 		env->col = 0x00880000;
	if (dist.y > (int)env->pos_y)
		env->col += 0x00008800;
	else
		env->col += 0x0000FF00;
}

double		dda(t_env *env)
{
	t_coor	dist;
	t_coor	tmp;
	t_coor	step;
	t_coor	flag;
	t_dot	cell;

	init_dda(&dist, &step, &flag, *env);
	cell.x = (int)(env->pos_x);
	cell.y = (int)(env->pos_y);
	while (env->tab[cell.y][cell.x + 1] == 0)
	{
		tmp.x = dist.x;
		tmp.y = dist.y;
		if (dist.x < dist.y && (tmp.x += step.x))
			cell.x += flag.x;
		else
		{
			tmp.y += step.y;
			cell.y += flag.y;
		}
		if (!(env->tab[cell.y][cell.x + 1] > 0) && (dist.x = tmp.x))
			dist.y = tmp.y;
	}
	colour_walls(env, dist);
	return ((dist.x < dist.y ? dist.x : dist.y));
}

void		raycast(t_env env)
{
	double	add;
	double	dist;
	t_dot	bot;
	t_dot	top;

	add = (PI / 3) / SIZE_X;
	env.ray = env.orientation - (PI / 6);
	bot.x = 0;
	top.x = 0;
	while (bot.x < SIZE_X)
	{
		dist = dda(&env) * cos(env.ray - env.orientation);
		bot.y = (SIZE_Y / 2) - ((SIZE_Y / dist) / 2);
		top.y = (SIZE_Y / 2) + ((SIZE_Y / dist) / 2);
		bot.color = env.col;
		top.color = env.col;
		segment(env, bot, top);
		env.ray += add;
		bot.x++;
		top.x++;
	}
}

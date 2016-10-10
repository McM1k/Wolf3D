/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:48:18 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/10 20:44:56 by gboudrie         ###   ########.fr       */
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

static int	init_dda(t_coor *start, t_coor *step, t_coor *flag, t_env env)
{
	flag->x = 1;
	flag->y = 1;
	step->x = 1.0 / cos(env.ray);
	step->y = 1.0 / sin(env.ray);
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
	printf("start : x = %lf, y = %lf\n", start->x, start->y);
	printf("step : x = %lf, y = %lf\n", step->x, step->y);
	return (0);
}

static void	colour_walls(t_env *env, t_coor flag)
{
	if (flag.x > 0 && flag.y > 0)
		env->col = 0x00FF0000;
	else if (flag.x > 0 && flag.y <= 0)
		env->col = 0x00FF8800;
	else if (flag.x <= 0 && flag.y > 0)
		env->col = 0x00FFFF00;
	else
		env->col = 0x0000FF00;
}

double		dda(t_env *env)
{
	t_coor	dist;
	t_coor	step;
	t_coor	flag;
	t_dot	cell;
	int		hit;

	hit = init_dda(&dist, &step, &flag, *env);
	cell.x = (int)(env->pos_x);
	cell.y = (int)(env->pos_y);
	while (hit == 0)
	{
		if (dist.x < dist.y)
		{
			dist.x += step.x;
			cell.x += flag.x;
			img_addr(*env, (cell.x + 0.5) * 20, (cell.y + 0.5) * 20, 0x000000FF);
		}
		else
		{
			dist.y += step.y;
			cell.y += flag.y;
			img_addr(*env, (cell.x + 0.5) * 20, (cell.y + 0.5) * 20, 0x000000FF);
		}
		if (env->tab[cell.y][cell.x + 1] > 0)
			hit = 1;
	}
	img_addr(*env, (cell.x + 0.5) * 20, (cell.y + 0.5) * 20, 0x0000DD30);
	colour_walls(env, flag);
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
		dist = dda(&env);
		printf("%lf\n", dist);
		bot.y = (SIZE_Y / 2) - ((SIZE_Y / dist) / 2);
		top.y = (SIZE_Y / 2) + ((SIZE_Y / dist) / 2);
		bot.color = env.col;
		top.color = env.col;
		segment(env, bot, top);
		img_addr(env, (int)((env.pos_x + dist * cos(env.ray)) * 20), (int)((env.pos_y + dist * sin(env.ray)) * 20), 0x00FF00FF);
		env.ray += add;
		bot.x++;
		top.x++;
	}

//	env.ray = env.orientation;
//	dist = dda(env);
//	img_addr(env, (int)((env.pos_x + dist * cos(env.orientation)) * 20), (int)((env.pos_y + dist * sin(env.orientation)) * 20), 0x00FF00FF);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:26:00 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/14 19:16:05 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			key_funct(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	events(keycode, env);

	return (1);
}

static void	collide(int keycode, t_env *env)
{
	t_coor	tmp;

	if (keycode == 2 || keycode == 0)
	{
		tmp.x = 0.1 * sin(env->orientation);
		tmp.y = -0.1 * cos(env->orientation);
	}
	else
	{
		tmp.x = 0.1 * cos(env->orientation);
		tmp.y = 0.1 * sin(env->orientation);
	}
	if (keycode == 2 || keycode == 1 || keycode == 125)
	{
		tmp.x *= -1;
		tmp.y *= -1;
	}
	if (env->tab[(int)(env->pos_y)][(int)(env->pos_x + 3 * tmp.x + 1)] == 0)
		env->pos_x += tmp.x;
	if (env->tab[(int)(env->pos_y + 3 * tmp.y)][(int)(env->pos_x + 1)] == 0)
		env->pos_y += tmp.y;
}

void		events(int keycode, t_env *env)
{
	if (keycode == 53)
		destroy_funct(env);
	if (keycode == 123 || keycode == 124)
	{
		env->orientation += (keycode == 124 ? 0.1 : -0.1);
		if (env->orientation > 2 * PI)
			env->orientation -= 2 * PI;
		if (env->orientation < 0)
			env->orientation += 2 * PI;
	}
	if (keycode == 125 || keycode == 126 || keycode == 13 || keycode == 1
		|| keycode == 0 || keycode == 2)
		collide(keycode, env);
	ft_bzero(env->img, SIZE_X * SIZE_Y * 4);
	raycast(*env);
	minimap(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->ig, 0, 0);
}

int			destroy_funct(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	mlx_destroy_image(env->mlx, env->ig);
	mlx_destroy_window(env->mlx, env->win);
	ft_putendl("Closing program.");
	exit(0);
	return (1);
}

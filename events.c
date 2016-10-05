/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:26:00 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/05 19:46:47 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_funct(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	events(keycode, env);

	return (1);
}

void	events(int keycode, t_env *env)
{
	if (keycode == 53) //ESC
		destroy_funct(env);
	if (keycode == 123 || keycode == 124) //LEFT
	{
		env->orientation += (keycode == 124 ? 0.1 : -0.1);
		if (env->orientation > 2 * PI)
			env->orientation -= 2 * PI;
		if (env->orientation < 0)
			env->orientation += 2 * PI;
	}
	if (keycode == 125) //DOWN
	{
		env->pos_x -= 0.05 * cos(env->orientation);
		env->pos_y -= 0.05 * sin(env->orientation);
	}
	if (keycode == 126) //UP
	{
		env->pos_x += 0.05 * cos(env->orientation);
		env->pos_y += 0.05 * sin(env->orientation);
	}
	ft_bzero(env->img, SIZE_X * SIZE_Y * 4);
	minimap(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->ig, 0, 0);
}

int		mouse_funct(int x, int y, t_env *env)
{
	env->curs_x = (double)x;
	env->curs_y = (double)y;
	return (1);
}

int		clic_funct(int button, int x, int y, t_env *env)
{
	if (button == 1)
		events(69, env);
	x = y;

	return (0);
}

int		destroy_funct(void *param)
{
	t_env*env;

	env = (t_env *)param;
	mlx_destroy_image(env->mlx, env->ig);
	mlx_destroy_window(env->mlx, env->win);
	ft_putendl("Closing program.");
	exit(0);
	return (1);
}

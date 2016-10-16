/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:16:43 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/15 21:08:08 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	env->pos_x = -1;
	while (env->tab[x])
	{
		y = 1;
		while (y <= env->tab[x][0])
		{
			if (env->tab[x][y] == 0 && env->pos_x == -1)
			{
				env->pos_x = x + 0.5;
				env->pos_y = y - 0.5;
			}
			y++;
		}
		x++;
	}
	env->orientation = PI / 2;
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac == 1 && (env.mlx = mlx_init()) &&
		(env.win = mlx_new_window(env.mlx, SIZE_X, SIZE_Y, "Wolf3d")) &&
		(env.ig = mlx_new_image(env.mlx, SIZE_X, SIZE_Y)) &&
		(env.img = mlx_get_data_addr(env.ig, &(env.bit), &(env.siz), &(env.ed)))
		&& (map(&(env.tab))))
		{
			init(&env);
			raycast(env);
			minimap(env);
			mlx_put_image_to_window(env.mlx, env.win, env.ig, 0, 0);
			mlx_hook(env.win, 2, 0, key_funct, &env);
			mlx_hook(env.win, 17, 0, destroy_funct, &env);
			mlx_loop(env.mlx);
	}
	else
	{
		ft_putstr("memory allocation failed, closing program ");
		ft_putendl(av[0]);
	}
	return (0);
}

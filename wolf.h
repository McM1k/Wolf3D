/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:27:05 by gboudrie          #+#    #+#             */
/*   Updated: 2016/10/15 21:08:34 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
#include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# define SIZE_X 1920
# define SIZE_Y 1080
# define PI 3.14159265358979323846

typedef struct	s_coor
{
	double		x;
	double		y;
}				t_coor;

typedef struct	s_dot
{
	int			x;
	int			y;
	int			color;
}				t_dot;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*ig;
	char		*img;
	int			siz;
	int			bit;
	int			ed;
	double		pos_x;
	double		pos_y;
	double		orientation;
	double		ray;
	int			col;
	int			**tab;
}				t_env;

int				map(int ***tab);
void			img_addr(t_env env, int x, int y, int color);
int				key_funct(int keycode, void *param);
void			events(int keycode, t_env *env);
int				destroy_funct(void *param);
void			minimap(t_env env);
void			segment(t_env env, t_dot a, t_dot b);
double			dda(t_env *env);
void			raycast(t_env env);
#endif

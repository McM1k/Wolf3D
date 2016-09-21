/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:39:22 by gboudrie          #+#    #+#             */
/*   Updated: 2016/09/19 17:55:06 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		*separator(char *str, int *tab)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_strsplit(str, ' ');
	i = 0;
	while (tmp[i])
		i++;
	if ((tab = ft_memalloc((i + 1) * 4)) == NULL)
	{
		ft_tabdel((void ***)&tmp);
		return (NULL);
	}
	j = 0;
	while (j++ < i)
		tab[j] = ft_atoi(tmp[j - 1]);
	tab[0] = i;
	ft_tabdel((void ***)&tmp);
	return (tab);
}

static int		**init_tab(int *fd, int **tab, char *arg)
{
	char		*str;
	int			tmp;
	int			gnl;

	tmp = 0;
	while ((gnl = get_next_line(*fd, &str)) == 1)
	{
		if ((ft_strlen(str)) == 0)
		{
			ft_memdel((void **)&str);
			close(*fd);
			return (NULL);
		}
		ft_memdel((void **)&str);
		tmp++;
	}
	close(*fd);
	if (gnl == -1 ||
		(tab = (int **)ft_memalloc(sizeof(int *) * tmp + 1)) == NULL)
		return (NULL);
	*fd = open(arg, O_RDONLY);
	tab[tmp + 1] = NULL;
	return (tab);
}

int				**reader(int fd, char *arg, int **tab)
{
	char	*str;
	int		i;
	int		gnl;

	i = 0;
	if ((tab = init_tab(&fd, tab, arg)) == NULL)
		return (NULL);
	while ((gnl = get_next_line(fd, &str)) == 1)
	{
		if ((tab[i] = separator(str, tab[i])) == NULL
			|| (i > 0 && tab[i][0] != tab[i - 1][0]))
		{
			while (i-- >= 0)
				ft_memdel((void **)&tab[i + 1]);
			ft_memdel((void **)&tab);
			close(fd);
			return (NULL);
		}
		i++;
		ft_memdel((void **)&str);
	}
	tab[i] = NULL;
	close(fd);
	return (gnl == 0 ? tab : NULL);
}

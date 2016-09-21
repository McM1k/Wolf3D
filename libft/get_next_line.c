/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/17 17:31:14 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd	*new_node(int fd)
{
	t_fd	*new;

	new = (t_fd *)ft_memalloc(sizeof(t_fd));
	new->fd = fd;
	new->str = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

static t_fd	*is_node_existing(int fd, t_fd *begin)
{
	t_fd	*tmp;
	t_fd	*node;

	tmp = begin;
	node = tmp;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		tmp = node;
		node = node->next;
	}
	node = new_node(fd);
	tmp->next = node;
	return (node);
}

static int	alloc_less(t_fd *ptr, t_fd *begin, int rd)
{
	int		size;
	t_fd	*tmp;
	t_fd	*tmp2;
	char	*str_tmp;

	if (rd > 0)
	{
		size = ft_strchr(ptr->str, '\n') - ptr->str + 1;
		str_tmp = ft_strsub(ptr->str, size, ft_strlen(ptr->str) - (size));
		ft_strdel(&ptr->str);
		ptr->str = str_tmp;
	}
	size = ft_strlen(ptr->str);
	if (rd == 0 && ptr->fd != 0)
	{
		tmp2 = begin;
		while (tmp2->fd != ptr->fd && (tmp = tmp2))
			tmp2 = tmp2->next;
		tmp->next = tmp2->next;
		ft_strdel(&ptr->str);
		ft_memdel((void **)&ptr);
	}
	return (size);
}

static int	reader(int rd, t_fd *node, int fd)
{
	char	*buf;
	char	*tmp;

	if (BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!ft_strchr(node->str, '\n') && rd > 0)
	{
		if ((rd = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (rd > 0)
		{
			buf[rd] = '\0';
			tmp = node->str;
			node->str = ft_strjoin(tmp, buf);
			ft_strdel(&tmp);
			rd = 1;
		}
	}
	ft_strdel(&buf);
	return (rd);
}

int			get_next_line(int const fd, char **line)
{
	static t_fd		*begin = NULL;
	t_fd			*ptr;
	int				rd;

	if (!begin)
		begin = new_node(0);
	ptr = is_node_existing(fd, begin);
	rd = 1;
	if ((rd = reader(rd, ptr, fd)) == -1)
		return (-1);
	if (rd == 0 && ft_strlen(ptr->str) > 0)
		*line = ft_strsub(ptr->str, 0, ft_strlen(ptr->str));
	else if (rd > 0)
		*line = ft_strsub(ptr->str, 0, ft_strchr(ptr->str, '\n') - ptr->str);
	if (ptr->fd == 0 && rd == 0)
	{
		if (ft_strlen(ptr->str) == 0)
			return (0);
		ft_strdel(&ptr->str);
		ptr->str = ft_strnew(BUFF_SIZE);
		return (1);
	}
	return (!((alloc_less(ptr, begin, rd) == 0) && (rd == 0)));
}

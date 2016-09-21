/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:37:46 by gboudrie          #+#    #+#             */
/*   Updated: 2016/06/08 13:31:19 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# define BUFF_SIZE 50000

int				get_next_line(int const fd, char **line);

typedef struct	s_fd
{
	int			fd;
	char		*str;
	struct s_fd	*next;
}				t_fd;

#endif

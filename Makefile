#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/08 21:26:14 by gboudrie          #+#    #+#              #
#    Updated: 2016/10/15 20:06:55 by gboudrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = wolf3d

MKLIB = make -C libft/

INCLUDES = libft/libft.a

CC = gcc

HEADER = wolf.h

FLAGS = -Wall -Wextra -Werror

SOURCES = main.c events.c raycast.c reader.c segment.c minimap.c map.c

OBJS = $(SOURCES:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all :			$(NAME)

$(NAME) :		$(OBJS) $(HEADER) Makefile
				$(MKLIB)
				$(CC) $(FLAGS) -c $(SOURCES)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)


fonly :
				$(CC) $(FLAGS) -c $(SOURCES)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)

norm :
				norminette $(SOURCES)

meteo :
				curl http://wttr.in/Paris
				curl http://wttr.in/Moon

america great again :
				@echo "#############################################"
				@echo "#                                           #"
				@echo "# ####     ##   ##  ##   ##   ##     ####   #"
				@echo "# #####   ####  ### ##   ##   ##     #####  #"
				@echo "# ##  ## ###### ######  ####  ##     ##  ## #"
				@echo "# ##  ## ##  ## ######  #  #  ##     ##  ## #"
				@echo '# ##  ## ##  ## ###### ##  ## ##     ##  ## #'
				@echo '# ##  ## ###### ###### ###### ##     ##  ## #'
				@echo '# #####   ####  ## ### ##  ## ##     #####  #'
				@echo '# ####     ##   ##  ## ##  ## ###### ####   #'
				@echo '#                                           #'
				@echo '#############################################'
				@echo '#                                           #'
				@echo '#     ###### #####  ##  ## #    # #####     #'
				@echo '#     ###### ##  ## ##  ## ##  ## ##  ##    #'
				@echo '#       ##   ##  ## ##  ## ###### ##  ##    #'
				@echo '#       ##   #####  ##  ## ##  ## #####     #'
				@echo '#       ##   ###    ##  ## ##  ## ##        #'
				@echo '#       ##   ####   ##  ## ##  ## ##        #'
				@echo '#       ##   ## ##  ###### ##  ## ##        #'
				@echo '#       ##   ##  ##  ####  ##  ## ##        #'
				@echo '#                                           #'
				@echo '#############################################'


clean :
				-rm -f $(OBJS)

fclean :		clean
				$(MKLIB) fclean
				-rm -f $(NAME)

re :			fclean all


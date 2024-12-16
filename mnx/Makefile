# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 13:31:09 by jvasquez          #+#    #+#              #
#    Updated: 2024/09/01 15:37:37 by jvasquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = menu.a

.SILENT:

INCLUDES = -I../libft -I../include -I../mnx -I../minilibx-linux
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g
CC = gcc
DIR_SRC	= 
FUNCTIONS =	tools.c		\
			controls.c	\
			hooks.c		\
			draw.c		\
			image.c		\
			innit.c		\
			destroy.c	\
			drag.c

#OBJS = $(addprefix $(DIR_SRC), ${FUNCTIONS:.c=.o})
OBJS = ${FUNCTIONS:.c=.o}

UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
	LIBTOOL = libtool -static -o $(NAME) $(NAME) ../libft/libft.a
else
	LIB = ../libft/libft.a
endif


${NAME}:	${OBJS}
			$(AR) -rcT $@ ${OBJS} $(LIB)
			$(LIBTOOL)
# $(CC) $(CFLAGS) ${OBJS} Libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
			rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all
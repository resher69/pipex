# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 03:50:43 by agardet           #+#    #+#              #
#    Updated: 2021/06/27 08:59:54 by agardet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c\
			setup.c\
			parsing.c

OBJS		= ${SRCS:.c=.o}

NAME		= pipex

INC			= libft.h

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%.o : %.c	${INC}
			${CC} ${CFLAGS} -I includes/ -c $< -o $@

${NAME}:	${OBJS}		includes/pipex.h
			make -C libft/
			cp libft/libft.a pipex
			ar -rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	 all clean fclean re
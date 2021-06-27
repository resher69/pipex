# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 11:25:36 by agardet           #+#    #+#              #
#    Updated: 2021/06/27 11:31:18 by agardet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re
.SUFFIXES: .c .o .h .a
EXEC = pipex
EXEC_LIBFT = libft/libft.a
SRCS = main.c	parsing.c	setup.c
OBJS = $(SRCS:.c=.o)
OBJDIR = objects/
SRCDIR = sources/
LIBDIR = libft/
INCDIR = includes/
CFLAGS = -Wall -Wextra -Werror
LIBS =  -lft
VPATH = sources/:includes/:objects/

all: $(EXEC_LIBFT) $(EXEC)


$(EXEC_LIBFT):
	make -C $(LIBDIR)
$(EXEC): $(OBJS)
	cc $(CFLAGS) $(addprefix $(OBJDIR), $(notdir $^)) -L $(LIBDIR)  $(LIBS) -o $(EXEC)
%.o: %.c
	cc -c $(CFLAGS) $< -I $(INCDIR) -I $(LIBDIR) -o $(addprefix $(OBJDIR), $@)
clean:
	make -C $(LIBDIR) clean
	$(RM) $(addprefix $(OBJDIR), $(OBJS))
fclean:
	make -C $(LIBDIR) fclean
	$(RM) $(addprefix $(OBJDIR), $(OBJS))
	$(RM) $(EXEC)
re: fclean all
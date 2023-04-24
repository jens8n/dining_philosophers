# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 16:41:43 by jebucoy           #+#    #+#              #
#    Updated: 2023/04/24 20:21:03 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

HEADER	=	./include

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g -I $(HEADER) -pthread

SRCS	=	main.c \
			parsing.c \
			init.c	\
			philo_routine.c \

OBJS	= $(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all	:	$(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 16:41:43 by jebucoy           #+#    #+#              #
#    Updated: 2023/05/09 18:00:36 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

HEADER	=	./include

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror  -g -I $(HEADER) -pthread #-fsanitize=address

SRCS	=	main.c \
			parsing.c \
			init.c	\
			philo_routine.c \
			utils.c \
			task_msg.c \

OBJS	= $(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all	:	$(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	: fclean all
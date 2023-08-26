# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 16:41:43 by jebucoy           #+#    #+#              #
#    Updated: 2023/08/17 22:02:35 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus

HEADER	=	./include

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror  -g3 -I $(HEADER) -pthread #-fsanitize=address

SRCS	=	main.c \
			parsing.c \
			utils.c \
			init.c \
			strjoin.c \
			itoa.c \
			tasks.c \

OBJS	= $(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all	:	$(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	: fclean all
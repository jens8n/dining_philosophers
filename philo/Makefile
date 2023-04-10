# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 16:41:43 by jebucoy           #+#    #+#              #
#    Updated: 2023/04/10 16:50:58 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g -I ./includes 

CC	=	cc

SRCS	=	philotest.c \

OBJS	= $(SRCS:.c=.o)

$(NAME)	:	$(NAME)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all	:	$(NAME)

clean	:
		rm -rf $(OBJS)

fclean	:
		rm -rf $(NAME)

re	: fclean all
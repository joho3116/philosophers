# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 18:20:38 by hojo              #+#    #+#              #
#    Updated: 2021/12/07 19:21:25 by hojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c \
			srcs/life.c \
			srcs/check.c \
			srcs/print.c \
			srcs/util.c \
			srcs/ft_atoi.c \
			srcs/ft_calloc.c \
			srcs/ft_put_fd.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	philo
RM		=	rm -f
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME) 	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

all		:	$(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

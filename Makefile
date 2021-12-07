# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hojo <hojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 18:20:38 by hojo              #+#    #+#              #
#    Updated: 2021/12/07 18:39:31 by hojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c \
			srcs/life.c \
			srcs/check.c \
			srcs/print.c \
			srcs/util.c \

OBJS	=	$(SRCS:.c=.o)
HEADER	=	include/philosopher.h
LIBFT	=	libft/libft.a

NAME = philo_one
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all				: $(NAME)

$(LIBFT)		:
	$(MAKE) -C ./libft

%.o				: %.c $(HEADERS)
	$(CC) $< $(HEADER_DIR) $(CFLAGS) -c -o $@

$(NAME)			: $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(LIBFT) $(HEADER_DIR) $(CFLAGS) -o $(NAME)

clean			:
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean			: clean
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re				: fclean all

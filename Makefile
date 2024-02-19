# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 09:59:37 by ifluxa-c          #+#    #+#              #
#    Updated: 2024/02/19 12:00:51 by ifluxa-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
LIBFT_NAME = libft.a

SRC =	./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./sources/so_long.c \
		./sources/print.c \
		./sources/map.c \
		./sources/checker.c

OBJS = ${SRC:.c=.o}

LIBFT_DIR := ./libft/
HEADER := ./include/

MLX	= -l mlx -framework OpenGL -framework AppKit
CC := gcc
CFLAGS := -Wall -Wextra -Werror  
RM := rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(HEADER) -o $@ 

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	gcc $(OBJS) $(MLX) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

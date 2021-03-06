# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeltrao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 16:20:56 by cbeltrao          #+#    #+#              #
#    Updated: 2018/11/22 01:56:17 by cbeltrao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRCS = src/main.c src/draw.c src/julia.c src/mandelbrot.c src/controls.c \
	   src/mine.c src/zoom.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIB = -L libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx_macos	
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBX) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C minilibx_macos clean

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

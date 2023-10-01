# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 17:05:36 by arigonza          #+#    #+#              #
#    Updated: 2023/07/10 17:05:37 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF	= fdf
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
MINILIBX = ./lib/minilibx-linux

INC = -I ./lib/includes -I
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
MLXFLAG = -lmlx -lXext -lX11
SRCS = $(shell find . -iname "*.c")
OBJS = ${SRCS:.c=.o}

all: minilibx $(FDF)

minilibx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(FDF): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, minilibx
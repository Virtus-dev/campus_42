# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:15:35 by arigonza          #+#    #+#              #
#    Updated: 2023/02/19 11:10:49 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
ARFLAGS = crs

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm

RMFLAG = -f

SRC =	./ft_printf.c\
	./ft_printf_utils.c\

OBJS = $(SRC:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
		$(RM) $(RMFLAG) $(NAME)

re : fclean all

.c.o : $(SRC) $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re

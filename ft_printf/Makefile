# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 17:52:08 by arigonza          #+#    #+#              #
#    Updated: 2023/05/01 17:52:20 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
ARFLAGS = crs

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm

RMFLAG = -f

INCLUDES = ./ft_printf.h

SRC = ./ft_printf.c\
      ./ft_printf_utils.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

%o : $(SRC) $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re

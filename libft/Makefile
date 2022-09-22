# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:15:35 by arigonza          #+#    #+#              #
#    Updated: 2022/09/22 12:25:36 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm

RMFLAG = -f

INCLUDES = ./libft.h

SRC =	./ft_isalpha.c\
	  	./ft_isdigit.c\
		./ft_isascii.c\
		./ft_isprint.c\
		./ft_strlen.c\
		./ft_memset.c\
		./ft_bzero.c\
		./ft_memcpy.c\

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

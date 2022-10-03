# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:15:35 by arigonza          #+#    #+#              #
#    Updated: 2022/10/03 12:52:14 by arigonza         ###   ########.fr        #
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
		./ft_isalnum.c\
		./ft_isascii.c\
		./ft_isprint.c\
		./ft_strlen.c\
		./ft_memset.c\
		./ft_bzero.c\
		./ft_memcpy.c\
		./ft_memmove.c\
		./ft_strlcpy.c\
		./ft_strlcat.c\
		./ft_strchr.c\
		./ft_strrchr.c\
		./ft_tolower.c\
		./ft_toupper.c\
		./ft_strncmp.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_strnstr.c\
		./ft_atoi.c\
		./ft_calloc.c\
		./ft_strdup.c\
		./ft_substr.c\
		./ft_strjoin.c\
		./ft_strtrim.c\

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

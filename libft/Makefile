# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:15:35 by arigonza          #+#    #+#              #
#    Updated: 2022/10/18 18:01:56 by arigonza         ###   ########.fr        #
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
		./ft_split.c\
		./ft_itoa.c\
		./ft_strmapi.c\
		./ft_striteri.c\
		./ft_putchar_fd.c\
		./ft_putstr_fd.c\
		./ft_putendl_fd.c\
		./ft_putnbr_fd.c\

BONUS = ./ft_lstnew_bonus.c\
		./ft_lstadd_front_bonus.c\
		./ft_lstsize_bonus.c\
		./ft_lstlast_bonus.c\
		./ft_lstadd_back_bonus.c\
		./ft_lstdelone_bonus.c\
		./ft_lstclear_bonus.c\
		./ft_lstiter_bonus.c\
		./ft_lstmap_bonus.c\

OBJS = $(SRC:.c=.o)

OBJSBONUS = $(BONUS:.c=.o)

$(OBJSBONUS) : $(BONUS)
	$(CC) $(FLAGS) -c $(BONUS)

bonus : $(OBJS) $(OBJSBONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJSBONUS)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS)


fclean : clean
		$(RM) $(RMFLAG) $(OBJSBONUS) $(NAME)

re : fclean all

.c.o : $(SRC) $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re

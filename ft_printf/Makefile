# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 17:52:08 by arigonza          #+#    #+#              #
#    Updated: 2023/07/16 18:05:32 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

AR = ar
ARFLAGS = crs

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm

RMFLAG = -rf

INCLUDES = ./ft_printf.h

SRC = ./ft_printf.c\
      ./ft_printf_utils.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

clean :
	@echo "Cleaning..."
	@$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	@echo "Full clean..."
	@$(RM) $(RMFLAG) $(NAME)

re : fclean all

%o : $(SRC) $(INCLUDES)
	@echo "Compiling..."
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
	@echo "Creating library..."
	@$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re

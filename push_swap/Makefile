

CFLAGS = -Wall -Wextra -Werror

PUSH_SWAP = push_swap

LIBFT = libft/libft.a

INC = -I libft/includes

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(LIBFT) $(SRC)
	@gcc $(CFLAGS) $(INC) -o $(PUSH_SWAP) $(SRC) $(LIBFT)

$(LIBFT) :
	@make -s -C libft
	@echo "|---------------------------|"
	@echo "|  Compiling Push_swap🤖🤖 |"
	@echo "|---------------------------|"

clean :
	@make -s -C libft clean
	@echo 🔥🔥 Deleting all .o files 🗑️🗑️

fclean : clean
	@make -C libft fclean
	@rm -rf $(PUSH_SWAP)
	@echo executing fclean...
	@echo 🔥🔥deleting executables files 🗑️🗑️

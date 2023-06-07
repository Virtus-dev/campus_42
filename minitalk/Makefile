CFLAGS  = -Wall -Wextra -Werror

CLIENT = client 

SERVER = server

LIBFT = libft/libft.a

INC = -I libft/includes

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) client.c
	@gcc $(CFLAGS) $(INC) -o $(CLIENT) client.c $(LIBFT)

$(SERVER): $(LIBFT) server.c
	@gcc $(CFLAGS) $(INC) -o $(SERVER) server.c $(LIBFT)

$(LIBFT):
	@make -s -C libft
	@echo "|-----------------------------------|"
	@echo "|       Compiling libft📚 ✅✅     |"
	@echo "|-----------------------------------|"

bonus : all

clean:
	@make -s -C libft clean
	@echo 🔥 🔥 Deleting all .o Files 🗑️ 🗑️

fclean: clean
	@make -C libft fclean
	@rm -rf $(CLIENT) $(SERVER)
	@echo  🔥 🔥 Deleting executables files 🗑️ 🗑️
	@echo "<----------------------------------->"

re: fclean all

rebonus : fclean all

.PHONY: all bonus clean fclean re rebonus
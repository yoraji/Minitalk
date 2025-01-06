CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus 

LIBFT_DIR = ./libft/
PRINTF_DIR = ./printf/

LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

all: $(LIBFT) $(PRINTF) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

bonus: $(LIBFT) $(PRINTF) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT_NAME) -L $(PRINTF_DIR) -lftprintf -L $(LIBFT_DIR) -lft

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER_NAME) -L $(PRINTF_DIR) -lftprintf -L $(LIBFT_DIR) -lft

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) -o $(CLIENT_BONUS_NAME) -L $(PRINTF_DIR) -lftprintf -L $(LIBFT_DIR) -lft

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS) -o $(SERVER_BONUS_NAME) -L $(PRINTF_DIR) -lftprintf -L $(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f *.o

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

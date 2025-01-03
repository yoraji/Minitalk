CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_NAME = client
SERVER_NAME = server

LIBFT_DIR = ./libft/
PRINTF_DIR = ./printf/

LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

all: $(LIBFT) $(PRINTF) $(CLIENT_NAME) $(SERVER_NAME)

bonus: all

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT_NAME) -L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lft

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER_NAME) -L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lft

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
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all bonus clean fclean re


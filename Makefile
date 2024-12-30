CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(CLIENT_SRCS:.c=.o) $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_NAME = client
SERVER_NAME = server

LIBFT = libft
PRINTF = printf

LIBFT_PATH = ./libft/ 
PRINTF_PATH = ./printf/

all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_SRCS)  -o $(CLIENT_NAME) -L $(PRINTF) -lft -L $(LIBFT) -lft

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRCS)  -o $(SERVER_NAME) -L $(PRINTF) -lft -L $(LIBFT) -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

$(PRINTF):
	make -C $(PRINTF_PATH)

clean:
	rm -f $(CLIENT_NAME) $(SERVER_NAME)
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) fclean

re: fclean all

.PHONY: all bonus libft printf clean fclean re


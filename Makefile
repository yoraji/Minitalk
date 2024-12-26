CC = gcc
CFLAG = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c

LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
CLIENT_NAME = client
SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRC) $(LIFBT_ARCHIVE)
	$(CC) $(CFALG) -o $@ $(CLIENT_SRCS) -L $(LIBFT_PATH) -lft

$(SERVER_NAME): $(CLIENT_SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAG) -o $@ $(SERVER_SRCS) -L $(LIBFT_PATH) -lft

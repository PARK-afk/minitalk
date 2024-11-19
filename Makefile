MINITALK        = MINITALK

SERVER          = server
CLIENT          = client

SERVER_BONUS    = server_bonus
CLIENT_BONUS    = client_bonus

CC              = cc
CFLAGS          = -Wall -Werror -Wextra
RM              = rm -rf

SRCS_PATH       = ./srcs
SERVER_FILES    = server.c put.c utils.c
CLIENT_FILES    = client.c put.c utils.c

SERVER_FILES_BONUS  = server_bonus.c put_bonus.c utils_bonus.c
CLIENT_FILES_BONUS  = client_bonus.c put_bonus.c utils_bonus.c

SERVER_SRCS         = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(SERVER_FILES))
CLIENT_SRCS         = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(CLIENT_FILES))

SERVER_SRCS_BONUS   = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(SERVER_FILES_BONUS))
CLIENT_SRCS_BONUS   = $(addprefix $(addsuffix /, $(SRCS_PATH)), $(CLIENT_FILES_BONUS))

SERVER_OBJS         = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS         = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS_BONUS   = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS   = $(CLIENT_SRCS_BONUS:.c=.o)

.PHONY: all clean fclean bonus

all: $(MINITALK)

$(MINITALK): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER_BONUS): $(SERVER_OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_BONUS): $(CLIENT_OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

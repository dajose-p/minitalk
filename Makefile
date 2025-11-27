CLIENT_NAME     := client
SERVER_NAME	:= server
BONUS_NAME      := checker
CC              := cc
CFLAGS          := -Wall -Wextra -Werror -g
LIBFT_DIR       := libft
LIBFT_A         := $(LIBFT_DIR)/libft.a

SRC_DIR         := srcs
OBJ_DIR         := objs
INC_DIR         := inc

GREEN   := \033[0;32m
YELLOW  := \033[0;33m
RED     := \033[0;31m
CYAN    := \033[0;36m
RESET   := \033[0m

CLIENT_SRCS := client.c

SERVER_SRCS := server.c

CLIENT_OBJS := $(addprefix $(OBJ_DIR)/, $(CLIENT_SRCS:.c=.o))
SERVER_OBJS     := $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT_A) $(CLIENT_OBJS)
	@echo "$(CYAN)[Linking client]$(RESET) $@"
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_A) -o $(CLIENT_NAME)
	@echo "$(GREEN)[OK]$(RESET) Ejecutable $(CLIENT_NAME) creado."

$(SERVER_NAME): $(LIBFT_A) $(SERVER_OBJS)
	@echo "$(CYAN)[Linking server]$(RESET) $@"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) -o $(SERVER_NAME)
	@echo "$(GREEN)[OK]$(RESET) Ejecutable $(SERVER_NAME) creado."

$(LIBFT_A):
	@echo "$(YELLOW)[Building libft]$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(CYAN)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR) :
	@mkdir -p $@

clean:
	@echo "$(RED)[Cleaning objects]$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)[Cleaning binaries]$(RESET)"
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

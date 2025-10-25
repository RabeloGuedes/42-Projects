NAME = minitalk
SERVER = server
CLIENT = client

LIBFT_DIR = libft
LIBFT = libft/libft.a
INC_FLAGS = -I ./inc -I $(LIBFT_DIR)/inc

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC_DIR = src
SRC =	send_signal.c handle_signal.c check_signal.c\
		sigaction_config.c handle_string.c get_string.c\
		send_string.c is_pid_valid.c

BONUS_SRC = $(SRC:handle_signal.c=handle_signal_bonus.c)

OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

BONUS_OBJS = $(addprefix $(OBJ_DIR)/,$(BONUS_SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJ) $(LIBFT) src/$(SERVER).c
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJ) src/$(SERVER).c -o $(SERVER) -L$(LIBFT_DIR) -lft

$(CLIENT): $(OBJ) $(LIBFT) src/$(CLIENT).c
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJ) src/$(CLIENT).c -o $(CLIENT) -L$(LIBFT_DIR) -lft

bonus: $(BONUS_OBJS) server_bonus client_bonus

server_bonus: $(BONUS_OBJS) $(LIBFT) src/$(SERVER)_bonus.c
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(BONUS_OBJS) src/$(SERVER)_bonus.c -o $(SERVER)_bonus -L$(LIBFT_DIR) -lft

client_bonus: $(BONUS_OBJS) $(LIBFT) src/$(CLIENT)_bonus.c
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(BONUS_OBJS) src/$(CLIENT)_bonus.c -o $(CLIENT)_bonus -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $(INC_FLAGS) $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR) 
	@rm -rf $(SERVER) $(CLIENT) $(SERVER)_bonus $(CLIENT)_bonus

re: fclean all

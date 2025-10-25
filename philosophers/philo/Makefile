CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread
NAME = philo

SRC = 	error_handler.c error_handler2.c forks.c memory.c monitor.c\
		params_checker.c philo_routine.c philo.c program.c utils.c\
		monitor_routine.c atomic_routines.c

ROOT_DIR = ./
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) main.c -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(ROOT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

NAME = push_swap
PUSH_SWAP_LIB = lib_$(NAME).a
PUSH_SWAP_LIB_PATH = -L. -l_$(NAME)
LIBFT = libft.a
LIBFT_PATH = ./libft/
CC = cc
FLAGS = -Wall -Wextra -Werror
SANITIZE_FLAG = -fsanitize=address
DEBUG_FLAGS = -g3 $(SANITIZE_FLAG)
SRC_PATH = src/
CHECKER_PATH = $(SRC_PATH)checker/
CHECKER_NAME = checker
TEST_PATH = test/
TEST_OUTPUT_FILES = test_output_files/
TEST_ERROR_FILES = test_error_files/
TEST_SEQUENCE = test_sequence/
TEST_100 = test_100/
TEST_500 = test_500/
SHELL_SCRIPTS_PATH = shell_scripts/
HELPERS_PATH = helpers/
MOVEMENTS_PATH = movements/
INC_FLAG = -I ./inc

HELPERS =	$(SRC_PATH)$(HELPERS_PATH)int_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)args_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)create_nodes.c\
			$(SRC_PATH)$(HELPERS_PATH)free_nodes.c\
			$(SRC_PATH)$(HELPERS_PATH)order_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)size_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)ft_lst_find.c\
			$(SRC_PATH)$(HELPERS_PATH)calcalute_least_rotations.c\
			$(SRC_PATH)$(HELPERS_PATH)handle_rotations_a.c\
			$(SRC_PATH)$(HELPERS_PATH)handle_rotations_b.c\
			$(SRC_PATH)$(HELPERS_PATH)sort.c\
			$(SRC_PATH)$(HELPERS_PATH)rotations_cost.c


MOVEMENTS = $(SRC_PATH)$(MOVEMENTS_PATH)swap.c\
			$(SRC_PATH)$(MOVEMENTS_PATH)push.c\
			$(SRC_PATH)$(MOVEMENTS_PATH)rotate.c

CHECKER =	$(CHECKER_PATH)checker_utils.c $(CHECKER_PATH)movement_validation.c

TESTS = $(TEST_PATH)display_nodes.c

OBJS = $(HELPERS:.c=.o) $(MOVEMENTS:.c=.o) $(TESTS:.c=.o)

# Colors
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
SUPER_RED = \033[91m
SUPER_GREEN = \033[92m
SUPER_YELLOW = \033[93m
SUPER_BLUE = \033[94m
SUPER_MAGENTA = \033[95m
SUPER_CYAN = \033[96m
# Colors

# Test Variables
STR_ARGS = "2 0 1"
DUPLICANTES_ARGS = 2 0 1 2
ARG_A = "2 0 1"
ARG_B = "3 8 4"
DOUBLE_STR = $(ARG_A) $(ARG_B)
NOT_INT_ARGS = 2 1 one 3
TYPO_ARGS = 0 4 -2 3-
NEGATIVES_ARGS = -2 -7 -3 -1 -5
POSITVES_ARGS = 5 7 1 8 3
GOOD_MIX_ARGS = $(POSITVES_ARGS) $(NEGATIVES_ARGS)
# Test Variables


all: $(NAME)

$(NAME): $(notdir $(OBJS))
	@echo "$(SUPER_YELLOW)Creating library!$(WHITE)"
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@echo "$(GREEN)Library successfully created!$(WHITE)"
	@echo "$(SUPER_YELLOW)Compiling $(SUPER_MAGENTA)$(NAME)$(SUPER_YELLOW)!$(WHITE)"
	@$(CC) $(FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)
	@echo "$(SUPER_MAGENTA)$(NAME)$(GREEN) successfully compiled!$(WHITE)"

$(notdir $(OBJS)): $(HELPERS) $(MOVEMENTS) $(TESTS)
	@echo "$(YELLOW)Compiling $(CYAN)libft$(YELLOW)!$(WHITE)"
	@make -s --directory=$(LIBFT_PATH)
	@echo "$(YELLOW)Compiling $(MAGENTA)OBJS FILES$(YELLOW)!$(WHITE)"
	@cp $(LIBFT_PATH)$(LIBFT) ./
	@mv $(LIBFT) $(PUSH_SWAP_LIB)
	@$(CC) -c $(FLAGS) $(INC_FLAG) $(HELPERS) $(MOVEMENTS) $(TESTS)
	@echo "$(GREEN)Compilation done!$(WHITE)"

clean:
	@make -s clean --directory=$(LIBFT_PATH)
	@rm -f $(notdir $(OBJS)) $(CHECKER_NAME) $(notdir $(CHECKER:.c=.o))
	@echo "$(RED)OBJS FILES removed!$(WHITE)"

fclean: clean
	@make -s fclean --directory=$(LIBFT_PATH)
	@rm -rf $(PUSH_SWAP_LIB) $(NAME) $(NAME).dSYM $(TEST_PATH)$(TEST_OUTPUT_FILES) $(TEST_PATH)$(TEST_ERROR_FILES) $(TEST_PATH)$(TEST_SEQUENCE)
	@echo "$(SUPER_RED)$(NAME), $(CHECKER_NAME) and $(PUSH_SWAP_LIB) removed!$(WHITE)"

re: fclean all

bonus: $(notdir $(OBJS)) checker $(notdir $(CHECKER:.c=.o))

checker:
	@$(CC) -c $(FLAGS) $(INC_FLAG) $(CHECKER)
	@echo "$(SUPER_YELLOW)Creating library!$(WHITE)"
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS)) $(notdir $(CHECKER:.c=.o))
	@echo "$(GREEN)Library successfully created!$(WHITE)"
	@echo "$(SUPER_YELLOW)Compiling $(SUPER_MAGENTA)$(CHECKER_NAME)$(SUPER_YELLOW)!$(WHITE)"
	@$(CC) $(FLAGS) $(INC_FLAG) $(CHECKER_PATH)$(CHECKER_NAME).c -o $(CHECKER_NAME) $(PUSH_SWAP_LIB_PATH)
	@echo "$(SUPER_MAGENTA)$(CHECKER_NAME)$(GREEN) successfully compiled!$(WHITE)"

debug: fclean $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

test_input: $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)
	@echo "$(YELLOW)input: \"$(STR_ARGS)\", expected: Error$(RED)"
	@sleep 2
	@./$(NAME) $(STR_ARGS)
	@sleep 1
	@echo "$(YELLOW)input: $(DUPLICANTES_ARGS), expected: Error$(RED)"
	@sleep 2
	@./$(NAME) $(DUPLICANTES_ARGS)
	@sleep 1
	@echo "$(YELLOW)input: \"$(ARG_A)\" \"$(ARG_B)\", expected: Error$(RED)"
	@sleep 2
	@./$(NAME) $(DOUBLE_STR)
	@sleep 1
	@echo "$(YELLOW)input: $(NOT_INT_ARGS), expected: Error$(RED)"
	@sleep 2
	@./$(NAME) $(NOT_INT_ARGS)
	@sleep 1
	@echo "$(YELLOW)input: $(TYPO_ARGS), expected: Error$(RED)"
	@sleep 2
	@./$(NAME) $(TYPO_ARGS)
	@sleep 1
	@echo "$(YELLOW)input: $(NEGATIVES_ARGS), expected: OK$(GREEN)"
	@sleep 2
	@./$(NAME) $(NEGATIVES_ARGS)
	@sleep 1
	@echo "$(YELLOW)input: $(POSITVES_ARGS), expected: OK$(GREEN)"
	@sleep 2
	@./$(NAME) $(POSITVES_ARGS)
	@sleep 1
	@echo "$(YELLOW)input: $(GOOD_MIX_ARGS), expected: OK$(GREEN)"
	@sleep 2
	@./$(NAME) $(GOOD_MIX_ARGS)

create_tests: fclean bonus
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS)) $(notdir $(CHECKER:.c=.o))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)
	@$(CC) $(FLAGS) $(INC_FLAG) $(CHECKER_PATH)$(CHECKER_NAME).c -o $(CHECKER_NAME) $(PUSH_SWAP_LIB_PATH)
	@cd $(TEST_PATH)$(SHELL_SCRIPTS_PATH) && sh create_test_files.sh

test_100:
	@cd $(TEST_PATH)$(SHELL_SCRIPTS_PATH) && sh test_output_100_random_numbers.sh

test_500:
	@cd $(TEST_PATH)$(SHELL_SCRIPTS_PATH) && sh test_output_500_random_numbers.sh

tests: create_tests test_100 test_500

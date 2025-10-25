NAME = libftprintf.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror -c
INCLUDE = include

LIBFT = libft

HELP_PATH = ./helpers

HELPERS = $(HELP_PATH)/ft_print_address.c $(HELP_PATH)/ft_print_uint.c $(HELP_PATH)/ft_print_int.c $(HELP_PATH)/ft_print_strchr.c $(HELP_PATH)/ft_print_hex.c

SRC = ft_printf.c ft_format_checker.c

OBJ_FILES_PATH = $(HELPERS:.c=.o)

OBJ_FILES = $(SRC:.c=.o) $(OBJ_FILES_PATH:$(HELP_PATH)/%=%)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
STRONG_RED = \033[0;91m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -s --directory=$(LIBFT)
	@cp $(LIBFT)/libft.a ./
	@mv $(LIBFT).a $(NAME)
	@ar rc $(NAME) $(OBJ_FILES)
	@echo "$(GREEN) $(NAME) complied!"

$(OBJ_FILES): $(SRC) $(HELPERS)
	@$(CC) $(CCFLAGS) $(SRC) $(HELPERS)
	@echo "$(YELLOW) compling OBJ_FILES!"

clean:
	@make -s clean --directory=$(LIBFT)
	@rm -f $(OBJ_FILES)
	@echo "$(RED) OBJ_FILES removed!"

fclean: clean
	@rm -f ./$(LIBFT)/libft.a $(NAME)
	@echo "$(STRONG_RED) $(NAME), $(LIBFT).a and OBJ_FILES removed!"

re: fclean all

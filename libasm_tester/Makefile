CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LDFLAGS =

# Test executable name
NAME = libasm_tester

# Source files
SRCS = main.c \
       test_framework.c \
       test_ft_strlen.c \
       test_stubs.c

OBJS = $(SRCS:.c=.o)

# Path to libasm project (will be prompted or provided)
LIBASM_PATH_FILE = .libasm_path
LIBASM_PATH = $(shell cat $(LIBASM_PATH_FILE) 2>/dev/null | tr -d '\n')
LIBASM_LIB = $(LIBASM_PATH)/libasm.a

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✓ Test suite compiled successfully!"

%.o: %.c libtest.h
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Run tests with automatic build
test:
	@if [ ! -f $(LIBASM_PATH_FILE) ]; then \
		read -p "Enter the absolute path to your libasm project: " path; \
		echo -n "$$path" > $(LIBASM_PATH_FILE); \
	fi
	@LIBASM_PATH=$$(cat $(LIBASM_PATH_FILE) | tr -d '\n'); \
	echo "Using libasm from: $$LIBASM_PATH"; \
	echo "Building libasm..."; \
	$(MAKE) -C "$$LIBASM_PATH" 2>&1; \
	if [ ! -f "$$LIBASM_PATH/libasm.a" ]; then \
		echo "Error: libasm.a not found at $$LIBASM_PATH/libasm.a"; \
		exit 1; \
	fi; \
	echo "Recompiling test suite with libasm..."; \
	$(MAKE) fclean_objs; \
	$(MAKE) CFLAGS="$(CFLAGS) -I$$LIBASM_PATH" LDFLAGS="$$LIBASM_PATH/libasm.a" test_with_lib; \
	echo ""; \
	./$(NAME) "$$LIBASM_PATH"

test_with_lib: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)

fclean_objs:
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)

fclean_all: fclean
	@echo "Cleaning libasm path cache..."
	@rm -f $(LIBASM_PATH_FILE)

re: fclean all

help:
	@echo "LIBASM Tester Makefile"
	@echo ""
	@echo "Usage:"
	@echo "  make           - Compile the test suite (without libasm)"
	@echo "  make test      - Build libasm and run all tests"
	@echo "  make clean     - Remove object files"
	@echo "  make fclean    - Remove object files and executable"
	@echo "  make fclean_all- Remove everything including saved libasm path"
	@echo "  make re        - Recompile from scratch"
	@echo "  make help      - Show this help message"
	@echo ""
	@echo "You can also run the tester directly:"
	@echo "  ./$(NAME) [path_to_libasm]"


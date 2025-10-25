COMP = cc
CFLAGS = -Wall -Wextra -Werror
LDCFLAGS = -Wl,-wrap,malloc

ENTRYPOINT = main.c
EXEC = prog
SRCS = wrapper.c
OBJS = $(SRCS:%.c=%.o)

all: $(ENTRYPOINT)

$(ENTRYPOINT): $(EXEC)

$(EXEC): $(OBJS)
	@$(COMP) $(CFLAGS) $(LDCFLAGS) $(ENTRYPOINT) $(OBJS) -o $(EXEC)

$(OBJS): $(SRCS)
	@$(COMP) $(CFLAGS) -c $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(EXEC)

re: fclean all

test: re
	@for i in `seq 1 10000`; do ./prog; done | sort | uniq -c
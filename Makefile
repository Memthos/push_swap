CC=gcc
CFLAGS=-Wall -Werror -Wextra
VPATH=srcs/
SRCS=parser_utils.c push_swap.c sort_functions.c stack_operations.c \
	stack_utils.c
OBJS_DIR=objs/
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
NAME=push_swap
BONUS=checker

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS) -o $@ $^
	@echo "Finished compiling push_swap"

bonus: $(BONUS)

$(BONUS):
	@echo "Finished compiling checker"

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -drf $(OBJS_DIR)
	@echo "Cleaned push_swap object files"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo Cleaned push_swap

re: fclean all

.PHONY: all clean fclean re bonus

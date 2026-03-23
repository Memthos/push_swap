CC=cc
CFLAGS=-Wall -Werror -Wextra
VPATH=srcs/
SRCS=parser_utils.c push_swap.c sort_functions.c stacks_operations.c \
	stack_utils.c
SRCS_BONUS=checker_bonus.c input_read_bonus.c parser_utils_bonus.c \
	stack_utils_bonus.c stacks_operations_bonus.c
OBJS_DIR=objs/
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS=$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))
LIBFT_DIR=libs/libft_tools
LIBFT=libs/libft_tools/libft_tools.a
NAME=push_swap
BONUS=checker

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Finished compiling push_swap"

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Finished compiling checker"

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@make -sC $(LIBFT_DIR) all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -drf $(OBJS_DIR)
	@make -sC $(LIBFT_DIR) clean
	@echo "Cleaned push_swap object files"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@make -sC $(LIBFT_DIR) fclean
	@echo Cleaned push_swap

re: fclean all

.PHONY: all clean fclean re bonus

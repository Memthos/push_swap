SRCS_DIR=sources/
OBJS_DIR=objects/
HEADERS=includes/
SRCS=ft_strcmp.c ft_strlen.c get_next_line.c get_next_line_utils.c

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
NAME=libft_tools.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^
	@echo "Finished compiling libft"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -drf $(OBJS_DIR)
	@echo "Cleaned libft object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned libft"

re: fclean all
	@echo "Recompiled libft"

.PHONY: all clean fclean re

FT_PRINTF_DIR=libs/ft_printf/
FT_PRINTF=$(addprefix $(FT_PRINTF_DIR), libftprintf.a)
SRCS_DIR=sources/
SRCS=$(addprefix $(SRCS_DIR), push_swap.c sort_normal.c sort_small.c sort_functions.c sort_utils.c stack_utils_01.c stack_utils_02.c)
OBJS=$(SRCS:.c=.o)
CFLAGS=-Werror -Wall -Wextra
CC=cc
NAME=push_swap

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(FT_PRINTF):
	make -s -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make clean -s -C $(FT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -s -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
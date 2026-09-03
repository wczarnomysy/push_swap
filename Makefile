NAME = push_swap
HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	parsing.c \
	flag_detector.c \
	ft_string.c \
	ft_split.c \
	lst_utils.c \
	free_utils.c \
	stack_utils.c \
	stack_analysis.c \
	op_utils.c \
	bench.c \
	bench_utils.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	sort_stack.c \
	sort_small.c \
	sort_simple.c \
	sort_medium.c \
	radix_sort.c \
	adaptive_sort.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

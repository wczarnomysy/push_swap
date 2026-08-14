NAME = push_swap.out
HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

ARCHIVES = assign_index.c \
disorder_check.c \
flag_detector.c \
ft_atol.c \
ft_lstadd_back.c \
ft_lstnew.c \
ft_split.c \
ft_strlen.c \
ft_strncmp.c \
ft_substr.c \
is_bench.c \
main.c \
validation_utils.c \
swap.c \
push.c \

OBJS = $(ARCHIVES:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c \
		parse_args.c \
		free.c \
		operations.c \
		radix_sort.c \
		lst_operations.c \
		ft_split.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

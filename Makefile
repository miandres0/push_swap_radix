NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c \
		parse_args.c \
		ft_atol.c \
		ft_split.c \
		free.c \
		radix_sort.c \
		moves_radix.c \
		alt_sort.c \
		alt_sort_aux.c \
		moves_alt.c \
		lst_operations.c
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

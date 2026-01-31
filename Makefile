NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
		operations.c \
		radix_sort.c \
		lst_operations.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

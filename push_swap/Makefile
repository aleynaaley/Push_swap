NAME = push_swap
CC = gcc
CFLAGS =  -Wall -Wextra -Werror
RM = rm -rf

SRCS =  push_swap.c\
		sort.c\
		sort_radix.c\
		sort_2.c\
		sort_3.c\
		create_stack.c\
		create_stack_2.c\
		check_arg.c\
		check_arg_2.c\
		check_arg_3.c\
		sort_swap.c\
		sort_3_long.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = pushswap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM				= rm -f


SRCS =
	
OBJS = $(SRCS:.c=.o)          
							 
all: $(NAME)                     

$(NAME): $(OBJS)                
	ar rc $(NAME) $(OBJS)        

clean:
	$(RM) $(OBJS)                      

 
fclean: clean              
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
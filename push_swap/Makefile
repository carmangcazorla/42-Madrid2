NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  free.c ft_split.c ft_atol.c main.c sort_large.c sort.c\
stacks.c validate.c movements.c movements2.c movements3.c movements1.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

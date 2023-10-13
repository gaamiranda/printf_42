NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c main.c ft_params1.c ft_params2.c
OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re	

FILES = ft_putchar.c ft_putptr.c ft_putstr.c printf.c
OBJ = $(FILES:.c=.o)
HEADER = printf.h 
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	echo "programme created"
%.o: %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	echo "object removed"

fclean: clean
	rm -f $(NAME)
	echo "programme removed"

re: fclean $(NAME)

.PHONY: clean

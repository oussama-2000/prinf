FILES = ft_putchar.c ft_putptr.c ft_putstr.c ft_printf.c ft_putnbr.c ft_puthexl.c ft_putunbr.c 
OBJ = $(FILES:.c=.o)
HEADER = ft_printf.h 
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "libftprintf.a created"

%.o: %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "libftprintf removed"

re: fclean $(NAME)

.PHONY: clean

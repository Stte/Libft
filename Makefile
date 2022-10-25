NAME = libft
FLAGS = -Wall -Werror -Wextra
SRCS = ft_isalpha.c
all: $(NAME)

$(NAME): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME).a *.o
	ranlib  $(NAME).a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME).a

re: fclean all

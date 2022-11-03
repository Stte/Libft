NAME = libft
FLAGS = -Wall -Werror -Wextra
SRCS = \
ft_bzero.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
ft_isdigit.c	ft_isprint.c	ft_memcpy.c		ft_memmove.c	\
ft_memset.c		ft_strlcpy.c	ft_strlen.c		ft_toupper.c	\
ft_tolower.c	ft_strchr.c		ft_strrchr.c	ft_strncmp.c	\
ft_memchr.c		ft_strlcat.c	ft_memcmp.c		ft_strnstr.c	\
ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		\
ft_strjoin.c

all: $(NAME)

$(NAME): $(SRCS)
	cc $(FLAGS) -c $(SRCS)
	ar rc $(NAME).a *.o
	ranlib  $(NAME).a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME).a

re: fclean all

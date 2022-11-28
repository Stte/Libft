FLAGS = -Wall -Werror -Wextra -g
BUFFER_SIZE = -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c

all: libft gnl

libft:
	gcc -g $(FLAGS) $(SANITIZE) $(TEST) $(LIBFT_TEST) -L.. -lft -o test_libft
	./test_libft

gnl:
	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(GNL_TEST) -L.. -lft -o test_gnl
	./test_gnl

test_clean:
	rm -f test_libft test_gnl

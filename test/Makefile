FLAGS = -Wall -Werror -Wextra -g
BUFFER_SIZE = -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c
ULONGTOHEX_TEST = ./test_ft_ulongtohex.c

all: libft gnl ulongtohex

libft:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(LIBFT_TEST) -L.. -lft -o run_libft
	./run_libft

gnl:
	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(GNL_TEST) -L.. -lft -o run_gnl
	./run_gnl

ulongtohex:
	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(ULONGTOHEX_TEST) -L.. -lft -o run_ulongtohex
	./run_ulongtohex

clean:
	rm -fr run_libft* run_gnl* run_ulongtohex*

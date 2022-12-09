FLAGS = -Wall -Werror -Wextra -g
BUFFER_SIZE = -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c
ULONGTOHEX_TEST = ./test_ft_ulongtohex.c
LTOA_TEST = ./test_ft_ltoa.c

all: build libft gnl ulongtohex ltoa


build:
	make debug -C ../

libft:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(LIBFT_TEST) -L.. -lft -o run_libft
	./run_libft

gnl:
	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(GNL_TEST) -L.. -lft -o run_gnl
	./run_gnl

ulongtohex:
	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(ULONGTOHEX_TEST) -L.. -lft -o run_ulongtohex
	./run_ulongtohex

ltoa:
	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(LTOA_TEST) -L.. -lft -o run_ltoa
	./run_ltoa

test:
	$(CC) $(FLAGS) $(SANITIZE) main.c -L.. -lft -o run_test
	./run_test

clean:
	rm -fr run_libft* run_gnl* run_ulongtohex* run_ltoa* run_test*

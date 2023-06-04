FLAGS = -Wall -Werror -Wextra -g -I../inc -I./unity
BUFFER_SIZE = -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c
ULONGTOHEX_TEST = ./test_ft_ulongtohex.c
LTOA_TEST = ./test_ft_ltoa.c
VEC_TEST = ./test_vec.c

all: clean run_test

$(LIBFT): $(LIBFT)
	make -C ..

run_test: $(LIBFT)
	gcc $(FLAGS) $(INCLUDES) $(SANITIZE) $(TEST) $(TESTS) -L.. -lft -o run_tests
	./run_tests

playground:
	gcc $(FLAGS) $(INCLUDES) $(SANITIZE) playground.c -L.. -lft -o run_playground
	./run_playground

clean:
	rm -fr run_*

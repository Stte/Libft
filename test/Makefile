# FLAGS = -Wall -Werror -Wextra -g -I../inc
# BUFFER_SIZE = -D BUFFER_SIZE=42
# SANITIZE = -fsanitize=address
# TEST = ./unity/unity.c
# LIBFT_TEST = ./test_libft.c
# GNL_TEST = ./test_gnl.c
# ULONGTOHEX_TEST = ./test_ft_ulongtohex.c
# LTOA_TEST = ./test_ft_ltoa.c
# VEC_TEST = ./test_vec.c
# FT_PRINTF_TEST = ./test_ft_printf.c

# all: build libft gnl ulongtohex ltoa vec

# build:
# 	make -C ..

# libft:
# 	gcc $(FLAGS) $(SANITIZE) $(TEST) $(LIBFT_TEST) -L.. -lft -o run_libft
# 	./run_libft

# gnl:
# 	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(GNL_TEST) -L.. -lft -o run_gnl
# 	./run_gnl

# ulongtohex:
# 	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(ULONGTOHEX_TEST) -L.. -lft -o run_ulongtohex
# 	./run_ulongtohex

# ltoa:
# 	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(LTOA_TEST) -L.. -lft -o run_ltoa
# 	./run_ltoa

# vec:
# 	gcc $(FLAGS) $(SANITIZE) $(TEST) $(VEC_TEST) -L.. -lft -o run_vec
# 	./run_vec

# playground:
# 	$(CC) $(FLAGS) $(SANITIZE) playground.c -L.. -lft -o run_playground
# 	./run_playground

# clean:
# 	rm -fr run_*



T = tests/
LIBFT = ../libft.a

FLAGS = -Wall -Werror -Wextra -g
INCLUDES = -I../inc -I./unity -I.
# SANITIZE = -fsanitize=address
TEST = ./unity/unity.c ./test.c
TESTS = \
$T/test_ft_ltoa.c	$T/test_ft_ulongtohex.c	$T/test_gnl.c	\
$T/test_libft.c $T/test_vec.c

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

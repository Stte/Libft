#include "unity/unity.h"
#include "vec.h"

void setUp(void) {
}

void tearDown(void) {

}

void test_vec_new(void)
{
	t_vec	actual;

	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, vec_new(&actual, 0, 0), "#1");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, vec_new(&actual, 0, 1), "#2");
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, vec_new(&actual, 1, 0), "#3");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, vec_new(&actual, 10, 1), "#4");
	TEST_ASSERT_TRUE_MESSAGE(actual.memory != NULL, "#5");
	TEST_ASSERT_TRUE_MESSAGE(actual.len == 0, "len");
	TEST_ASSERT_TRUE_MESSAGE(actual.alloc_size == 10, "alloc_size");
	vec_free(&actual);
}

void test_vec_free(void)
{
	t_vec actual;

	TEST_ASSERT_EQUAL_INT(1, vec_new(&actual, 10, 1));
	vec_free(&actual);
	TEST_ASSERT_TRUE_MESSAGE(actual.len == 0, "len");
	TEST_ASSERT_TRUE_MESSAGE(actual.alloc_size == 0, "alloc_size");
	TEST_ASSERT_TRUE_MESSAGE(actual.elem_size == 0, "elem_size");
	TEST_ASSERT_TRUE_MESSAGE(actual.memory == NULL, "memory");
}

void test_vec_from(void)
{
	t_vec	actual;
	int		expected[] = {1, 2, 3, 4, 5};

	vec_from(&actual, expected, 5, sizeof(int));
	TEST_ASSERT_EQUAL_MEMORY(expected, actual.memory, sizeof(expected));
	TEST_ASSERT_TRUE_MESSAGE(actual.len == 5, "len");
	TEST_ASSERT_TRUE_MESSAGE(actual.elem_size == sizeof(int), "elem_size");
	TEST_ASSERT_TRUE_MESSAGE(actual.alloc_size == sizeof(int) * 5, "alloc_size");
	vec_free(&actual);
}

void test_vec_resize(void)
{
	t_vec	actual;
	int		expected[] = {1, 2, 3, 4, 5};

	TEST_ASSERT_TRUE_MESSAGE(vec_from(&actual, expected, 5, sizeof(int)) > 0, "vec_from fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_resize(&actual, 100), "vec_resize fail");
	TEST_ASSERT_EQUAL_MEMORY(expected, actual.memory, sizeof(expected));
	TEST_ASSERT_TRUE_MESSAGE(actual.len == 5, "len");
	TEST_ASSERT_TRUE_MESSAGE(actual.elem_size == sizeof(int), "elem_size");
	TEST_ASSERT_TRUE_MESSAGE(actual.alloc_size == sizeof(int) * 100, "alloc_size");
	vec_free(&actual);
}

void test_vec_append(void)
{
	t_vec	actual;
	t_vec	t1;
	int		base1[] = {1, 2, 3};
	int		base2[] = {4, 5, 6};
	int		expected[] = {1, 2, 3, 4, 5, 6};

	TEST_ASSERT_TRUE_MESSAGE(vec_from(&actual, base1, 3, sizeof(int)) > 0, "vec_from fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_from(&t1, base2, 3, sizeof(int)) > 0, "vec_from fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_append(&actual, &t1) > 0, "vec_append fail");
	TEST_ASSERT_EQUAL_MEMORY(expected, actual.memory, sizeof(expected));
	TEST_ASSERT_TRUE_MESSAGE(actual.len == 6, "len");
	TEST_ASSERT_TRUE_MESSAGE(actual.elem_size == sizeof(int), "elem_size");
	TEST_ASSERT_TRUE_MESSAGE(actual.alloc_size == 24, "alloc_size");
	vec_free(&actual);
	vec_free(&t1);
}

void test_vec_push(void)
{
	t_vec	t1;
	int		base[] = {1, 2, 3, 4, 5};
	int		expect[] = {2, 4, 1};

	TEST_ASSERT_TRUE_MESSAGE(vec_new(&t1, 1, sizeof(int)) > 0, "vec_from fail");
	vec_push(&t1, &base[1]);
	TEST_ASSERT_TRUE_MESSAGE(t1.len == 1, "len #1");
	TEST_ASSERT_TRUE_MESSAGE(t1.elem_size == sizeof(int), "elem_size #1");
	TEST_ASSERT_TRUE_MESSAGE(t1.alloc_size == sizeof(int) * 1, "alloc_size #1");
	vec_push(&t1, &base[3]);
	TEST_ASSERT_TRUE_MESSAGE(t1.len == 2, "len #2");
	TEST_ASSERT_TRUE_MESSAGE(t1.elem_size == sizeof(int), "elem_size #2");
	TEST_ASSERT_TRUE_MESSAGE(t1.alloc_size == sizeof(int) * 2, "alloc_size #2");
	vec_push(&t1, &base[0]);
	TEST_ASSERT_TRUE_MESSAGE(t1.len == 3, "len #3");
	TEST_ASSERT_TRUE_MESSAGE(t1.elem_size == sizeof(int), "elem_size #3");
	TEST_ASSERT_TRUE_MESSAGE(t1.alloc_size == 16, "alloc_size #3");
	TEST_ASSERT_EQUAL_MEMORY(expect, t1.memory, sizeof(expect));
	vec_free(&t1);
}

void test_vec_copy(void)
{
	t_vec   t1;
	t_vec   t2;
	int     base[] = {1, 2, 3, 4, 5};
	TEST_ASSERT_TRUE_MESSAGE(vec_from(&t1, base, 5, sizeof(int)) > 0, "vec_from fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_new(&t2, 5, sizeof(int)) > 0, "vec_new fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_copy(&t2, &t1) > 0, "vec_copy fail");
	TEST_ASSERT_EQUAL_MEMORY(base, t2.memory, sizeof(base));
	vec_free(&t1);
	vec_free(&t2);
}

void test_vec_copy_2(void)
{
	t_vec   t1;
	t_vec   t2;
	int     base[] = {1, 2, 3, 4, 5};
	int     base2[] = {1, 2, 3};
	TEST_ASSERT_TRUE_MESSAGE(vec_from(&t1, base, 5, sizeof(int)) > 0, "vec_from fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_new(&t2, 3, sizeof(int)) > 0, "vec_new fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_copy(&t2, &t1) > 0, "vec_copy fail");
	TEST_ASSERT_EQUAL_MEMORY(base2, t2.memory, sizeof(base2));
	TEST_ASSERT_TRUE_MESSAGE(t2.len == 3, "len");
	TEST_ASSERT_TRUE_MESSAGE(t2.elem_size == sizeof(int), "elem_size");
	TEST_ASSERT_TRUE_MESSAGE(t2.alloc_size == 3 * sizeof(int), "alloc_size");
	vec_free(&t1);
	vec_free(&t2);
}

void test_vec_prepend(void)
{
	t_vec	actual;
	t_vec	t1;
	int		base1[] = {1, 2, 3};
	int		base2[] = {4, 5, 6};
	int		expected[] = {4, 5, 6, 1, 2, 3};

	TEST_ASSERT_TRUE_MESSAGE(vec_from(&actual, base1, 3, sizeof(int)) > 0, "vec_from fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_from(&t1, base2, 3, sizeof(int)) > 0, "vec_from fail");
	TEST_ASSERT_TRUE_MESSAGE(vec_append(&actual, &t1) > 0, "vec_append fail");
	TEST_ASSERT_EQUAL_MEMORY(expected, actual.memory, sizeof(expected));
	TEST_ASSERT_TRUE_MESSAGE(actual.len == 6, "len");
	TEST_ASSERT_TRUE_MESSAGE(actual.elem_size == sizeof(int), "elem_size");
	TEST_ASSERT_TRUE_MESSAGE(actual.alloc_size == 24, "alloc_size");
	vec_free(&actual);
	vec_free(&t1);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_vec_new);
	RUN_TEST(test_vec_free);
	RUN_TEST(test_vec_from);
	RUN_TEST(test_vec_resize);
	RUN_TEST(test_vec_append);
	RUN_TEST(test_vec_push);
	RUN_TEST(test_vec_copy);
	RUN_TEST(test_vec_copy_2);
	RUN_TEST(test_vec_prepend);
	return UNITY_END();
}

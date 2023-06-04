#include "unity/unity.h"
#include "libft.h"

void test_ft_atoi_should_be_equal_int(void) {
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("42"));
}

void test_ft_isdigit_should_be_true(void) {
	TEST_ASSERT_TRUE(ft_isdigit('1'));
}
void test_ft_isdigit_should_be_false(void) {
	TEST_ASSERT_FALSE(ft_isdigit('a'));
}

void test_tf_split_should_be_equal(void)
{
	char	*string = "  	Is th|is a| real 	...| nah";
	char	**expected = ((char*[5]){"  	Is th", "is a", " real 	...", " nah", NULL});
	char	**actual = ft_split(string, '|');
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, 5);
	for (int i = 0; i < 5; i++)
		free(actual[i]);
	free(actual);
}

int test_libft(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_atoi_should_be_equal_int);
	RUN_TEST(test_ft_isdigit_should_be_true);
	RUN_TEST(test_ft_isdigit_should_be_false);
	RUN_TEST(test_tf_split_should_be_equal);
	return UNITY_END();
}

#include "unity.h"
#include "libft.h"

void test_ft_ltoa_1_should_be_equal(void) {
	char	*actual;

	actual = ft_ltoa(-1);
	TEST_ASSERT_EQUAL_STRING("-1", actual);
	free(actual);
}
void test_ft_ltoa_2_should_be_equal(void) {
	char	*actual;

	actual = ft_ltoa(0);
	TEST_ASSERT_EQUAL_STRING("0", actual);
	free(actual);
}
void test_ft_ltoa_3_should_be_equal(void) {
	char	*actual;

	actual = ft_ltoa(2147483647);
	TEST_ASSERT_EQUAL_STRING("2147483647", actual);
	free(actual);
}
void test_ft_ltoa_4_should_be_equal(void) {
	char	*actual;

	actual = ft_ltoa(-2147483648);
	TEST_ASSERT_EQUAL_STRING("-2147483648", actual);
	free(actual);
}
void test_ft_ltoa_5_should_be_equal(void) {
	char	*actual;

	actual = ft_ltoa(9223372036854775807);
	TEST_ASSERT_EQUAL_STRING("9223372036854775807", actual);
	free(actual);
}
void test_ft_ltoa_6_should_be_equal(void) {
	char	*actual;

	actual = ft_ltoa(-9223372036854775807);
	TEST_ASSERT_EQUAL_STRING("-9223372036854775807", actual);
	free(actual);
}

int test_ft_ltoa(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_ltoa_1_should_be_equal);
	RUN_TEST(test_ft_ltoa_2_should_be_equal);
	RUN_TEST(test_ft_ltoa_3_should_be_equal);
	RUN_TEST(test_ft_ltoa_4_should_be_equal);
	RUN_TEST(test_ft_ltoa_5_should_be_equal);
	RUN_TEST(test_ft_ltoa_6_should_be_equal);
	return UNITY_END();
}

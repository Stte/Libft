#include "unity/unity.h"
#include "../libft.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_ft_ulongtohex_1_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(-1);
	TEST_ASSERT_EQUAL_STRING("ffffffffffffffff", actual);
}
void test_ft_ulongtohex_2_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(0);
	TEST_ASSERT_EQUAL_STRING("0", actual);
}
void test_ft_ulongtohex_3_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(10);
	TEST_ASSERT_EQUAL_STRING("a", actual);
}
void test_ft_ulongtohex_4_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(11);
	TEST_ASSERT_EQUAL_STRING("b", actual);
}
void test_ft_ulongtohex_5_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(12);
	TEST_ASSERT_EQUAL_STRING("c", actual);
}
void test_ft_ulongtohex_6_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(13);
	TEST_ASSERT_EQUAL_STRING("d", actual);
}
void test_ft_ulongtohex_7_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(14);
	TEST_ASSERT_EQUAL_STRING("e", actual);
}
void test_ft_ulongtohex_8_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(15);
	TEST_ASSERT_EQUAL_STRING("f", actual);
}
void test_ft_ulongtohex_9_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(16);
	TEST_ASSERT_EQUAL_STRING("10", actual);
}
void test_ft_ulongtohex_10_should_be_equal(void) {
	char	*actual;

	actual = ft_ulongtohex(255);
	TEST_ASSERT_EQUAL_STRING("ff", actual);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_ulongtohex_1_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_2_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_3_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_4_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_5_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_6_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_7_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_8_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_9_should_be_equal);
	RUN_TEST(test_ft_ulongtohex_10_should_be_equal);
	return UNITY_END();
}

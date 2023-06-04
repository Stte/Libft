#include "test.h"
#include "unity/unity.h"
#include <fcntl.h>
#include <unistd.h>
// #include "ft_printf.h"

void setUp(void) {
}

void tearDown(void) {
	FILE *fp = freopen("test_output", "w+", stdout);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);
}

int main(void)
{
	test_ft_ltoa();
	test_ft_ulongtohex();
	test_gnl();
	test_libft();
	test_vec();
	// test_ft_printf();
	return (0);
}


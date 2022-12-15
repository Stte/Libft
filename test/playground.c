#include "libft.h"

int	main(void)
{
	t_vec	actual;
	t_vec	t1;
	int		base1[] = {1, 2, 3};
	int		base2[] = {4, 5, 6};
	// int		expected[] = {1, 2, 3, 4, 5, 6};

	vec_from(&actual, base1, 3, sizeof(int));
	vec_from(&t1, base2, 3, sizeof(int));
	vec_append(&actual, &t1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:53:15 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/06 00:01:24 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	test(unsigned int i, char *c)
// {
// 	c[0] = c[0] + 1;
// 	printf("%c - %d\n", c[0], i);
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main()
// {
// 	char	str[] = "This is a test";
// 	ft_striteri(str, test);
// 	printf("%s\n", str);
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:02:00 by tspoof            #+#    #+#             */
/*   Updated: 2022/10/26 19:19:58 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void	test_isalpha(void)
{
	printf("Testing ft_isalpha...\n");
	printf("'a' = %s\n", ft_isalpha('a') == isalpha('a') ? "ok" : "FAIL");
	printf("'A' = %s\n", ft_isalpha('A') == isalpha('A') ? "ok" : "FAIL");
	printf("'z' = %s\n", ft_isalpha('z') == isalpha('z') ? "ok" : "FAIL");
	printf("'Z' = %s\n", ft_isalpha('Z') == isalpha('Z') ? "ok" : "FAIL");
	printf("'1' = %s\n", ft_isalpha('1') == isalpha('1') ? "ok" : "FAIL");
	printf("'$' = %s\n", ft_isalpha('$') == isalpha('$') ? "ok" : "FAIL");
	printf(" 1  = %s\n", ft_isalpha(1) == isalpha(1) ? "ok" : "FAIL");
}

void	test_isdigit(void)
{
	printf("Testing ft_isdigit...\n");
	printf("'4' = %s\n", ft_isdigit('4') == isdigit('4') ? "ok" : "FAIL");
	printf("'a' = %s\n", ft_isdigit('a') == isdigit('a') ? "ok" : "FAIL");
	printf("'$' = %s\n", ft_isdigit('$') == isdigit('$') ? "ok" : "FAIL");
	printf(" 4  = %s\n", ft_isdigit(4) == isdigit(4) ? "ok" : "FAIL");
}

void	test_isalnum(void)
{
	printf("Testing ft_isalnum...\n");
	printf("'a' = %s\n", ft_isalnum('a') == isalnum('a') ? "ok" : "FAIL");
	printf("'A' = %s\n", ft_isalnum('A') == isalnum('A') ? "ok" : "FAIL");
	printf("'z' = %s\n", ft_isalnum('z') == isalnum('z') ? "ok" : "FAIL");
	printf("'Z' = %s\n", ft_isalnum('Z') == isalnum('Z') ? "ok" : "FAIL");
	printf("'1' = %s\n", ft_isalnum('1') == isalnum('1') ? "ok" : "FAIL");
	printf("'$' = %s\n", ft_isalnum('$') == isalnum('$') ? "ok" : "FAIL");
	printf(" 1  = %s\n", ft_isalnum(1) == isalnum(1) ? "ok" : "FAIL");
	printf("'4' = %s\n", ft_isalnum('4') == isalnum('4') ? "ok" : "FAIL");
	printf("'a' = %s\n", ft_isalnum('a') == isalnum('a') ? "ok" : "FAIL");
	printf("'$' = %s\n", ft_isalnum('$') == isalnum('$') ? "ok" : "FAIL");
	printf(" 4  = %s\n", ft_isalnum(4) == isalnum(4) ? "ok" : "FAIL");
}

void	test_isascii(void)
{
	printf("Testing ft_isascii...\n");
	printf("'4' = %s\n", ft_isascii('4') == isascii('4') ? "ok" : "FAIL");
	printf("'a' = %s\n", ft_isascii('a') == isascii('a') ? "ok" : "FAIL");
	printf("'$' = %s\n", ft_isascii('$') == isascii('$') ? "ok" : "FAIL");
	printf(" 4  = %s\n", ft_isascii(4) == isascii(4) ? "ok" : "FAIL");
	printf(" 1114  = %s\n", ft_isascii(1114) == isascii(1114) ? "ok" : "FAIL");
}

// Good one
void	test_isprint(void)
{
	int	i;
	int	errors;

	errors = 0;
	printf("Testing ft_isprint...\n");
	i = 32;
	while (i < 127)
	{
		if (ft_isprint(i) != isprint(i))
		{
			printf("FAIL, when ascii dec is %d\n", i);
			errors += 1;
		}
		i++;
	}
	if (ft_isprint(0) != isprint(0))
	{
		printf("FAIL, when ascii dec is 0\n");
		errors += 1;
	}
	if (ft_isprint(1000) != isprint(1000))
	{
		printf("FAIL, when ascii dec is 1000\n");
		errors += 1;
	}
	if (errors == 0)
	{
		printf("Passed\n");
	}
}

void	test_strlen(void)
{
	int	errors;

	errors = 0;
	printf("Testing ft_strlen...\n");

	if (ft_strlen("") != (int)strlen(""))
	{
		printf("FAIL, when string is \"\"\n");
		errors += 1;
	}
	if (ft_strlen("Hello how are you?") != (int)strlen("Hello how are you?"))
	{
		printf("FAIL, when string is \"Hello how are you?\"\n");
		errors += 1;
	}

	if (errors == 0)
	{
		printf("Passed\n");
	}
}
// Not really testing anything
void	test_memset(void)
{
	int		errors;
	char	test[5];
	// int	i;

	errors = 0;
	printf("Testing ft_memset...\n");


	if (ft_memset(test, 'p', sizeof(test)) != memset(test, 'p', sizeof(test)))
	{
		printf("FAIL, when char is \'p\'\n");
		errors += 1;
	}

	if (errors == 0)
	{
		printf("Passed\n");
	}
}

void	test_bzero(void)
{
	int		errors;
	char	str[] = "test";
	char	str1[] = "test";

	printf("Testing ft_bzero...\n");
	errors = 0;
	ft_bzero(str, sizeof(str));
	bzero(str1, sizeof(str1));

	size_t i = 0;
	while(i < sizeof(str))
	{
		if (str[i] != str1[i])
		{
			errors = 1;
		}
		i++;
	}
	if (errors == 0)
	{
		printf("Passed\n");
	}
	else
		printf("FAIL\n");
}

void	test_memcpy(void)
{
	int		errors = 0;
	size_t	i;
	char	*src = "abcde";
	char	dest[15];
	char	dest1[15];

	printf("Testing ft_memcpy...\n");
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	memcpy(dest1, src, ft_strlen(src) + 1);

	i = 0;
	while (i < ft_strlen(src))
	{
		if (dest[i] != dest1[i])
			errors = 1;
		i++;
	}

	if (!errors)
		printf("Passed\n");
	else
		printf("FAIL\n");
}

void	test_memmove(void)
{
	char	a[50] = "testi";
	char	b[50] = "testi";
	int		i;
	int		errors = 0;

	printf("Testing ft_memmove...\n");
	ft_memmove(&a[2], a, 4);
	memmove(&b[2], b, 4);

	i = 0;
	while (i < 5)
	{
		if (a[i] != b[i])
			errors++;
		i++;
	}

	if (!errors)
		printf("Passed\n");
	else
		printf("FAIL\n");
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	return (0);
}

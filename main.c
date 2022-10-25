/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:02:00 by tspoof            #+#    #+#             */
/*   Updated: 2022/10/25 16:53:20 by tspoof           ###   ########.fr       */
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
	printf("Testing ft_isprint...\n");

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

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:05:22 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/05 15:45:44 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start_idx;
	size_t	end_idx;

	if (!s1)
		return (NULL);

	start_idx = 0;
	end_idx = ft_strlen(s1);
	while (ft_strchr(set, s1[start_idx]) && start_idx < end_idx)
		start_idx++;
	while (ft_strchr(set, s1[end_idx]) && start_idx < end_idx)
		end_idx--;

	// i = (size_t)(s1cpy - s1);
	ptr = ft_substr(s1 + start_idx, 0, end_idx - start_idx + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

/* int	main()
{
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *ret = ft_strtrim(s1, " \n\t");

	printf("%s\n", ret);
	return 0;
} */

/* char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end_idx;
	size_t	i;
	char	*s1_cpy;

	if (!s1)
		return (NULL);
	s1_cpy = s1;
	end_idx = ft_strlen(s1_cpy);
	i = 0;
	while (set[i])
	{
		if (*s1_cpy == set[i])
		{
			s1_cpy++;
			i = 0;
		}
		i++;
	}
	i = 0;
	while (set[i])
	{
		if (s1_cpy[end_idx] == set[i])
		{
			end_idx--;
			i = 0;
		}
		i++;
	}
	i = (size_t)(s1_cpy - s1);
	ft_substr(s1_cpy, 0, end_idx - i);
} */

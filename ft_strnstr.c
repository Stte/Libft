/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:17:40 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/02 11:42:06 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		needle_len;
	char		*haystack_copy;

	if (ft_strlen(needle) == 0 || !needle || haystack == needle)
		return ((char *)haystack);
	if (!haystack && len == 0)
		return (NULL);
	haystack_copy = (char *)haystack;
	needle_len = ft_strlen(needle);
	i = 0;
	while (i < len - needle_len)
	{
		haystack_copy = ft_memchr(haystack_copy, needle[0], len);
		if (!haystack_copy)
			return (NULL);
		i = (size_t)(haystack_copy - haystack);
		if (!ft_strncmp(haystack_copy, needle, needle_len))
			return ((char *)haystack_copy);
		haystack_copy++;
	}
	return (NULL);
}

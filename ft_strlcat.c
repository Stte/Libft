/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:39:31 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/02 18:14:51 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	dstlen;
// 	size_t	i;
// 	size_t	srclen;

// 	if (dst == NULL && dstsize == 0)
// 		return (ft_strlen(src));
// 	dstlen = ft_strlen(dst);
// 	srclen = ft_strlen(src);
// 	i = 0;
// 	while (dstlen < dstsize && src[i] != '\0')
// 	{
// 		dst[dstlen + i] = src[i];
// 		i++;
// 	}
// 	return (srclen + dstlen);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	// size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	dst_space;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		return (srclen + dstlen);
	dst_space = dstsize - dstlen;
	if (srclen > dst_space)
	{
		ft_memcpy(dst + dstlen, src, dst_space - 1);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst + dstlen, src, ft_strlen(src));

	return (srclen + dstsize);
}

// int main () {
// 	char	*str = "the cake is a lie !\0I'm hidden lol\r\n";
// 	char	buff1[0xF00] = "there is no stars in the sky";
// 	char	buff2[0xF00] = "there is no stars in the sky";
// 	size_t	max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

// 	size_t	r1 = strlcat(buff1, str, max);
// 	size_t	r2 = ft_strlcat(buff2, str, max);

// 	// char	s1[4] = "";
// 	// char	s2[4] = "";
// 	// r1 = strlcat(s1, "thx to ntoniolo for this test !", 4);
// 	// r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);

// 	return 0;
// }

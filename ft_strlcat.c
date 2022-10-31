/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:39:31 by tspoof            #+#    #+#             */
/*   Updated: 2022/10/31 10:51:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	dstlen;
	int	i;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	i = 0;
	while (dstlen < dstsize && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	return (ft_strlen(src));
}

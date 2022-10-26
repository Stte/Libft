/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:15:29 by tspoof            #+#    #+#             */
/*   Updated: 2022/10/26 19:17:10 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	while (len > 0)
	{
		((char *)dst)[len - 1] = ((char *)src)[len - 1];
		len--;
	}

	return (dst);
}

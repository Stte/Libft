/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:17:37 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/29 14:49:29 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Zero a byte string.
 *
 * Zeroes **n** number of bytes in memory
 * starting from location pointed by **s**.
 * @param s Pointer to memory
 * @param n Number of bytes
 */
void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
	{
		ft_memset(s, 0, n);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:10:14 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/29 15:33:34 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocate and free dynamic memory
 *
 * Allocates memory and sets every byte to 0.
 * @param count How many elements
 * @param size Size of a element (eg. 4 bytes)
 * @returns Pointer to the allocated memory
 * @attention Allocates memory
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!count || !size)
		return (ft_calloc(1, 1));
	if ((count * size) / count != size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

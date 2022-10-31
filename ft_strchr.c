/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:07:09 by tspoof            #+#    #+#             */
/*   Updated: 2022/10/31 11:27:44 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	slen;
	int	i;

	slen = ft_strlen(s);
	i = 0;
	while (i < slen + 1)
	{
		if (s[i] == c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}

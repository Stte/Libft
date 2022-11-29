/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:03:13 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/29 14:27:54 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief ASCII to integer.
 *
 * Returns integer from number string.
 * @param str Number as a string
 * @return Number as a integer
 */
int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	val;

	sign = 1;
	val = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\n')
	{
		val = val * 10 + (str[i] - '0');
		if (sign == 1 && val > 9223372036854775807)
			return (-1);
		if (sign == -1 && val > 9223372036854775807)
			return (0);
		i++;
	}
	return ((int)(sign * val));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:12:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 12:57:10 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_overflow(const char *str, int *overflow)
{
	long	sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0') * sign;
		if (num > 2147483647 || num < -2147483648)
		{
			*overflow = 1;
			return (-1);
		}
		str++;
	}
	return (num);
}

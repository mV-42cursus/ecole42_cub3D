/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:31:06 by marvin            #+#    #+#             */
/*   Updated: 2023/11/06 19:04:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wrong_format(char *file_path)
{
	while (*file_path)
		file_path++;
	file_path -= 4;
	if (ft_strcmp(".cub", file_path))
		return (TRUE);
	return (FALSE);
}

int	invalid_input(char *str, int flag)
{
	while (*str)
	{
		if (*str == ' ' || *str == '0' || *str == '1' \
			|| *str == 'N' || *str == 'S' || *str == 'E' || *str == 'W')
		{
			if (flag == TRUE)
			{
				if (*str == 'N' || *str == 'S' || *str == 'E' || *str == 'W')
					return (TRUE);
			}
		}
		else
			return (TRUE);
		str++;
	}
	return (FALSE);
}

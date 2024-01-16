/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:23:41 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 12:07:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalid_rgb_num(t_data *data)
{
	free_data_element(data);
	ft_exit("Error\nOnly three rgb values are allowed", 1);
}

int	is_all_space(char *line, int flag, int i)
{
	char	**arr;

	arr = ft_split(line, '\n');
	line = arr[0];
	if (arr[0] == NULL)
	{
		free(arr);
		return (TRUE);
	}
	while (line && *line)
	{
		if (*line != ' ')
			flag = FALSE;
		line++;
	}
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
	if (flag == FALSE)
		return (FALSE);
	return (TRUE);
}

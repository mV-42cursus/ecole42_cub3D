/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:32:07 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 22:57:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_data_element(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free_str(&data->element[i]);
		i++;
	}
}

void	free_rgb_integer(t_data *data, char **arr, int overflow)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free_data_element(data);
	if (overflow == TRUE)
		ft_exit("Invalid rgv value (overflow)", 1);
	ft_exit("Invalid rgb value (0 ~ 255)", 1);
}

void	free_data_map(t_data *data)
{
	int	row;

	row = 0;
	while (row < data->axis[ROW])
	{
		free(data->map[row]);
		row++;
	}
	free(data->map);
	data->map = NULL;
}

void	free_data_visited(t_data *data)
{
	int	row;

	row = 0;
	while (row < data->axis[ROW])
	{
		free(data->visited[row]);
		row++;
	}
	free(data->visited);
	data->visited = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:32:48 by marvin            #+#    #+#             */
/*   Updated: 2023/11/06 19:05:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_row_value(t_data *data)
{
	t_node	*p;
	int		row;

	row = 0;
	p = data->map_src;
	while (data->map_src)
	{
		data->map_src = data->map_src->next;
		row++;
	}
	data->map_src = p;
	return (row + 2);
}

int	find_col_value(t_data *data)
{
	t_node	*p;
	int		col;
	int		len;

	p = data->map_src;
	col = 0;
	len = 0;
	while (data->map_src)
	{
		len = ft_strlen(data->map_src->content);
		if (len > col)
			col = len;
		data->map_src = data->map_src->next;
	}
	data->map_src = p;
	return (col + 2);
}

int	find_player_loc(char **map, int *loc)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'N' || map[row][col] == 'S' || \
				map[row][col] == 'E' || map[row][col] == 'W')
			{
				loc[ROW] = row;
				loc[COL] = col;
				return (TRUE);
			}
			col++;
		}
		row++;
	}
	return (FALSE);
}

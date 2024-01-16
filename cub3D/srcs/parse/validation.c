/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:33:21 by marvin            #+#    #+#             */
/*   Updated: 2023/12/03 02:57:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dfs(t_data *data, int row, int col, int *axis)
{
	if (row < 0 || row >= data->axis[ROW] || col < 0 || col >= data->axis[COL])
		return ;
	data->visited[row][col] = VISITED;
	if (data->map[row][col] == 'N' || data->map[row][col] == 'S' \
		|| data->map[row][col] == 'E' || data->map[row][col] == 'W')
		ft_exit("Error\nWall error", 1);
	if (row < data->axis[ROW] - 1 && data->map[row + 1][col] != WALL \
		&& data->visited[row + 1][col] == NOT_VISITED)
		dfs(data, row + 1, col, axis);
	if (row >= 1 && data->map[row - 1][col] != WALL \
		&& data->visited[row - 1][col] == NOT_VISITED)
		dfs(data, row - 1, col, axis);
	if (col < data->axis[COL] && data->map[row][col + 1] != WALL \
		&& data->visited[row][col + 1] == NOT_VISITED)
		dfs(data, row, col + 1, axis);
	if (col >= 1 && data->map[row][col - 1] != WALL \
		&& data->visited[row][col - 1] == NOT_VISITED)
		dfs(data, row, col - 1, axis);
}

void	dfs2(t_data *data, int row, int col, int *axis)
{
	if (row < 0 || row >= data->axis[ROW] || col < 0 || col >= data->axis[COL])
		return ;
	data->visited[row][col] = VISITED;
	if (data->map[row][col] == ' ')
		ft_exit("Error\nInvalid map argument", 1);
	if (row < data->axis[ROW] - 1 && data->map[row + 1][col] != WALL \
		&& data->visited[row + 1][col] == NOT_VISITED)
		dfs2(data, row + 1, col, axis);
	if (row >= 1 && data->map[row - 1][col] != WALL \
		&& data->visited[row - 1][col] == NOT_VISITED)
		dfs2(data, row - 1, col, axis);
	if (col < data->axis[COL] && data->map[row][col + 1] != WALL \
		&& data->visited[row][col + 1] == NOT_VISITED)
		dfs2(data, row, col + 1, axis);
	if (col >= 1 && data->map[row][col - 1] != WALL \
		&& data->visited[row][col - 1] == NOT_VISITED)
		dfs2(data, row, col - 1, axis);
}

void	preprocess_content(t_data *data, int k)
{
	while (((char *)data->map_src->content)[++k])
	{
		if (((char *)data->map_src->content)[k] == '\n')
		{
			data->map_src->content = \
			ft_erase(((char *)data->map_src->content), k, k);
			k = -1;
			continue ;
		}
	}
}

void	create_map(t_data *data)
{
	int	i;
	int	k;

	i = -1;
	data->map = ft_calloc_exit(data->axis[ROW] + 1, sizeof(char *));
	while (++i < data->axis[ROW])
		data->map[i] = ft_calloc_exit(data->axis[COL] + 1, sizeof(char));
	i = -1;
	while (++i < data->axis[ROW])
	{
		k = -1;
		while (++k < data->axis[COL])
			data->map[i][k] = '*';
	}
}

void	invalid_map_free_exit(t_data *data)
{
	free_data_element(data);
	free_data_map(data);
	free_nodes(data);
	ft_exit("Error\nInvalid map argument.", 1);
}

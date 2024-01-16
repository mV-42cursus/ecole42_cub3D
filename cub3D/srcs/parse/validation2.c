/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:21:55 by marvin            #+#    #+#             */
/*   Updated: 2023/12/03 02:58:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c, int *flag)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		*flag = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

void	assign_value(t_data *data, int flag)
{
	int	i;
	int	k;

	i = 1;
	flag = FALSE;
	while (data->map_src)
	{
		k = -1;
		preprocess_content(data, k);
		if (invalid_input(data->map_src->content, flag))
			invalid_map_free_exit(data);
		while (((char *)data->map_src->content)[++k])
		{
			data->map[i][k + 1] = ((char *)data->map_src->content)[k];
			if (flag == TRUE)
				if (is_player(((char *)data->map_src->content)[k], &flag))
					invalid_map_free_exit(data);
			if (is_player(((char *)data->map_src->content)[k], &flag))
				continue ;
		}
		i++;
		data->map_src = data->map_src->next;
	}
}

void	create_visited(t_data *data)
{
	int	i;

	i = -1;
	data->visited = ft_calloc_exit(data->axis[ROW] + 1, sizeof(int *));
	while (++i < data->axis[ROW])
		data->visited[i] = ft_calloc_exit(data->axis[COL] + 1, sizeof(int));
}

void	map_validation(t_data *data, int flag)
{
	int	i;
	int	k;
	int	player_loc[2];

	flag = FALSE;
	i = 1;
	k = -1;
	create_map(data);
	assign_value(data, flag);
	if (!find_player_loc(data->map, player_loc))
	{
		free_data_element(data);
		free_data_map(data);
		ft_exit("Error\nPlayer position not found", 1);
	}
	create_visited(data);
	dfs(data, 0, 0, data->axis);
	dfs2(data, player_loc[ROW], player_loc[COL], data->axis);
	free_data_visited(data);
}

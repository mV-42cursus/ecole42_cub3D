/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:35:20 by marvin            #+#    #+#             */
/*   Updated: 2023/12/03 03:05:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(int fd, t_data *data)
{
	char	*line;

	while (1)
	{
		line = NULL;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_all_space(line, 0, 0))
		{
			free(line);
			continue ;
		}
		ft_lstadd_back(&data->map_src, ft_lstnew((void *)line));
	}
}

void	whitespace(char *file_path)
{
	char	c;
	int		bytes;
	int		fd;

	fd = open(file_path, O_RDONLY);
	bytes = 0;
	while (1)
	{
		c = 0;
		bytes = read(fd, &c, 1);
		if (c == 10)
			continue ;
		if ((c >= 9 && c <= 13) || c == 127)
			ft_exit("Error\nno whitespace", 1);
		if (bytes == 0)
			break ;
	}
	close(fd);
}

void	mapsize_error(t_data *data)
{
	free_data_element(data);
	free_nodes(data);
	free(data);
	ft_exit("Error\nCheck map size. Too large.", 1);
}

void	parse(t_data *data, char *file_path)
{
	t_node	*cur;
	t_node	*p;
	int		fd;
	int		flag;

	flag = FALSE;
	whitespace(file_path);
	fd = open(file_path, O_RDONLY);
	parse_elements(data, fd);
	if (element_validation(data) != 6)
	{
		free_data_element(data);
		ft_exit("Error\nInvalid Map", 1);
	}
	parse_map(fd, data);
	p = data->map_src;
	cur = NULL;
	data->axis[ROW] = find_row_value(data);
	data->axis[COL] = find_col_value(data);
	if (data->axis[ROW] * data->axis[COL] > 100 * 100)
		return (mapsize_error(data));
	map_validation(data, flag);
	close(fd);
	draw_main(data);
}

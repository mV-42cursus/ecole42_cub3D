/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:48:56 by marvin            #+#    #+#             */
/*   Updated: 2023/11/15 12:02:00 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	element_validation(t_data *data)
{
	int	validation;

	validation = 0;
	validation += texture(data, NO);
	validation += texture(data, SO);
	validation += texture(data, WE);
	validation += texture(data, EA);
	validation += rgb(data, F);
	validation += rgb(data, C);
	return (validation);
}

void	preprocess_line(char **line)
{
	int	i;

	i = 0;
	while (line[0] && line[0][i])
	{
		if (line[0][i] == ' ')
		{
			line[0] = ft_erase(line[0], i, i);
			i = 0;
		}
		i++;
	}
}

void	parse_elements(t_data *data, int fd)
{
	char	*line;
	int		rot;

	rot = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		preprocess_line(&line);
		if (line == NULL)
			break ;
		if (line && line[0] == '\n')
		{
			free(line);
			line = NULL;
			continue ;
		}
		data->element[rot] = ft_strdup(line);
		free(line);
		line = NULL;
		rot++;
		if (rot == 6)
			break ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:56:29 by jongolee          #+#    #+#             */
/*   Updated: 2023/10/12 00:00:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

void	find_nl_from_stack(int fd, char **line, char **result)
{
	char	stack[BUFFER_SIZE + 1];

	while (1)
	{
		fill_stack_zero(stack);
		if (read(fd, stack, BUFFER_SIZE) < 0)
		{
			*result = 0;
			free(*line);
			*line = 0;
			break ;
		}
		if (ft_strlen(stack) == 0)
		{
			*result = *line;
			*line = 0;
			break ;
		}
		ft_strjoin(line, stack, result);
		if (new_line_index(stack) >= 0)
			break ;
	}
}

char	*str_split_by_nl(char **line)
{
	ssize_t	nl_idx;
	char	*nl;
	char	*temp;

	nl_idx = new_line_index(*line);
	nl = ft_strndup(*line, nl_idx + 1);
	if (!nl)
	{
		free(*line);
		*line = 0;
		return (0);
	}
	if ((*line)[nl_idx + 1])
	{
		temp = ft_strndup(*line + nl_idx + 1, ft_strlen(*line + nl_idx + 1));
		free(*line);
		*line = temp;
	}
	else
	{
		free(*line);
		*line = 0;
	}
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;

	if (fd < 0)
		return (0);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= 80000000)
		return (0);
	if (line && new_line_index(line) >= 0)
		result = str_split_by_nl(&line);
	else
	{
		find_nl_from_stack(fd, &line, &result);
		if (!line)
			return (result);
		result = str_split_by_nl(&line);
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:56:55 by jongolee          #+#    #+#             */
/*   Updated: 2023/10/12 00:00:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

ssize_t	new_line_index(char *str)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	fill_stack_zero(char *stack)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		stack[i++] = 0;
}

size_t	ft_strlen(char *str)
{
	char	*_s;

	if (!str)
		return (0);
	_s = str;
	while (*str)
		str++;
	return (str - _s);
}

void	ft_strjoin(char **line, char *stack, char **result)
{
	char	*temp;
	size_t	idx;

	idx = 0;
	temp = malloc(ft_strlen(*line) + ft_strlen(stack) + 1);
	if (!temp)
	{
		*result = 0;
		free(*line);
		*line = 0;
		return ;
	}
	while (*line && (*line)[idx])
	{
		temp[idx] = (*line)[idx];
		idx++;
	}
	while (*stack)
	{
		temp[idx++] = (*stack);
		stack++;
	}
	temp[idx] = 0;
	free(*line);
	*line = temp;
}

char	*ft_strndup(char *str, size_t n)
{
	char	*temp;
	size_t	i;

	temp = malloc(n + 1);
	if (!temp)
		return (0);
	temp[n] = 0;
	i = 0;
	while (i < n)
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}

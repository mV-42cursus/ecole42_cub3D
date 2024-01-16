/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:35:51 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 12:07:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	condition_match(char *str, int flag)
{
	if (ft_strlen(str) <= 3)
		return (FALSE);
	if (flag == NO)
		return (str[0] == 'N' && str[1] == 'O' && str[2] == '.');
	if (flag == SO)
		return (str[0] == 'S' && str[1] == 'O' && str[2] == '.');
	if (flag == WE)
		return (str[0] == 'W' && str[1] == 'E' && str[2] == '.');
	if (flag == EA)
		return (str[0] == 'E' && str[1] == 'A' && str[2] == '.');
	if (flag == F)
		return (str[0] == 'F' && (str[1] >= '0' && str[1] <= '9'));
	if (flag == C)
		return (str[0] == 'C' && (str[1] >= '0' && str[1] <= '9'));
	return (FALSE);
}

char	*remove_newline(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '\n')
		{
			path = ft_erase(path, i, i);
			i = 0;
			continue ;
		}
		i++;
	}
	return (path);
}

int	texture(t_data *data, int flag)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (i < 6)
	{
		if (condition_match(data->element[i], flag))
		{
			path = data->element[i] + 2;
			path = remove_newline(ft_strdup(path));
			if (open(path, O_RDONLY) == -1)
			{
				free_data_element(data);
				free_str(&path);
				ft_exit("Error\ntexture open error", 1);
			}
			free_str(&path);
			return (1);
		}
		i++;
	}
	return (0);
}

void	rgb_integer(t_data *data, char **arr, int flag, int overflow)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		if (flag == F)
		{
			data->floor[i] = ft_atoi_overflow(arr[i], &overflow);
			if (data->floor[i] < 0 || data->floor[i] > 255)
				free_rgb_integer(data, arr, overflow);
		}
		if (flag == C)
		{
			data->ceiling[i] = ft_atoi_overflow(arr[i], &overflow);
			if (data->ceiling[i] < 0 || data->ceiling[i] > 255)
				free_rgb_integer(data, arr, overflow);
		}
		i++;
	}
	i = -1;
	while (arr[++i])
		free_str(&arr[i]);
	free(arr);
	if (i > 3)
		invalid_rgb_num(data);
}

int	rgb(t_data *data, int flag)
{
	char	**arr;
	char	*value;
	int		i;
	int		overflow;

	arr = NULL;
	value = NULL;
	i = 0;
	overflow = 0;
	while (i < 6)
	{
		if (condition_match(data->element[i], flag))
		{
			value = data->element[i] + 1;
			arr = ft_split(value, ',');
			rgb_integer(data, arr, flag, overflow);
			return (1);
		}
		i++;
	}
	return (0);
}

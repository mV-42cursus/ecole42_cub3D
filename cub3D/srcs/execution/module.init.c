/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:25:10 by jongolee          #+#    #+#             */
/*   Updated: 2023/11/15 18:13:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	rotate(t_info *info, double radian)
{
	double	old_plane_x;

	old_plane_x = info->plane_x;
	info->dir_x = -cos(radian);
	info->dir_y = -sin(radian);
	info->plane_x = info->plane_x * cos(radian) - info->plane_y * sin(radian);
	info->plane_y = old_plane_x * sin(radian) + info->plane_y * cos(radian);
}

void	init_vector(t_info *info, t_data *data, int i)
{
	int	j;

	while (i < data->axis[ROW])
	{
		j = 0;
		while (j < data->axis[COL])
		{
			if (data->map[i][j] == 'S' || data->map[i][j] == 'E' || \
			data->map[i][j] == 'W' || data->map[i][j] == 'N')
			{
				info->pos_x = i + 0.5;
				info->pos_y = j + 0.5;
				if (data->map[i][j] == 'S')
					rotate(info, PI);
				else if (data->map[i][j] == 'W')
					rotate(info, PI / 2);
				else if (data->map[i][j] == 'E')
					rotate(info, -PI / 2);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_zero(int **arr, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
			arr[i][j++] = 0;
		i++;
	}
}

void	init_buffer(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			info->buf[i][j++] = 0;
		i++;
	}
	info->texture = (int **)malloc(sizeof(int *) * 4);
	if (!info->texture)
		ft_exit("malloc failed", 1);
	i = 0;
	while (i < 4)
	{	
		info->texture[i] = \
		(int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH));
		if (!info->texture[i++])
			ft_exit("malloc failed", 1);
	}
	init_zero(info->texture, 4, TEX_HEIGHT * TEX_WIDTH);
}

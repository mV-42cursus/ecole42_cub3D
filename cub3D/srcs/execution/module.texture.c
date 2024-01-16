/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:45:40 by jongolee          #+#    #+#             */
/*   Updated: 2023/11/15 15:32:21 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image \
		(info->mlx, path, &img->img_width, &img->img_height);
	img->addr = (int *)mlx_get_data_addr \
	(img->img, &img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->addr[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	set_null(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (data->element[i][j])
		{
			if (data->element[i][j] == '\n')
				data->element[i][j] = 0;
			j++;
		}
		i++;
	}
}

char	*get_src(int src, t_data *data)
{
	int	i;

	i = 0;
	set_null(data);
	while (i < 6)
	{
		if (src == WE && data->element[i][0] == 'W' && \
			data->element[i][1] == 'E')
			return (ft_strdup(data->element[i] + 2));
		else if (src == SO && data->element[i][0] == 'S' && \
		data->element[i][1] == 'O')
			return (ft_strdup(data->element[i] + 2));
		else if (src == NO && data->element[i][0] == 'N' && \
		data->element[i][1] == 'O')
			return (ft_strdup(data->element[i] + 2));
		else if (src == EA && data->element[i][0] == 'E' && \
		data->element[i][1] == 'A')
			return (ft_strdup(data->element[i] + 2));
		i++;
	}
	return (0);
}

void	load_texture(t_info *info, t_data *data)
{
	t_img	img;
	char	*path[4];

	path[0] = get_src(EA, data);
	path[1] = get_src(WE, data);
	path[2] = get_src(SO, data);
	path[3] = get_src(NO, data);
	load_image(info, info->texture[EA], path[0], &img);
	load_image(info, info->texture[WE], path[1], &img);
	load_image(info, info->texture[SO], path[2], &img);
	load_image(info, info->texture[NO], path[3], &img);
	free(path[0]);
	free(path[1]);
	free(path[2]);
	free(path[3]);
}

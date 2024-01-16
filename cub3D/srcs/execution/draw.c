/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:18:22 by jongolee          #+#    #+#             */
/*   Updated: 2023/11/15 18:19:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			info->img.addr[y * WIN_WIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	draw_back(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				info->buf[y][x] = info->ceiling;
			else
				info->buf[y][x] = info->floor;
			x++;
		}
		y++;
	}
}

int	on_close_window(t_info *info)
{
	mlx_destroy_window(info -> mlx, info -> win);
	exit(0);
	return (0);
}

void	init_info(t_info *info, t_data *data)
{
	info->mlx = mlx_init();
	info->dir_x = -1.0;
	info->dir_y = 0.0;
	info->map = data->map;
	info->plane_x = 0.0;
	info->plane_y = 0.66;
	info->ceiling = \
	get_color(0, data->ceiling[0], data->ceiling[1], data->ceiling[2]);
	info->floor = get_color(0, data->floor[0], data->floor[1], data->floor[2]);
	info->move_speed = 0.05;
	info->rot_speed = 0.05;
	info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx");
	info->img.img = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
	info->img.addr = \
	(int *)mlx_get_data_addr(info->img.img, &info->img.bpp, \
	&info->img.size_l, &info->img.endian);
	init_vector(info, data, 0);
	init_buffer(info);
}

int	draw_main(t_data *data)
{
	t_info	info;

	init_info(&info, data);
	load_texture(&info, data);
	calc(&info);
	draw(&info);
	mlx_hook(info.win, ON_KEY_PRESS, 0, key_press, &info);
	mlx_hook(info.win, ON_DESTROY, 0, on_close_window, &info);
	mlx_loop(info.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:47:37 by jongolee          #+#    #+#             */
/*   Updated: 2023/11/15 18:18:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_coordinate(t_info *info, t_coordinate	*c, int x)
{
	c->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	c->raydir_x = info->dir_x + info->plane_x * c->camera_x;
	c->raydir_y = info->dir_y + info->plane_y * c->camera_x;
	c->map_x = (int)info->pos_x;
	c->map_y = (int)info->pos_y;
	c->delta_dist_x = fabs(1 / c->raydir_x);
	c->delta_dist_y = fabs(1 / c->raydir_y);
	c->hit = 0;
	c->step_x = 1;
	c->side_dist_x = (c->map_x + 1.0 - info->pos_x) * c->delta_dist_x;
	if (c->raydir_x < 0)
	{
		c->step_x = -1;
		c->side_dist_x = (info->pos_x - c->map_x) * c->delta_dist_x;
	}
	c->step_y = 1;
	c->side_dist_y = (c->map_y + 1.0 - info->pos_y) * c->delta_dist_y;
	if (c->raydir_y < 0)
	{
		c->step_y = -1;
		c->side_dist_y = (info->pos_y - c->map_y) * c->delta_dist_y;
	}
}

void	dda(t_info *info, t_coordinate *c)
{
	while (c->hit == 0)
	{
		if (c->side_dist_x < c->side_dist_y)
		{
			c->side_dist_x += c->delta_dist_x;
			c->map_x += c->step_x;
			c->side = 0;
		}
		else
		{
			c->side_dist_y += c->delta_dist_y;
			c->map_y += c->step_y;
			c->side = 1;
		}
		if (info->map[c->map_x][c->map_y] == '1' \
		|| info->map[c->map_x][c->map_y] == '*')
			c->hit = 1;
	}
	if (c->side == 0)
		c->perp_wall_dist = \
		(c->map_x - info->pos_x + (1 - c->step_x) / 2) / c->raydir_x;
	else
		c->perp_wall_dist = \
		(c->map_y - info->pos_y + (1 - c->step_y) / 2) / c->raydir_y;
}

void	get_height_wallx(t_info *info, t_coordinate *c)
{
	c->line_height = (int)(WIN_HEIGHT / c->perp_wall_dist);
	c->draw_start = -c->line_height / 2 + WIN_HEIGHT / 2;
	if (c->draw_start < 0)
		c->draw_start = 0;
	c->draw_end = c->line_height / 2 + WIN_HEIGHT / 2;
	if (c->draw_end >= WIN_HEIGHT)
		c->draw_end = WIN_HEIGHT - 1;
	if (c->side == 0)
		c->wall_x = \
		info->pos_y + c->perp_wall_dist * c->raydir_y;
	else
		c->wall_x = \
		info->pos_x + c->perp_wall_dist * c->raydir_x;
	c->wall_x -= floor(c->wall_x);
	c->tex_x = (int)(c->wall_x * (double)TEX_WIDTH);
	c->tex_x = TEX_WIDTH - c->tex_x - 1;
	if (c->side == 0 && c->raydir_x > 0)
		c->tex_num = 0;
	else if (c->side == 0 && c->raydir_x < 0)
		c->tex_num = 1;
	if (c->side == 1 && c->raydir_y < 0)
		c->tex_num = 3;
	else if (c->side == 1 && c->raydir_y > 0)
		c->tex_num = 2;
}

void	render_texture(t_info *info, t_coordinate *c, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		color;

	y = c->draw_start;
	step = (double)TEX_HEIGHT / c->line_height;
	tex_pos = (c->draw_start - WIN_HEIGHT / 2 + c->line_height / 2) * step;
	while (y < c->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = info->texture[c->tex_num][TEX_HEIGHT * tex_y + c->tex_x];
		info->buf[y][x] = color;
		y++;
	}
}

void	calc(t_info *info)
{
	t_coordinate	c;
	int				x;

	x = 0;
	draw_back(info);
	while (x < WIN_WIDTH)
	{
		set_coordinate(info, &c, x);
		dda(info, &c);
		get_height_wallx(info, &c);
		render_texture(info, &c, x);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:34:10 by jongolee          #+#    #+#             */
/*   Updated: 2023/11/15 18:19:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	on_press_w(t_info *info)
{
	double	hit;
	double	new_x;
	double	new_y;

	new_x = info->pos_x + info->dir_x * info->move_speed ;
	new_y = info->pos_y + info->dir_y * info->move_speed;
	hit = 0.0001;
	if (info->map[(int)(new_x + hit)][(int)(info->pos_y)] != '1' && \
	info->map[(int)(new_x - hit)][(int)(info->pos_y)] != '1')
		info->pos_x += info->dir_x * info->move_speed;
	if (info->map[(int)(info->pos_x)][(int)(new_y + hit)] != '1' && \
	info->map[(int)(info->pos_x)][(int)(new_y - hit)] != '1')
		info->pos_y += info->dir_y * info->move_speed;
}

void	on_press_s(t_info *info)
{
	double	hit;
	double	new_x;
	double	new_y;

	new_x = info->pos_x - info->dir_x * info->move_speed;
	new_y = info->pos_y - info->dir_y * info->move_speed;
	hit = 0.0001;
	if (info->map[(int)(new_x + hit)][(int)(info->pos_y)] != '1' && \
		info->map[(int)(new_x - hit)][(int)(info->pos_y)] != '1')
		info->pos_x -= info->dir_x * info->move_speed;
	if (info->map[(int)(info->pos_x)][(int)(new_y + hit)] != '1' && \
		info->map[(int)(info->pos_x)][(int)(new_y - hit)] != '1')
		info->pos_y -= info->dir_y * info->move_speed;
}

void	on_press_a_d(t_info *info, double radian)
{
	double	dir_x;
	double	dir_y;
	double	new_x;
	double	new_y;
	double	hit;

	hit = 0.0001;
	dir_x = info->dir_x * cos(radian) - info->dir_y * sin(radian);
	dir_y = info->dir_x * sin(radian) + info->dir_y * cos(radian);
	new_x = info->pos_x + dir_x * info->move_speed;
	new_y = info->pos_y + dir_y * info->move_speed;
	if (info->map[(int)(new_x + hit)][(int)(info->pos_y)] != '1' && \
		info->map[(int)(new_x - hit)][(int)(info->pos_y)] != '1')
		info->pos_x += dir_x * info->move_speed;
	if (info->map[(int)(info->pos_x)][(int)(new_y + hit)] != '1' && \
		info->map[(int)(info->pos_x)][(int)(new_y - hit)] != '1')
		info->pos_y += dir_y * info->move_speed;
}

void	on_press_arr(t_info *info, int key)
{
	double	old_dir_x;
	double	old_dir_y;
	double	radian;

	radian = 0;
	old_dir_x = info->dir_x;
	if (key == KEY_RIGHT)
		radian = -info->rot_speed;
	else if (key == KEY_LEFT)
		radian = info->rot_speed;
	old_dir_x = info->dir_x;
	info->dir_x = \
	info->dir_x * cos(radian) - info->dir_y * sin(radian);
	info->dir_y = \
	old_dir_x * sin(radian) + info->dir_y * cos(radian);
	old_dir_y = info->plane_x;
	info->plane_x = \
	info->plane_x * cos(radian) - info->plane_y * sin(radian);
	info->plane_y = \
	old_dir_y * sin(radian) + info->plane_y * cos(radian);
}

int	key_press(int key, t_info *info)
{
	if (key == KEY_W)
		on_press_w(info);
	else if (key == KEY_S)
		on_press_s(info);
	else if (key == KEY_A)
		on_press_a_d(info, PI / 2);
	else if (key == KEY_D)
		on_press_a_d(info, -PI / 2);
	else if (key == KEY_RIGHT)
		on_press_arr(info, key);
	else if (key == KEY_LEFT)
		on_press_arr(info, key);
	else if (key == KEY_ESC)
		exit(0);
	calc(info);
	draw(info);
	return (0);
}

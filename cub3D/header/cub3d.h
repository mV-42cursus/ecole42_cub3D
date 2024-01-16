/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:15:55 by marvin            #+#    #+#             */
/*   Updated: 2023/12/03 02:58:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*ft_erase(char *str, int start, int end);
char	*ft_strdup(const char *s);
void	*ft_memset(void *str, int c, size_t n);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(void *content);
void	ft_exit(char *msg, int flag);
void	*ft_calloc_exit(size_t nmemb, size_t size);

# define TRUE 1
# define FALSE 0

# define ROW 0
# define COL 1

# define VISITED 1
# define NOT_VISITED 0
# define VALID 1
# define INVALID 0

# define WALL '1'

# define WIN_WIDTH 1024
# define WIN_HEIGHT 512
# define ON_KEY_PRESS 2
# define ON_DESTROY 17
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define PI 3.14159265359

typedef struct s_img
{
	void	*img;
	int		*addr;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[WIN_HEIGHT][WIN_WIDTH];
	int		**texture;
	double	move_speed;
	double	rot_speed;
	int		floor;
	int		ceiling;
	char	**map;
}				t_info;

typedef struct s_coordinate
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
}				t_coordinate;

typedef struct s_data {
	int		row;
	int		col;
	char	*element[6];
	int		floor[3];
	int		ceiling[3];
	int		axis[2];
	t_node	*map_src;
	char	**map;
	int		**visited;
	int		space_cnt;
}	t_data;

enum e_condition {
	NO = 0,
	SO,
	WE,
	EA,
	F,
	C,
};

enum e_code
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/* elements.c */
void	parse_elements(t_data *data, int fd);
void	preprocess_line(char **line);
int		element_validation(t_data *data);

/* error.c */
int		wrong_format(char *file_path);
int		invalid_input(char *str, int flag);

/* find.c */
int		find_row_value(t_data *data);
int		find_col_value(t_data *data);
int		find_player_loc(char **map, int *loc);

/* heap.c */
void	free_str(char **str);
void	free_data_element(t_data *data);
void	free_rgb_integer(t_data *data, char **arr, int overflow);
void	free_data_map(t_data *data);
void	free_data_visited(t_data *data);

/* heap2.c */
void	free_nodes(t_data *data);

/* map.c */
void	parse_map(int fd, t_data *data);
void	parse(t_data *data, char *file_path);

/* utils.c */
int		condition_match(char *str, int flag);
char	*remove_newline(char *path);
int		texture(t_data *data, int flag);
void	rgb_integer(t_data *data, char **arr, int flag, int overflow);
int		rgb(t_data *data, int flag);

/* utils2.c */
void	invalid_rgb_num(t_data *data);
int		is_all_space(char *line, int flag, int i);

/* validation.c */
void	dfs(t_data *data, int row, int col, int *axis);
void	dfs2(t_data *data, int row, int col, int *axis);
void	preprocess_content(t_data *data, int k);
void	create_map(t_data *data);
void	invalid_map_free_exit(t_data *data);

/* validation2.c */
int		is_player(char c, int *flag);
void	assign_value(t_data *data, int flag);
void	create_visited(t_data *data);
void	map_validation(t_data *data, int flag);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int		draw_main(t_data *data);
int		get_color(int t, int r, int g, int b);
void	init_vector(t_info *info, t_data *data, int i);
void	init_buffer(t_info *info);

//on_press
int		key_press(int key, t_info *info);
void	draw(t_info *info);
void	calc(t_info *info);

//texture
void	load_texture(t_info *info, t_data *data);
void	draw_back(t_info *info);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:56:47 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/28 18:36:28 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define ROTATE_SPEED 0.05
#define MOVE_SPEED 0.05

#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define LEFT 123
#define RIGHT 124
#define UP 126
#define DOWN 125

typedef struct s_line
{
	int			x;
	int			y;
	int			y0;
	int			y1;
	int			tex_x;
	int			tex_y;
}				t_line;

typedef struct s_key
{
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		left;
	bool		right;
	bool		up;
	bool		down;
}				t_key;

typedef struct s_player
{
	double		cam_height;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	t_line		line;
	double		camera_x;

}				t_player;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_dist;
	int			current_x;
	int			draw_start;
	int			line_height;
	int			draw_end;
}				t_ray;

typedef struct s_image
{
	void		*img;
	char		*address;
	int			bits_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_game
{
	char		**game_map;
}				t_game;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_ray		ray;
	t_game		*game;
	int			ceiling_color;
	int			floor_color;
	t_player	player;
	t_image		image;
	t_key		keys;
	t_image		north_texture;
	t_image		south_texture;
	t_image		east_texture;
	t_image		west_texture;
}				t_data;

// raycasting algorithms
void			cast_rays(t_data *data, t_player *player);
void			wall_distance(t_game *game, t_ray *ray, t_player *player);

// hooks and player movement
int				on_keyrelease(int key, void *info);
int				exit_game(void *info);
int				hook_loop(void *info);
int				on_keypress(int key, void *info);
void			go_forward(t_data *data);
void			go_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);

// texture functions
void			paint_texture_line(t_data *root, t_ray *ray, t_line *line,
					double wall_x);
void			load_texture(t_data *data, t_image *image, char *path);

// initiate values
void			init_player_direction(t_data *data, char dir);
void			ray_info(t_ray *ray, t_player *player);
void			init_keys(t_key *keys);
void			data_info(t_data *data);
void			player_info(t_data *data);

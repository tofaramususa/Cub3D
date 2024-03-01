/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../include/cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:32:09 by arashido          #+#    #+#             */
/*   Updated: 2024/02/25 14:48:42 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define ROTATE_SPEED 0.05
# define MOVE_SPEED 0.05

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef enum e_error
{
	SUCCESS,
	INVALID_ARG,
	WRONG_MAP,
	WRONG_INPUT,
	MALLOC_FAIL,
	IMG_FAIL,
	OPEN_ERR,
	MLX_FAIL,
	WRITE_FAIL,
	WRONG_TEXTURE
}						t_error;

// ------------------- stack.c -------------------- //

typedef struct s_stack_node
{
	char				*val;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node		*front;
	t_stack_node		*rear;
}						t_stack;

void					init_stack(t_stack *s);
void					enstack(t_stack *s, void *val);
void					*destack(t_stack *s);
char					*stack_to_str(t_stack *s);
void					free_stack(t_stack *s);

// ------------------ parsing.c ----------------- //
typedef struct s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

//both used in parsing and execution
typedef struct s_map_infos
{
	char				*no_path; //allocated
	char				*so_path; //allocated
	char				*we_path; //allocated
	char				*ea_path; //allocated

	t_color				floor_color;
	t_color				ceiling_color;

	t_stack				stack;

	int					no_path_parsed; //flags
	int					so_path_parsed;
	int					we_path_parsed;
	int					ea_path_parsed;
	int					floor_color_parsed;
	int					ceiling_color_parsed;

}						t_map_infos;

//both used in execution and parsing
typedef struct s_map
{
	int					cols;
	int					rows;
	char				**map_data; //actual map
}						t_map;

//execution
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

//parsing
typedef struct s_arr
{
	char				**strings;
	int					length;
}						t_arr;

// execution
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

//execution
typedef struct s_line
{
	int					x;
	int					y;
	int					y0;
	int					y1;
	int					tex_x;
	int					tex_y;
}						t_line;

//execution
typedef struct s_key
{
	bool				w;
	bool				s;
	bool				a;
	bool				d;
	bool				left;
	bool				right;
	bool				up;
	bool				down;
}						t_key;

//execution
typedef struct s_ray
{
	double				raydir_x;
	double				raydir_y;
	int					map_x;
	int					map_y;
	double				delta_x;
	double				delta_y;
	double				side_x;
	double				side_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	double				wall_dist;
	int					current_x;
	int					draw_start;
	int					line_height;
	int					draw_end;
}						t_ray;

//execution
typedef struct s_player
{
	double				cam_height;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				speed;
	t_line				line;
	double				camera_x;
	char 				direction; // wall player is facing

}						t_player;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	t_image		image;
	t_ray		ray;
	t_key		keys;
	t_map				map;
	t_map_infos			map_infos;
	t_player			player;
	t_image				north_texture;
	t_image				south_texture;
	t_image				west_texture;
	t_image				east_texture;
	int					floor_color;
	int					ceiling_color;

}						t_data;

// #============# free.c #===============#
void					ft_free(void **ptr);
void					free_array(char **array);
void					free_2d_array(char ***map);
void					free_map_infos(t_map_infos *map_infos);
void					free_and_cleanup(t_data *data);

// #============# parsing.c #===============#
int						parse_map(char *file_name, t_map_infos *map_infos);

// #============# parsing_validation.c #===============#
int						verify_colors(t_color *color, char **colors);
int						check_texture(char *path);

// #============# parsing_helpers.c #===============#
int						beginswith(char **array, char *str);
int						arr_length(char **array);
int						is_empty_line(char *line);
int						open_map_file(char *file_name);
int						is_number(char *str);
void					print_error(const char *error_message);
int						print_error_ms(const char *error_message);

// #============# map_validation.c #===============#
int						is_valid_map(t_map *map);

// #============# map.c #===============#
void					convert_stack_to_2d_array(t_map *map, t_stack *stack);

// #============# parse_line.c #===============#
int						check_texture_path(t_map_infos *map_infos,
							t_arr *array, int *parsed_flag, char *type);
int						handle_color_line(t_map_infos *map_infos, t_arr *array,
							int *parsed_flag, char *type);

// #============# map_error_handling.c #===============#
int						print_missing_elements_error(t_map_infos *map_infos);

// #============# execution #===============#
// raycasting algorithms
void					cast_rays(t_data *data, t_player *player);
void					wall_distance(t_map *map, t_ray *ray,
							t_player *player);

// hooks and player movement
int						on_keyrelease(int key, void *info);
int						exit_game(void *info);
int						hook_loop(void *info);
int						on_keypress(int key, void *info);
void					go_forward(t_data *data);
void					go_backward(t_data *data);
void					move_left(t_data *data);
void					move_right(t_data *data);
void					rotate_left(t_data *data);
void					rotate_right(t_data *data);

// texture functions
void					paint_texture_line(t_data *root, t_ray *ray,
							t_line *line, double wall_x);
void					load_texture(t_data *data, t_image *image, char *path);

// initiate values
void					init_player_direction(t_data *data, char dir);
void					ray_info(t_ray *ray, t_player *player);
void					init_keys(t_key *keys);
void					data_info(t_data *data);
void					player_info(t_data *data);

#endif
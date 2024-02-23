/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:56:47 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/23 21:32:39 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define WINDOW_WIDTH 650
#define WINDOW_HEIGHT 650
// #define ROTATION_SPEED
#define PLAYER_SPEED 1
#define ROTATE_LEFT -30
#define ROTATE_RIGHT 30
#define WEIGHT 0.5

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124


typedef struct s_line
{
	int x;
	int y;
	int y0;
	int y1;
	int tex_x;
	int tex_y;
}				t_line;

typedef struct s_player
{
	int cam_height;  
	double pos_x;
	double pos_y;
	double dirX; 
	double dirY; 
	double planeX; // initial POV
	double planeY; // initial POV
	int cameraX;

}				t_player;

typedef struct s_ray
{
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double deltaX;
	double deltaY;
	double sideX;
	double sideY;
	int stepX;
	int stepY;
	int hit; 
	int side;
	double		perpWallDist;
	int current_x; 
	int draw_start;
	int line_height;
	int draw_end; 
}				t_ray;

typedef struct s_image {
	
	void *img;
	char *address;
	int  bits_pixel;
	int line_length;
	int endian;
	int width;
	int height;

} t_image;

typedef struct s_game
{
	char		**game_map; //allocated

	t_image *north_texture; //allocated
	t_image *south_texture; //allocated
	t_image *east_texture; //allocated
	t_image *west_texture; //allocated

}			t_game;

//mlx information about the image


//mlx information about the window
// typedef struct s_window 
// {
// 	void *mlx; //for mlx_init
// 	void  *window; //the actual window from 
// } t_window;

typedef struct s_key
{
	bool  w;
	bool  s;
	bool  a;
	bool  d;
	bool  left;
	bool  right;
} t_key;

// information about the whole game
typedef struct s_data
{

	void 	*mlx;	
	void 	*window; 
	t_ray	ray; //allocated
	t_game	*game; //allocated
	int 	ceiling_color;
	int		floor_color;
	t_player player; //allocated
	t_image image; //allocated
	t_image sample_texture; //allocated
	t_key keys;
	
}				t_data;

void	cast_rays(t_data *data, t_player *player);
int on_keypress(int key, void *info);
int on_keyrelease(int key, void *info);
int exit_game(void *info);
int hook_loop(void *info);
void init_keys(t_key *keys);
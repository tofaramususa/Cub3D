/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:56:47 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/13 23:35:09 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WINDOW_WIDTH 650
#define WINDOW_HEIGHT 650
#define ROTATION_SPEED
#define PLAYER_SPEED

/// @brief vertical line to be drawn on the screen
typedef struct s_line
{
	int x;     // x coordinate of line relative to screen
	int y;     // the current pixel index of the line along y axis
	int y0;    // y start index of drawing texture
	int y1;    // y end index of drawing texture
	int tex_x; // x coordinate of texture
	int tex_y; // y coordinate of texture
}				t_line;

// player information
typedef struct s_player
{
	cam_height;    // height of the camera
	double pos_x;  // initial player position
	double pos_y;  // ''
	double dirX;   // initial direction
	double dirY;   // initial direction
	double planeX; // initial POV
	double planeY; // initial POV
	double speed;  // speed of the player
}				t_player;

// ray infomation
//
typedef struct s_ray
{
	rayDirX;  // this the direction of the ray;
	rayDirY;  // this is the direction of the ray
	int mapX; // position of the ray inside map
	int mapY; // position of the ray inside map
	deltaX;
	deltaY;
	sideX;
	sideY;
	int stepX; // direction to step in X or Y
	int stepY; //
	int hit;   // was a wall hit
	int side;  // was a NS or a EW wall hit
	double		perpWallDist;
	int current_x;   // current x coordinate of the ray
	int draw_start;  // start of the line to draw
	int line_height; // height of the line to draw
	int draw_end;    // end of the line to draw
}				t_ray;

typedef struct s_game
{
	char		**map;
	t_player	*player;
	// we need the image here
	texture; // texture image

}			t_game;

// information about the whole game
typedef struct s_data
{
	t_ray		*ray;
	// we need an image too
	t_game		*game;
	// t_img mlx_img; // the image we will put to window
	ceiling_color; // ceiling color
	floor_color; // floor color
	// t_img north_texture; //get image
	// t_img south_texture; //get image
	// t_img east_texture; //get image
	// t_img west_texture; //get image
	

}				t_data;

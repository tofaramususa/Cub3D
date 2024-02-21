/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:53:59 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/21 20:33:16 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// t_data game;
// 1. Map initialization and Window Creation
	// - necessary information for rendering the game world

// 2. Raycasting - calculating the window and stuff
// 3. Rendering
// 4. Player movement - handling rotation and movement within game world

// initialise struct
// parse the parameters
// mlx_init
// mlx_new_window
// init_images
// init_players
// init colors
// cast_rays
// mlx_key_hook
// mlx_hook
// mlx_loop_hook
// mlx_loop

// need information --  player position in the map
// player y position in the map
// map width and map height
//
void	player_info(t_player *player)
{
	player->pos_x = 3;
	player->pos_y = 9;
	player->dirX = 1,    // were the player is facing
		player->dirY = 0; // initial direction vector
	player->planeX = 0; //may need to change this
	player->planeY = 0.66; //may need to change this
	player->cam_height = WINDOW_HEIGHT / 2;
}

void convert_image(t_data *data, t_image *image)
{
	char *path = "./test.xpm";
	image = calloc(1, sizeof(t_image *));
	image->img = mlx_xpm_file_to_image(data->mlx, path, &image->width, &image->height);
	image->address = mlx_get_data_addr(image->img,
		&image->bits_pixel, &image->line_length, &image->endian);
}

void	data_info(t_data *data)
{
	data->ceiling_color = 0x0000ff;
	data->floor_color = 0x0D300ff;
	// data->test_color = 0x0FF00ff;
}

void	run_game(t_data *data) // this is like the callback
{
	// exit(0);
	data_info(data); // parsing
	player_info(data->player);
	cast_rays(data, data->player);
	// function to get the textures of the different walls
	// mlx_loop                                                                                                                                               _hook()
		//continuously update the window using specified function
	// mlx_hook() //hook for key press
	// mlx_key_loop() //loop to keep the window open
	mlx_loop(data->mlx);
}

int	main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.player = calloc(1, sizeof(t_player *));
	data.ray = calloc(1, sizeof(t_ray *));
	// data.game = calloc(1, sizeof(t_game *));
	data.game = calloc(1, sizeof(t_game *));
	data.game->game_map = calloc(10, sizeof(char *));
	data.image = calloc(1, sizeof(t_image *));
	
		// exit(0);
          // init the map
	data.game->game_map[0] = strdup("1111111111111111111111111"); // fill the map
	data.game->game_map[1] = strdup("1000000000000000000100001");
	data.game->game_map[2] = strdup("1001000000000000000000001");
	data.game->game_map[3] = strdup("1001000000000000001000001");
	data.game->game_map[4] = strdup("1001000000000000001000001");
	data.game->game_map[5] = strdup("1001000000100000001000001");
	data.game->game_map[6] = strdup("1001000000000000001000001");
	data.game->game_map[7] = strdup("1001000000001000001000001");
	data.game->game_map[8] = strdup("1111111111111111111111111");
	data.game->game_map[9] = NULL;

	data.window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
		"cub3D");
	data.image->img = mlx_new_image(data.mlx, WINDOW_WIDTH,
		WINDOW_HEIGHT);                                                          
		// we need the address too.
	data.image->address = mlx_get_data_addr(data.image->img,
		&data.image->bits_pixel, &data.image->line_length, &data.image->endian);
		// get address of image
	convert_image(&data, data.sample_texture);
	run_game(&data);
	// clean up and exit game
}
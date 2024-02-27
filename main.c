/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:53:59 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/28 01:55:57 by tofaramusus      ###   ########.fr       */
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
void init_keys(t_key *keys)
{
	keys->w = false;
	keys->s = false;
	keys->a = false;
	keys->d = false;
	keys->left = false;
	keys->right = false;
	keys->up = false;
	keys->down = false;
}

void player_direction(t_player *player, char dir)
{
    if (dir == 'E')
    {
        player->dirX = 1;
        player->dirY = 0;
        player->planeX = 0;
        player->planeY = 0.66;
    }
    else if (dir == 'W')
    {
        player->dirX = -1;
        player->dirY = 0;
        player->planeX = 0;
        player->planeY = -0.66;
    }
    else if (dir == 'S')
    {
        player->dirX = 0;
        player->dirY = 1;
        player->planeX = 0.66;
        player->planeY = 0;
    }
    else if (dir == 'N')
    {
        player->dirX = 0;
        player->dirY = -1;
        player->planeX = -0.66;
        player->planeY = 0;
    }
}

void	player_info(t_player *player)
{
	player->pos_x = 5;
	player->pos_y = 5;
	player_direction(player, 'S');
	player->cam_height = WINDOW_HEIGHT / 2;
}

void convert_image(t_data *data, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->mlx, path, &image->width, &image->height);
	image->address = mlx_get_data_addr(image->img,
		&image->bits_pixel, &image->line_length, &image->endian);
}

void	data_info(t_data *data)
{
	data->ceiling_color = 0xADD8E6;
	data->floor_color = 0x964B00;
	data->test_color = 0x00008B;
}

void	run_game(t_data *data) // this is like the callback
{
	data_info(data);
	player_info(&data->player);
	cast_rays(data, &data->player);
	mlx_hook(data->window, 2, 0, &on_keypress, data);
	mlx_hook(data->window, 3, 0, &on_keyrelease, data);
	mlx_hook(data->window, 17, 1L << 17, &exit_game, data);
	mlx_loop_hook(data->mlx, &hook_loop, data);
	mlx_loop(data->mlx);
}

int	main(void)
{
	t_data data;

	data.mlx = mlx_init();
	// data.player = calloc(1, sizeof(t_player *));
	// data.ray = calloc(1, sizeof(t_ray *));
	// data.game = calloc(1, sizeof(t_game *));
	data.game = calloc(1, sizeof(t_game *));
	data.game->game_map = calloc(10, sizeof(char *));
	// data.image = calloc(1, sizeof(t_image *));
	// data.sample_texture = calloc(1, sizeof(t_image *));
	data.game->game_map[0] = strdup("1111111111111111111111111111");
	data.game->game_map[1] = strdup("1000000000000000000000001001");
	data.game->game_map[2] = strdup("1000000000000000000000001001");
	data.game->game_map[3] = strdup("1000000000000001010100000001");
	data.game->game_map[4] = strdup("1000000000000000000000001001");
	data.game->game_map[5] = strdup("1000000000101010000000000101");
	data.game->game_map[6] = strdup("1000000000100010000000000011");
	data.game->game_map[7] = strdup("1000000000100010000000001001");
	data.game->game_map[8] = strdup("1111111111111111111111111111");
	data.game->game_map[9] = NULL;
	data.window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
		"cub3D");
	data.image.img = mlx_new_image(data.mlx, WINDOW_WIDTH,
		WINDOW_HEIGHT);                                                          
		// we need the address too.
	data.image.address = mlx_get_data_addr(data.image.img,
		&data.image.bits_pixel, &data.image.line_length, &data.image.endian);
		// get address of image
	// convert_image(&data, &data.sample_texture, "./wall.xpm");
	convert_image(&data, &data.north_texture, "./redbrick.xpm");
	convert_image(&data, &data.south_texture, "./stone_wall.xpm");
	convert_image(&data, &data.east_texture, "./bluestone.xpm");
	convert_image(&data, &data.west_texture, "./wall_1.xpm");
	run_game(&data);
	// clean up and exit game
}
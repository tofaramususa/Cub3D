/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:53:59 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/16 20:03:08 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

	// t_data game;
	// 1. Map initialization and Window Creation - necessary information for rendering the game world
	
	//2. Raycasting - calculating the window and stuff
	//3. Rendering 
	//4. Player movement - handling rotation and movement within game world



	//initialise struct
	//parse the parameters
	//mlx_init
	//mlx_new_window
	//init_images
	//init_players
	//init colors
	//cast_rays
	//mlx_key_hook
	//mlx_hook
	//mlx_loop_hook
	//mlx_loop


//need information --  player position in the map
//player y position in the map
// map width and map height
//
void player_info(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 2;
	player->dirX = -1, //were the player is facing
	player->dirY = 0; //initial direction vector
	player->planeX = 0;
	player->planeY = 0.66; 
}
void run_game(t_data *data) //this is like the callback
{
	player_info(data->player);
	cast_rays(data, data->player);
	//function to get the textures of the different walls
	// mlx_loop                                                                                                                                               _hook() //continuously update the window using specified function
	//mlx_hook() //hook for key press
	//mlx_key_loop() //loop to keep the window open
	mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	t_data data;

	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.image.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT); //we need the address too. 
	data.image.address = (int *) mlx_get_data_addr(data.image.img, &data.image.bits_pixel, &data.image.line_length, data.image.endian); //get address of image
	run_game(&data);
	//clean up and exit game
}
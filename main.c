/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:53:59 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/14 19:01:09 by tmususa          ###   ########.fr       */
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
// void game_loop(void) //this is like the callback
// {
// 	 mlx_delete_image() //delete the image or clear window
// 	 mlx_new_image() //create a new image
// 	//cast_rays() //cast rays to render the game
// 	//mlx_put_image_to_window() //put the image to the window
// }

int main(int ac, char **av)
{
	t_data *data;
	void *mlx;
	void *window;
	void *image;
	char *address;
	void *image;
	int pixel_bits;
	int line_bytes;
	int endian;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->image-> = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT); //we need the address too. 
	address = (int *) mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian); //get address of image
	//get texture function
	cast_rays(data, data->player);
	//function to get the textures of the different walls
	// mlx_loop_hook() //continuously update the window using specified function
	//mlx_hook() //hook for key press
	//mlx_key_loop() //loop to keep the window open
	//mlx_loop()
	//clean up and exit game
}
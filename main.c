/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:53:59 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/28 17:38:22 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	run_game(t_data *data)
{
	data_info(data);
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
	// test-data
	data.game = calloc(1, sizeof(t_game *));
	data.game->game_map = calloc(10, sizeof(char *));
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
	data.image.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.image.address = mlx_get_data_addr(data.image.img,
			&data.image.bits_pixel, &data.image.line_length,
			&data.image.endian);
	run_game(&data);
	exit_game(&data);
}
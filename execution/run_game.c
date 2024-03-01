/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:53:59 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/01 20:29:36 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

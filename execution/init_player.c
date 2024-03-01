/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:40:47 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/03/01 20:29:36 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// working
static void	init_player_direction_east(t_data *data)
{
	while (data->player.dir_x < 1.0 && data->player.dir_y > 0)
	{
		rotate_right(data);
	}
}

static void	init_player_direction_west(t_data *data)
{
	while (data->player.dir_x > -1.0 || data->player.dir_y > 0.0)
	{
		rotate_left(data);
	}
}

static void	init_player_direction_north(t_data *data)
{
	while (data->player.dir_x > 0.0 || data->player.dir_y > -1.0)
	{
		rotate_left(data);
	}
}

void	init_player_direction(t_data *data, char dir)
{
	data->player.dir_x = 0;
	data->player.dir_y = 1;
	data->player.plane_x = 0.66;
	data->player.plane_y = 0;
	if (dir == 'E')
	{
		init_player_direction_east(data);
	}
	else if (dir == 'W')
	{
		init_player_direction_west(data);
	}
	else if (dir == 'N')
	{
		init_player_direction_north(data);
	}
}

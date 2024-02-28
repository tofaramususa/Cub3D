/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:40:47 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/02/28 17:57:38 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//working
static void	init_player_direction_east(t_data *data)
{
	// data->player.dirX = 1;
	// data-player->dirY = 0;
	while(data->player.dirX < 1.0 && data->player.dirY > 0)
	{
		rotate_right(data);
	}
}

static void	init_player_direction_west(t_data *data)
{
    while(data->player.dirX > -1.0 || data->player.dirY > 0.0)
    {
        rotate_left(data);
    }
}

static void	init_player_direction_north(t_data *data)
{
    while(data->player.dirX > 0.0 || data->player.dirY > -1.0)
    {
        rotate_left(data);
    }
}

void	init_player_direction(t_data *data, char dir)
{
	data->player.dirX = 0;
	data->player.dirY = 1;
	data->player.planeX = 0.66;
	data->player.planeY = 0;
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
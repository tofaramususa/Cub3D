/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:26:38 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/02/28 17:59:58 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_info(t_data *data)
{
	data->player.pos_x = 5;
	data->player.pos_y = 5;
	init_player_direction(data, 'W');
	data->player.cam_height = WINDOW_HEIGHT / 2;
}

void	data_info(t_data *data)
{
	player_info(data);
	data->ceiling_color = 0xADD8E6;
	data->floor_color = 0x964B00;
	load_texture(data, &data->north_texture, "./textures/redbrick.xpm");
	load_texture(data, &data->south_texture, "./textures/stone_wall.xpm");
	load_texture(data, &data->east_texture, "./textures/bluestone.xpm");
	load_texture(data, &data->west_texture, "./textures/wall_1.xpm");
}

void	init_keys(t_key *keys)
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

void	ray_info(t_ray *ray, t_player *player)
{
	ray->mapX = player->pos_x;
	ray->mapY = player->pos_y;
	ray->deltaX = fabs(1 / ray->rayDirX);
	ray->deltaY = fabs(1 / ray->rayDirY);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:26:38 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/02/28 18:31:24 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_info(t_data *data)
{
	data->player.pos_x = 5;
	data->player.pos_y = 5;
	init_player_direction(data, 'E');
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
	ray->map_x = player->pos_x;
	ray->map_y = player->pos_y;
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:26:38 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/03/04 15:55:21 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// function to find player position and direction
void	player_facing(t_data *data, char dir)
{
	data->player.direction = 'N';
	if (dir == 'S')
		data->player.direction = 'S';
	else if (dir == 'E')
		data->player.direction = 'E';
	else if (dir == 'W')
		data->player.direction = 'W';
}

void	find_player_position(char **map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				player->pos_x = i;
				player->pos_y = j;
				return ;
			}
		}
	}
}

void	player_info(t_data *data)
{
	find_player_position(data->map.map_data, &data->player);
	player_facing(data,
		data->map.map_data[(int)data->player.pos_x][(int)data->player.pos_y]);
	init_player_direction(data, data->player.direction);
	data->player.cam_height = WINDOW_HEIGHT / 8;
}

void	data_info(t_data *data)
{
	init_keys(&data->keys);
	data->floor_color = color_to_hex(data->map_infos.floor_color);
	data->ceiling_color = color_to_hex(data->map_infos.ceiling_color);
	player_info(data);
	load_texture(data, &data->north_texture, data->map_infos.no_path);
	load_texture(data, &data->south_texture, data->map_infos.so_path);
	load_texture(data, &data->east_texture, data->map_infos.ea_path);
	load_texture(data, &data->west_texture, data->map_infos.we_path);
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
	if (ray->raydir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->raydir_y);
	// ray->delta_x = fabs(1 / ray->raydir_x);
	// ray->delta_y = fabs(1 / ray->raydir_y);
}

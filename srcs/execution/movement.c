/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:50 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/05 15:47:35 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	go_backward(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = data->player.pos_x - data->player.dir_x * 0.3;
	new_pos_y = data->player.pos_y - data->player.dir_y * 0.3;
	if (data->map.map_data[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dir_x * 0.05;
	if ((data->map.map_data[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y -= data->player.dir_y * 0.05;
}

void	move_left(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(data->player.pos_x - data->player.dir_y * 0.3);
	new_pos_y = (int)(data->player.pos_y + data->player.dir_x * 0.3);
	if (data->map.map_data[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dir_y * 0.05;
	if ((data->map.map_data[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y += data->player.dir_x * 0.05;
}

void	move_right(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(data->player.pos_x + data->player.dir_y * 0.3);
	new_pos_y = (int)(data->player.pos_y - data->player.dir_x * 0.3);
	if (data->map.map_data[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dir_y * 0.05;
	if ((data->map.map_data[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y -= data->player.dir_x * 0.05;
}

void	rotate_left(t_data *data)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(ROTATE_SPEED)
		- data->player.dir_y * sin(ROTATE_SPEED);
	data->player.dir_y = olddir_x * sin(ROTATE_SPEED) + data->player.dir_y
		* cos(ROTATE_SPEED);
	oldplane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(ROTATE_SPEED)
		- data->player.plane_y * sin(ROTATE_SPEED);
	data->player.plane_y = oldplane_x * sin(ROTATE_SPEED) + data->player.plane_y
		* cos(ROTATE_SPEED);
}

void	rotate_right(t_data *data)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-ROTATE_SPEED)
		- data->player.dir_y * sin(-ROTATE_SPEED);
	data->player.dir_y = olddir_x * sin(-ROTATE_SPEED) + data->player.dir_y
		* cos(-ROTATE_SPEED);
	oldplane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-ROTATE_SPEED)
		- data->player.plane_y * sin(-ROTATE_SPEED);
	data->player.plane_y = oldplane_x * sin(-ROTATE_SPEED)
		+ data->player.plane_y * cos(-ROTATE_SPEED);
}

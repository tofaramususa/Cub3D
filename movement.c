/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:50 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/28 17:15:04 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	go_forward(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = data->player.pos_x + data->player.dirX * 0.05;
	new_pos_y = data->player.pos_y + data->player.dirY * 0.05;
	if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dirX * 0.05;
	if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y += data->player.dirY * 0.05;
}

void	go_backward(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = data->player.pos_x - data->player.dirX * 0.05;
	new_pos_y = data->player.pos_y - data->player.dirY * 0.05;
	if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dirX * 0.05;
	if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y -= data->player.dirY * 0.05;
}

void	move_left(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(data->player.pos_x - data->player.dirY * 0.05);
	new_pos_y = (int)(data->player.pos_y - data->player.dirX * 0.05);
	if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dirY * 0.05;
	if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y += data->player.dirX * 0.05;
}

void	move_right(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(data->player.pos_x + data->player.dirY * 0.05);
	new_pos_y = (int)(data->player.pos_y + data->player.dirX * 0.05);
	if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dirY * 0.05;
	if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y -= data->player.dirX * 0.05;
}

void	rotate_left(t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->player.dirX;
	data->player.dirX = data->player.dirX * cos(ROTATE_SPEED)
		- data->player.dirY * sin(ROTATE_SPEED);
	data->player.dirY = oldDirX * sin(ROTATE_SPEED) + data->player.dirY
		* cos(ROTATE_SPEED);
	oldPlaneX = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(ROTATE_SPEED)
		- data->player.planeY * sin(ROTATE_SPEED);
	data->player.planeY = oldPlaneX * sin(ROTATE_SPEED) + data->player.planeY
		* cos(ROTATE_SPEED);
}

void	rotate_right(t_data *data)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = data->player.dirX;
	data->player.dirX = data->player.dirX * cos(-ROTATE_SPEED)
		- data->player.dirY * sin(-ROTATE_SPEED);
	data->player.dirY = oldDirX * sin(-ROTATE_SPEED) + data->player.dirY
		* cos(-ROTATE_SPEED);
	oldPlaneX = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-ROTATE_SPEED)
		- data->player.planeY * sin(-ROTATE_SPEED);
	data->player.planeY = oldPlaneX * sin(-ROTATE_SPEED) + data->player.planeY
		* cos(-ROTATE_SPEED);
}
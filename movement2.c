/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:50 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/25 18:16:43 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void player_movement(t_data *data)
// {
// 	//Rotate camera
// 	data->player.dirX = data->player.dirX * cos() — data->player.dirY * sin();
// 	data->player.dirX = data->player.dirX * sin() + data->player.dirY * cos();

// 	data->player.planeX = data->player.planeX * cos() — data->player.planeY * sin();
// 	data->player.planeY = data->player.planeX * sin() + data->player.planeY * cos();

// 	//Move back and forth
// 	data->player.pos_x += data->player.dirX * MOVE_SPEED;
// 	data->player.pos_y += data->player.dirY * MOVE_SPEED;

// 	//move sideways
// 	data->player.pos_x += data->player.dirX * MOVE_SPEED;
// 	data->player.pos_y += data->player.dirY * MOVE_SPEED;
// }

void go_forward(t_data *data)
{
	int new_pos_x;
	int new_pos_y;
	
	new_pos_x = (int)data->player.pos_x + data->player.dirX * MOVE_SPEED;
	new_pos_y = (int)(int)data->player.pos_y + data->player.dirY * MOVE_SPEED;
	
	if (data->game->map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x = new_pos_x;
	if ((data->game->map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y = new_pos_y;
}

void go_backward(t_data *data)
{
	int new_pos_x;
	int new_pos_y;
	
	new_pos_x = (int)data->player.pos_x - data->player.dirX * MOVE_SPEED;
	new_pos_y = (int)(int)data->player.pos_y - data->player.dirY * MOVE_SPEED;

	if (data->game->map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x = new_pos_x;
	if ((data->game->map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y = new_pos_y;	
}


void move_left(t_data *data)
{
	int new_pos_x;
	int new_pos_y;
	
	new_pos_x = (int)data->player.pos_x - data->player.cameraX * MOVE_SPEED;
	new_pos_y = (int)data->player.pos_y - data->player.cameraX * MOVE_SPEED;

	if (data->game->map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x = new_pos_x;
	if ((data->game->map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y = new_pos_y;	
}

void move_right(t_data *data)
{
	int new_pos_x;
	int new_pos_y;
	
	new_pos_x = (int)data->player.pos_x + data->player.cameraX * MOVE_SPEED;
	new_pos_y = (int)data->player.pos_y + data->player.cameraX * MOVE_SPEED;

	if (data->game->map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x = new_pos_x;
	if ((data->game->map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y = new_pos_y;		
}


void rotate_left(t_data *data)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = data->player.dirX;
	
	data->player.dirX = data->player.dirX * cos(ROTATE_SPEED) - data->player.dirY * sin(ROTATE_SPEED);
	data->player.dirY = oldDirX * sin(ROTATE_SPEED) + data->player.dirY * cos(ROTATE_SPEED);

	oldPlaneX = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(ROTATE_SPEED) - data->player.planeY * sin(ROTATE_SPEED);
	data->player.planeY = oldPlaneX * sin(ROTATE_SPEED) + data->player.planeY * cos(ROTATE_SPEED);
}

void rotate_right(t_data *data)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = data->player.dirX;
	data->player.dirX = data->player.dirX * cos(-ROTATE_SPEED) - data->player.dirY * sin(-ROTATE_SPEED);
	data->player.dirY = oldDirX * sin(-ROTATE_SPEED) + data->player.dirY * cos(-ROTATE_SPEED);

	oldPlaneX = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-ROTATE_SPEED) - data->player.planeY * sin(-ROTATE_SPEED);
	data->player.planeY = oldDirX * sin(-ROTATE_SPEED) + data->player.planeY * cos(-ROTATE_SPEED);
}

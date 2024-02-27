/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:50 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/27 23:07:30 by tofaramusus      ###   ########.fr       */
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
	
	new_pos_x = data->player.pos_x + data->player.dirX * 0.05;
	new_pos_y = data->player.pos_y + data->player.dirY * 0.05;

	
	if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dirX * 0.05;
	if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y += data->player.dirY * 0.05;
}

void go_backward(t_data *data)
{
	int new_pos_x;
	int new_pos_y;
	
	new_pos_x = data->player.pos_x - data->player.dirX * 0.05;
	new_pos_y = data->player.pos_y - data->player.dirY * 0.05;

	if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dirX * 0.05;
	if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y -= data->player.dirY * 0.05;;	
}

void move_right(t_data *data)
{
    int new_pos_x;
    int new_pos_y;

    new_pos_x = (int)(data->player.pos_x - data->player.dirY * 0.05);
    new_pos_y = (int)(data->player.pos_y + data->player.dirX * 0.05);

    if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
        data->player.pos_x -= data->player.dirY * 0.05;
    if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
        data->player.pos_y += data->player.dirX * 0.05;
}

void move_left(t_data *data)
{
    int new_pos_x;
    int new_pos_y;

    new_pos_x = (int)(data->player.pos_x + data->player.dirY * 0.05);
    new_pos_y = (int)(data->player.pos_y - data->player.dirX * 0.05);

    if (data->game->game_map[new_pos_x][(int)data->player.pos_y] != '1')
        data->player.pos_x += data->player.dirY * 0.05;
    if ((data->game->game_map[(int)data->player.pos_x][new_pos_y] != '1'))
        data->player.pos_y -= data->player.dirX * 0.05;
}


void rotate_right(t_data *data)
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

void rotate_left(t_data *data)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = data->player.dirX;
	data->player.dirX = data->player.dirX * cos(-ROTATE_SPEED) - data->player.dirY * sin(-ROTATE_SPEED);
	data->player.dirY = oldDirX * sin(-ROTATE_SPEED) + data->player.dirY * cos(-ROTATE_SPEED);

	oldPlaneX = data->player.planeX;
	data->player.planeX = data->player.planeX * cos(-ROTATE_SPEED) - data->player.planeY * sin(-ROTATE_SPEED);
	data->player.planeY = oldPlaneX * sin(-ROTATE_SPEED) + data->player.planeY * cos(-ROTATE_SPEED);
}
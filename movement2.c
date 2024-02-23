/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:39:50 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/23 18:27:00 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void player_movement(t_data *data)
// {
// 	//Rotate camera
// 	data->player->dirX = data->player->dirX * cos() — data->player->dirY * sin();
// 	data->player->dirX = data->player->dirX * sin() + data->player->dirY * cos();

// 	data->player->planeX = data->player->planeX * cos() — data->player->planeY * sin();
// 	data->player->planeY = data->player->planeX * sin() + data->player->planeY * cos();

// 	//Move back and forth
// 	data->player->pos_x += data->player->dirX * WEIGHT;
// 	data->player->pos_y += data->player->dirY * WEIGHT;

// 	//move sideways
// 	data->player->pos_x += data->player->dirX * WEIGHT;
// 	data->player->pos_y += data->player->dirY * WEIGHT;
// }

void go_forward(t_data *data)
{
	data->player->pos_x += data->player->dirX * WEIGHT;
	data->player->pos_y += data->player->dirY * WEIGHT;
}


void go_backward(t_data *data)
{
	data->player->pos_x -= data->player->dirX * WEIGHT;
	data->player->pos_y -= data->player->dirY * WEIGHT;	
}


void move_left(t_data *data)
{
	data->player->pos_x -= data->player->cameraX * WEIGHT;
	data->player->pos_y -= data->player->cameraX * WEIGHT;	
}

void move_right(t_data *data)
{
	data->player->pos_x += data->player->cameraX * WEIGHT;
	data->player->pos_y += data->player->cameraX * WEIGHT;	
}


void rotate_left(t_data *data)
{
	data->player->dirX = data->player->dirX * cos(ROTATE_LEFT) — data->player->dirY * sin(ROTATE_LEFT);
	data->player->dirX = data->player->dirX * sin(ROTATE_LEFT) + data->player->dirY * cos(ROTATE_LEFT);

	data->player->planeX = data->player->planeX * cos(ROTATE_LEFT) — data->player->planeY * sin(ROTATE_LEFT);
	data->player->planeY = data->player->planeX * sin(ROTATE_LEFT) + data->player->planeY * cos(ROTATE_LEFT);
}

void rotate_right(t_data *data)
{
	data->player->dirX = data->player->dirX * cos(ROTATE_RIGHT) - data->player->dirY * sin(ROTATE_RIGHT);
	data->player->dirX = data->player->dirX * sin(ROTATE_RIGHT) + data->player->dirY * cos(ROTATE_RIGHT);

	data->player->planeX = data->player->planeX * cos(ROTATE_RIGHT) — data->player->planeY * sin(ROTATE_RIGHT);
	data->player->planeY = data->player->planeX * sin(ROTATE_RIGHT) + data->player->planeY * cos(ROTATE_RIGHT);
}



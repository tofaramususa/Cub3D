/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:30:21 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/25 19:07:03 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	draw_minimap(t_data *data)
// {
// 	int column;
// 	int row;
// 	double scale_x = (double)100 / data->map_columns;
// 	double scale_y = (double)100 / data->map_rows;

// 	column = -1;
// 	while (++column < data->map_columns)
// 	{
// 		row = -1;
// 		while (row < data->map_rows)
// 		{
// 			if (data->game->map[row][column] == '1')
// 			{
// 				color_pixel(&data->minimap, column * scale_x, row * scale_y, 0xFFFFFF);
// 			}
// 		}
// 	}
// 	color_pixel(&data->minimap, data->player.pos_x * scale_x, data->player.pos_y * scale_y, 0xFFA500);
// }


void draw_minimap(t_data *data, int x, int y)
{
	int i;
	int j;

	i = -1;

	while(++i < y)
	{
		j = -1;
		while(++j < x)
		{
			if(data->game->map[i / 8][j /8] == '1')
				data->minimap.address[i * x + j] = data->ceiling_color;
			else
				data->minimap.address[i * x + j] = data->floor_color;
		}
	}
	
	color_pixel(&data->minimap, data->player.pos_x, data->player.pos_y, data->floor_color);
}
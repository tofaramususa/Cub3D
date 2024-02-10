/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:29:17 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/10 21:33:15 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void calculate_distances(t_ray *ray, t_player *player)
{
	ray->deltaX = abs(1 / ray->rayDirX);
	ray->deltaY = abs(1 / ray->rayDirY);
	ray->mapX = player->pos_x;
	ray->mapY = player->pos_y;
	
	ray->deltaX = (ray->rayDirX == 0) ? 1e30 : abs(1 / ray->rayDirX);
	ray->deltaY = (ray->rayDirY == 0) ? 1e30 : abs(1 / ray->rayDirY);
	

	
}

int wall_position(t_ray *ray)
{
	char **realMap; //this is the actual map we have
	int hit = 0;

	while(hit = 0)
	{
		if (ray->sideX < ray->sideY)
		{
			ray->sideX += ray->deltaX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideY += ray->deltaY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}

		if(realMap[ray->mapX][ray->mapY] > 0) //we are checking if we inside wall
			hit = 1;
	}
}



//reset ray struct
void initiate_ray(t_ray *ray)
{
	
}
//for casting each ray
void cast_ray(t_player *player)
{
	int x = -1;
	double cameraX;
	t_ray *ray;

	while(++x < WINDOW_WIDTH)
	{
		initiate_ray(ray);
		cameraX = 2 * x / double(w) - 1;
		ray->rayDirX = player->dirX + player->planeX * cameraX;
		ray->rayDirY = player->dirY + player->planeY * cameraX;
		calculate_distances(ray, player);
		wall_position(ray);
		
	}
}
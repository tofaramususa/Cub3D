/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:30:46 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/02/28 16:35:34 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void calculate_step_and_side_distances(t_ray *ray, t_player *player)
{
    if (ray->rayDirX < 0)
    {
        ray->stepX = -1;
        ray->sideX = (player->pos_x - ray->mapX) * ray->deltaX;
    }
    else
    {
        ray->stepX = 1;
        ray->sideX = (ray->mapX + 1.0 - player->pos_x) * ray->deltaX;
    }
    if (ray->rayDirY < 0)
    {
        ray->stepY = -1;
        ray->sideY = (player->pos_y - ray->mapY) * ray->deltaY;
    }
    else
    {
        ray->stepY = 1;
        ray->sideY = (ray->mapY + 1.0 - player->pos_y) * ray->deltaY;
    }
}

static void find_wall_and_calculate_distance(t_game *game, t_ray *ray)
{
    int hit = 0;
    while (hit == 0)
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
        if (game->game_map[ray->mapX][ray->mapY] == '1')
            hit = 1;
    }
    if (ray->side == 0)
        ray->perpWallDist = (ray->sideX - ray->deltaX);
    else
        ray->perpWallDist = (ray->sideY - ray->deltaY);
}

void wall_distance(t_game *game, t_ray *ray, t_player *player)
{
    calculate_step_and_side_distances(ray, player);
    find_wall_and_calculate_distance(game, ray);
}
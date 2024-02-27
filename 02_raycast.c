/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:29:17 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/27 23:01:58 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_info(t_ray *ray, t_player *player)
{
	ray->mapX = player->pos_x;
	ray->mapY = player->pos_y;
	ray->deltaX = fabs(1 / ray->rayDirX);
	ray->deltaY = fabs(1 / ray->rayDirY);
}
void	color_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->address + (y * image->line_length + x * (image->bits_pixel
			/ 8));
	*(unsigned int *)dst = color;
}

void	wall_distance(t_game *game, t_ray *ray, t_player *player)
{
	int	hit;

	hit = 0;
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

void	paint_line(t_data *root, t_line *line, int rgb)
{
	int	y;
	int	y_max;

	y = line->y0;
	y_max = line->y1;
	if (y >= 0)
	{
		while (y < y_max)
		{
			color_pixel(&root->image, line->x, y, rgb);
			y++;
		}
	}
}

void	get_line_height(t_ray *ray)
{
	ray->line_height = (int)(WINDOW_HEIGHT / ray->perpWallDist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
}

void	draw_wall(t_data *root, t_ray *ray, int current_x)
{
	t_line	line;

	double wall_x; //where exactly the wall was hit
	if (ray->side == 0)
		wall_x = root->player.pos_y + ray->perpWallDist * ray->rayDirY;
	else
		wall_x = root->player.pos_x + ray->perpWallDist * ray->rayDirX;
	wall_x -= floor(wall_x);
	line.x = current_x;
	get_line_height(ray);
	if (root->game->game_map[ray->mapX][ray->mapY] == '1')
	{
		line.y0 = ray->draw_start;
		line.y1 = ray->draw_end;
		paint_texture_line(root, ray, &line, wall_x);
	}
	line.y0 = 0;
	line.y1 = ray->draw_start;
	paint_line(root, &line, root->ceiling_color);
	line.y0 = ray->draw_end;
	line.y1 = WINDOW_HEIGHT;
	paint_line(root, &line, root->floor_color);
}

void cast_rays(t_data *data, t_player *player)
{
	int current_x = -1;

	mlx_clear_window(data->mlx, data->window);
	while (++current_x < WINDOW_WIDTH)
	{
		data->player.cameraX = 2 * current_x / (double)WINDOW_WIDTH - 1;
		data->ray.rayDirX = player->dirX + player->planeX * data->player.cameraX;
		data->ray.rayDirY = player->dirY + player->planeY * data->player.cameraX; 
		ray_info(&data->ray, player);
		wall_distance(data->game, &data->ray, &data->player);
		draw_wall(data, &data->ray, current_x);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.img,
		0, 0);
}

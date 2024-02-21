/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:29:17 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/21 22:08:21 by tmususa          ###   ########.fr       */
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
	int counter = 0;
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
			counter++;
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
			color_pixel(root->image, line->x, y, rgb);
			y++;
		}
	}
}
// reset ray struct
// void	initiate_ray(t_ray *ray)
// 	//reset ray position which comes from parsing
// {

// }
// for casting each ray

// NEED FUNCTION TO IMPLEMENT RAY DRAW START AND END;
void	get_line_height(t_ray *ray) // to set draw_start and draw_end
{
	ray->line_height = (int)(WINDOW_HEIGHT / ray->perpWallDist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
	// printf("line-height: %d\n", ray->line_height);
	// we know the distance between the wall the cam vector
}


void copy_texture_pixel(t_image *image, t_image *texture, t_line *line)
{
	char *dst;
	char *src;

	// printf("texture->bits_pixel: %d\n", texture->bits_pixel);
	dst = image->address + (line->y * image->line_length + line->x
		* (image->bits_pixel / 8));
			src = texture->address + (line->tex_y * texture->line_length
				+ line->tex_x
		* (texture->bits_pixel / 8));
			dst = src;
	// exit(0);
}

void	texture_on_img(t_data *root, t_ray *ray, t_line *line,
		t_image *texture)
{
	int	scale;

	//the line length may be zero
	scale = line->y * texture->line_length - (WINDOW_HEIGHT
			* root->player->cam_height) * texture->line_length / 2
		+ ray->line_height * texture->line_length / 2;
	line->tex_y = ((scale * texture->height) / ray->line_height);
	copy_texture_pixel(root->image, texture, line);
}

void	paint_texture_line(t_data *root, t_ray *ray, t_line *line, int wall_x)
{
	int y_max;
	line->y = line->y0;
	
	y_max = line->y1;
	line->tex_x = (int)(wall_x * (double)root->sample_texture->width);
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			texture_on_img(root, ray, line,
				root->sample_texture);
			line->y++;
			// exit(0);
		}
	}
}

void	draw_wall(t_data *root, t_ray *ray, int current_x)
{
	t_line	*line;
	double wall_x;

	line = calloc(1, sizeof(t_line *));
	if (ray->side == 0)
		wall_x = root->player->pos_y + ray->perpWallDist * ray->rayDirY;
	else
		wall_x = root->player->pos_x + ray->perpWallDist * ray->rayDirX;
	wall_x -= floor(wall_x);
	line->x = current_x;
	get_line_height(ray);
	if (root->game->game_map[ray->mapX][ray->mapY] == '1')
	{
		line->y0 = ray->draw_start;
		line->y1 = ray->draw_end;
		// paint_line(root, &line, root->test_color);
		// exit(0);
		paint_texture_line(root, ray, line, wall_x);
	}
	line->y0 = 0;
	line->y1 = ray->draw_start;
	paint_line(root, line, root->ceiling_color);
	line->y0 = ray->draw_end;
	line->y1 = WINDOW_HEIGHT;
	paint_line(root, line, root->floor_color);
	// exit(0);
}
void cast_rays(t_data *data, t_player *player)
{
	int current_x = -1;
	double cameraX;

	mlx_clear_window(data->mlx, data->window);
	while (++current_x < WINDOW_WIDTH)
	{
		// initiate_ray(ray);
		// printf("%d\n", current_x);
		cameraX = 2 * current_x / (double)WINDOW_WIDTH - 1;
		// printf("cameraX:%f\n", cameraX);
		data->ray->rayDirX = player->dirX + player->planeX * cameraX;
		// this is the direction of the ray
		data->ray->rayDirY = player->dirY + player->planeY * cameraX;
		// printf("ray directionX: %f, ray directionY: %f\n",data->ray->rayDirX, data->ray->rayDirY);
		// printf("rayDirX %f\n, rayDirY %f\n", data->ray->rayDirX, data->ray->rayDirY);
		ray_info(data->ray, player);
		wall_distance(data->game, data->ray, data->player);
		// printf("mapX: %d, mapY: %d\n", data->ray->mapX, data->ray->mapY);
		// printf("perpendicular wall distance: %f\n", data->ray->perpWallDist);
		// get_texture(root->game); we need to use the ray direction to find the texture to put on
		// exit(0);
		draw_wall(data, data->ray, current_x);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image->img,
		0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:29:17 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/02 01:26:56 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	color_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->address + (y * image->line_length + x * (image->bits_pixel
				/ 8));
	*(unsigned int *)dst = color;
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
	ray->line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
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
	double	wall_x;

	if (ray->side == 0)
		wall_x = root->player.pos_y + ray->wall_dist * ray->raydir_y;
	else
		wall_x = root->player.pos_x + ray->wall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	line.x = current_x;
	get_line_height(ray);
	if (root->map.map_data[ray->map_x][ray->map_y] == '1')
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

void	cast_rays(t_data *data, t_player *player)
{
	int	current_x;

	current_x = -1;
	mlx_clear_window(data->mlx, data->window);
	while (++current_x < WINDOW_WIDTH)
	{
		data->player.camera_x = 2 * current_x / (double)WINDOW_WIDTH - 1;
		data->ray.raydir_x = player->dir_x + player->plane_x
			* data->player.camera_x;
		data->ray.raydir_y = player->dir_y + player->plane_y
			* data->player.camera_x;
		ray_info(&data->ray, player);
		wall_distance(&data->map, &data->ray, &data->player);
		draw_wall(data, &data->ray, current_x);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
}

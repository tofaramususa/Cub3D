/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:31:53 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/02/27 23:01:12 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void copy_texture_pixel(t_image *image, t_image *texture, t_line *line)
{
	int color;
	char *dst;
	char *src;

	src = texture->address + (line->tex_y * texture->line_length + line->tex_x * (texture->bits_pixel / 8));
	dst = image->address + (line->y * image->line_length + line->x * (image->bits_pixel / 8));
	color = *(unsigned int *)src;
	*(unsigned int *)dst = color;
}

t_image *check_side(t_ray *ray, t_game *game)
{
	if (ray->side == 0 && ray->rayDirX > 0)
		return (&game->east_texture);
	if (ray->side == 0 && ray->rayDirX < 0)
		return (&game->west_texture);
	if (ray->side == 1 && ray->rayDirY > 0)
		return (&game->south_texture);
	return (&game->north_texture);
}

void	paint_texture_line(t_data *root, t_ray *ray, t_line *line, double wall_x)
{
	int y_max;
	double step;
	double texPos;

	
	line->y = line->y0;
	y_max = line->y1;
	
	line->tex_x = (int)(wall_x * (double)root->sample_texture.width);
	if(ray->side == 0 && ray->rayDirX > 0) //checking for the side of the wall
		line->tex_x = root->sample_texture.width - line->tex_x - 1; //touches x axis - south
	if(ray->side == 1 && ray->rayDirY < 0)
		line->tex_x = root->sample_texture.width - line->tex_x - 1;	//touches y axis (west)
	step = 1.0 * root->sample_texture.height / ray->line_height;
	texPos = (ray->draw_start - WINDOW_HEIGHT / 2 + ray->line_height / 2) * step;
	while (line->y < y_max)
		{
			line->tex_y = (int)texPos & (root->sample_texture.height - 1);
			texPos += step;
			copy_texture_pixel(&root->image, &root->sample_texture, line);
			line->y++;
		}
}
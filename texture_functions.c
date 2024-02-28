/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:31:53 by tofaramusus       #+#    #+#             */
/*   Updated: 2024/02/28 16:56:09 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	copy_texture_pixel(t_image *image, t_image *texture, t_line *line)
{
	int		color;
	char	*dst;
	char	*src;

	src = texture->address + (line->tex_y * texture->line_length + line->tex_x
			* (texture->bits_pixel / 8));
	dst = image->address + (line->y * image->line_length + line->x
			* (image->bits_pixel / 8));
	color = *(unsigned int *)src;
	*(unsigned int *)dst = color;
}

t_image	*check_texture_side(t_ray *ray, t_data *data)
{
	if (ray->side == 0 && ray->rayDirX > 0)
		return (&data->east_texture);
	if (ray->side == 0 && ray->rayDirX < 0)
		return (&data->west_texture);
	if (ray->side == 1 && ray->rayDirY > 0)
		return (&data->south_texture);
	return (&data->north_texture);
}

void	paint_texture_line(t_data *root, t_ray *ray, t_line *line,
		double wall_x)
{
	int		y_max;
	double	step;
	double	texPos;
	t_image	*texture;

	texture = check_texture_side(ray, root);
	line->y = line->y0;
	y_max = line->y1;
	line->tex_x = (int)(wall_x * (double)texture->width);
	if (ray->side == 0 && ray->rayDirX > 0)
		line->tex_x = texture->width - line->tex_x - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		line->tex_x = texture->width - line->tex_x - 1;
	step = 1.0 * texture->height / ray->line_height;
	texPos = (ray->draw_start - WINDOW_HEIGHT / 2 + ray->line_height / 2)
		* step;
	while (line->y < y_max)
	{
		line->tex_y = (int)texPos & (texture->height - 1);
		texPos += step;
		copy_texture_pixel(&root->image, texture, line);
		line->y++;
	}
}

//change this function to check if the texture is already loaded or if it failed then free and exit
void	load_texture(t_data *data, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->mlx, path, &image->width,
			&image->height);
	image->address = mlx_get_data_addr(image->img, &image->bits_pixel,
			&image->line_length, &image->endian);
}
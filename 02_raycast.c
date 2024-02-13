/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:29:17 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/13 18:50:56 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_values(t_ray *ray, t_player *player) //this to calculate positions
{
	// ray->deltaX = abs(1 / ray->rayDirX);
	// ray->deltaY = abs(1 / ray->rayDirY);
	ray->mapX = player->pos_x;
	ray->mapY = player->pos_y;
	ray->deltaX = abs(1 / ray->rayDirX);
	ray->deltaY = abs(1 / ray->rayDirY);
}

int	wall_position(t_ray *ray)
{
	int	hit;

	char **realMap; // this is the actual map we have
	hit = 0;
	while (hit = 0)
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
		if (realMap[ray->mapX][ray->mapY] > 0)
			// we are checking if we inside real map
			hit = 1;
	}
	if (ray->side == 0) //not sure here
		ray->perpWallDist = (ray->sideX - ray->deltaX);
	else
		ray->perpWallDist = (ray->sideY - ray->deltaY);
}

// reset ray struct
void	initiate_ray(t_ray *ray)
{
}
// for casting each ray

//NEED FUNCTION TO IMPLEMENT RAY DRAW START AND END;
void get_line_height(t_ray * ray) //to set draw_start and draw_end
{
	ray->line_height = (int)(WINDOW_HEIGHT / ray->perpWallDist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	//we know the distance between the wall the cam vector
}

void	draw_wall(t_player *player, t_ray *ray, int current_x)
{
	t_line	line;
	double	wall_x; //what is wall x for 

	if (ray->side == WEST || ray->side == EAST) //not sure here what side is?, wait maybe it is side the ray is hitting
		wall_x = player->pos_y + ray->perpWallDist * ray->rayDirY;
	else
		wall_x = player->pos_x + ray->perpWallDist * ray->rayDirX;
	wall_x -= floor(wall_x); //this is to get the texture x coordinate
	line->x = current_x; //how do l find current
	// paint texture if the ray hits a wall
	line->y0 = 0;//start at top of screen
	if (root->game->map[ray->mapX][ray->mapY] == 1) //confirm if the ray hits the wall
	{
		line->y0 = ray->draw_start; //start at top start of draw_line
		line->y1 = ray->draw_end; //end at the end of draw_line
		paint_texture_line(root, ray, line, wall_x); //paint the texture line using the wall_x
	}
	get_line_height(ray); //get the line height
	line->y1 = ray->draw_start; //end of the wall
	paint_line(root, line, root->crgb); //paint the ceiling
	
	line->y0 = ray->draw_end; //we need to know the end of the wall
	// start at bottom of page
	line->y1 = WINDOW_HEIGHT;
	// function to paint a solid color
	paint_line(root, line, root->frgb);
}

//we change the pixel of the root image data the line
pixel_on_img(int rgb, int x, int y, t_image *img)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8] = b;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 1] = g;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 2] = r;
}

//we change the pixel of the root image data
void	texture_on_img(t_data *root, t_ray *ray, t_line *line, t_image *texture)
{
	int	scale;
	//we dont know  the line_height
	//we dont know texture line length
	// we dont know player cam_height
	// we dont know

	scale = line->y - (WINDOW_HEIGHT / 2) + ray->line_height / 2;
	scale = line->y * texture->line_length - (WINDOW_HEIGHT
			* root->game->player->cam_height) * texture->line_length / 2
		+ ray->line_height * texture->line_length / 2;
	line->tex_y = ((scale * texture->height) / ray->line_height);
	// we will need to adjust with line length so the formula becomes
	line->tex_y = ((scale * texture->height) / ray->line_height)
		/ texture->line_length;
	// we can just simply modify the root image data
	// itself with the values we obtained above
	// line->y - the y point of the current vertical line
	// line->x - the x point of the current vertical line
	// line->tex_y - the y point of the texture
	// line->tex_x - the x point of the texture
	// texture->bitsperpixel - bpp/8 = r, (bpp/8) + 1 = g, (bpp/8) + 2 = b,
	//              Very wack need to refer to minilibx docs
	root->mlx_img->data[line->y + line->x * root->mlx_img->bits_per_pixel
		/ 8] = texture->data[line->tex_y + line->tex_x
		* (texture->bits_per_pixel / 8)];
	// and to adjust for line size
	root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
		* root->mlx_img->bits_per_pixel / 8] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)];
}

//we paint the texture line
void	paint_texture_line(t_data *root, t_line *line, int rgb) // or paint_texture_line
{
	int y;
	int y_max;
	
	y = line->y0;
	y_max = line->y1;
	if (y >= 0)
	{
		while (y < y_max)
		{
			texture_on_img(rgb, line->x, y, root->mlx_img);
			y++;
		}
	}
}

//we paint the texture line
void	paint_line(t_data *root, t_line *line, int rgb) // or paint_texture_line
{
	int y;
	int y_max;

	y = line->y0;
	y_max = line->y1;
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_on_img(rgb, line->x, y, root->mlx_img);
			y++;
		}
	}
}

void	cast_ray(t_player *player)
{
	int x = -1;
	double cameraX;
	t_ray *ray;

	while (++x < WINDOW_WIDTH)
	{
		initiate_ray(ray);
		cameraX = 2 * x / double(WINDOW_WIDTH) - 1; //this is the x coordinate of the camera
		ray->rayDirX = player->dirX + player->planeX * cameraX; //this is the direction of the ray
		ray->rayDirY = player->dirY + player->planeY * cameraX; //this is the direction of the ray
		initiate_values(ray, player); //this is the intial_values of the ray;
		wall_position(ray); //we have the x and y of the wall;
		draw_wall(player, ray, x)
	}
}
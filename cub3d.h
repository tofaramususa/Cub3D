/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:56:47 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/10 20:12:39 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WINDOW_WIDTH 650

//player information
typedef struct s_player
{
	double pos_x; //initial player position
	double pos_y; // ''
	double dirX; //initial direction
	double dirY; //initial direction
	double planeX; //initial POV
	double planeY; //initial POV
	
	
}	t_player;

//ray infomation
//
typedef struct s_ray
{
	rayDirX; //this the direction of the ray;
	rayDirY; //this is the direction of the ray
	int mapX; //position of the ray inside map
	int mapY;  //position of the ray inside map
	deltaX;
	deltaY;
	sideX;
	sideY;
	int stepX; //direction to step in X or Y
	int stepY; //
	int hit; //was a wall hit
	int side; //was a NS or a EW wall hit
	double perpWallDist;
	
 
} t_ray;




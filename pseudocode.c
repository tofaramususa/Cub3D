// 
// posX, posY - player position vector
// dirX, dirY - player direction vector
// planeX, planeY - how do l find this?
// Ray starting point(posx, posy)
// Viewing Angle (FOV) - x = tan(33) - 0.6494
// cameraX = 2 * x/(double)WIN_X - 1;
// The Ray Vector = rayDirectionX and rayDirectionY
// r->raydir_x = v->dir_x + v->pln_x * r->cam_x;
// r->raydir_y = v->dir_y + v->pln_y * r->cam_x;
// 
// DDA 
// mapX, mapY = the current square of the map the ray is in
// sideDist - distance the ray has travelled from its starting position to the first x and y side
// deltaDistX, deltaDistY - distance the ray has to travel to go from 1 side to the next
// deltaDistX = abs(1 / rayDirX)
// deltaDistY = abs(1 / rayDirY)
// stepX - direction (1 or -1) moving in the x directin
// stepY - variable direction (1 or -1) when moving in the y direction
// sideDistX - distance travelled by the ray from starting point to where it meets x plane
// sideDistY -distance travelled by the ray from starting point to where it meets y plane
// deltaDistX - distance the ray travels from the first x plan to the next x plane
// deltaDisty - distance the ray travels from the first x plan to the next y plane
// dda_->map_x = (int)data->pos.x;
// dda_->map_y = (int)data->pos.y;
// if (rayDirX < 0)
// sideDistX = (posX — mapX) * deltaDistX;
// else
// sideDistX = (mapX + 1 — posX) * deltaDistX;
// if (rayDirY < 0)
// sideDistY = (posY — mapY) * deltaDistY;
// else
// sideDistY = (mapY + 1 — posY) * deltaDistY;
// 
// if (sideDistX < sideDistY)
// {
// sideDistX += deltaDistX;
// mapX += stepX;
// side = WALL_X; // 0
// }
// else
// {
// sideDistY += deltaDistY;
// mapY += stepY;
// side = WALL_Y; // 1
// }
// if (mapArr[mapY][mapX] == ‘1’) hit = 1
// else hit = 0
// 
// if(side == 0) perpWallDist = (sideDistX — deltaDistX);

// else perpWallDist = (sideDistY — deltaDistY);
// 
// if(side == 0) perpWallDist = (sideDistX — deltaDistX);

// else perpWallDist = (sideDistY — deltaDistY);
// 
// Calculate distance from staring point of the ray to wall
//if(side == 0)
// perpWallDist = (sideDistX — deltaDistX);
// else
// perpWallDist = (sideDistY — deltaDistY);
//Calculate height of line to draw on screen

// wall->line_height = (int)(HEIGHT / wall->perp_wall_dist);

//calculate lowest and highest pixel to fill in current stripe

// wall->draw_start = -wall->line_height / 2 + HEIGHT / 2;

// if (wall->draw_start < 0)

// wall->draw_start = 0;

// wall->draw_end = wall->line_height / 2 + HEIGHT / 2;

// if (wall->draw_end >= HEIGHT)

// wall->draw_end = HEIGHT — 1;

//Rotate the view
// dirX = dirX * cos(theta) — dirY * sin(theta);

// dirY = dirX * sin(theta) + dirY * cos(theta);

// Rotate the camera plane
// planeX = planeX * cos(theta) — planeY * sin(theta);

// planeY = planeX * sin(theta) + planeY * cos(theta);

// move back and forth
// posX += dirX * WEIGHT;
// posY += dirY * WEIGHT;

//move sideways
// posX += cameraX * WEIGHT;

// posY += cameraY * WEIGHT;

//Adding texture to the wall:
// texturing calculations

//calculate value of wallX

// double wallX; //where exactly the wall was hit

// if (side == 0) wallX = posY + perpWallDist * rayDirY; // hits the x-side

// else wallX = posX + perpWallDist * rayDirX;// hits the y-side

// wallX -= floor((wallX));

//x coordinate on the texture

// int texX = int(wallX * double(texWidth));

// if(side == 0 && rayDirX > 0) texX = texWidth — texX — 1; touches x axis (south)

// if(side == 1 && rayDirY < 0) texX = texWidth — texX — 1; touches y axis (west)
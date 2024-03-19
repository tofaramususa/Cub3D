/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:27:22 by arashido          #+#    #+#             */
/*   Updated: 2024/03/05 15:20:08 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (!is_number(colors[i]))
		{
			print_error("Error\nInvalid numeric value in color at index\n");
			return (0);
		}
		i++;
	}
	return (i == 3);
}

static int	check_color(t_color *color)
{
	if (color->red < 0 || color->red > 255)
	{
		print_error("Error\nRed value out of range (0-255)\n");
		return (0);
	}
	if (color->green < 0 || color->green > 255)
	{
		print_error("Error\nGreen value out of range (0-255)\n");
		return (0);
	}
	if (color->blue < 0 || color->blue > 255)
	{
		print_error("Error\nBlue value out of range (0-255)\n");
		return (0);
	}
	return (1);
}

int	verify_colors(t_color *color, char **colors)
{
	if (!check_colors(colors))
	{
		print_error("Error\n");
		print_error("Invalid color format. Please use three \
		digits seperated by commas for the color \
		components (e.g., 'R,G,B').\n");
		return (WRONG_MAP);
	}
	color->red = ft_atoi(colors[0]);
	color->green = ft_atoi(colors[1]);
	color->blue = ft_atoi(colors[2]);
	if (!check_color(color))
	{
		print_error("Error\n");
		print_error("Color components must be between 0 \
and 255.\n");
		return (WRONG_MAP);
	}
	return (SUCCESS);
}

int	check_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

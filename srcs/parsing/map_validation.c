/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:27:47 by arashido          #+#    #+#             */
/*   Updated: 2024/03/05 15:12:57 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

static int	has_valid_neighbors(t_map *map, int i, int j)
{
	if (map->map_data[i][j + 1] == ' ' || map->map_data[i][j - 1] == ' '
		|| map->map_data[i + 1][j] == ' ' || map->map_data[i - 1][j] == ' ')
		return (0);
	return (1);
}

static int	verify_map_element(t_map *map, int i, int j)
{
	char	c;

	c = map->map_data[i][j];
	if (i == 0 || i == map->rows - 1 || j == 0 || j == map->cols - 1)
	{
		if (c != '1' && c != ' ')
		{
			print_error("Error\nmap is not enclosed by walls\n");
			return (0);
		}
	}
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (!has_valid_neighbors(map, i, j))
		{
			print_error("Error\nInvalid placement\n");
			return (0);
		}
	}
	return (1);
}

static int	is_enclosed_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (!verify_map_element(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_map(t_map *map)
{
	int	i;
	int	j;
	int	start_count;

	i = -1;
	start_count = 0;
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (!is_valid_map_char(map->map_data[i][j]))
			{
				return (print_error_ms("Error\nInvalid character in map\n"), 0);
			}
			if (map->map_data[i][j] == 'N' || map->map_data[i][j] == 'S'
				|| map->map_data[i][j] == 'E' || map->map_data[i][j] == 'W')
				start_count++;
		}
	}
	if (start_count != 1)
		return (print_error("Error\n Starter position"), 0);
	return (is_enclosed_map(map));
}

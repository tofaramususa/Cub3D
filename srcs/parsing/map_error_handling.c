/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:27:42 by arashido          #+#    #+#             */
/*   Updated: 2024/03/05 15:10:57 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	print_missing_elements_error(t_map_infos *map_infos)
{
	print_error("Error\n");
	print_error("Invalid map file. \
The following elements are missing:\n");
	if (map_infos->no_path_parsed != 1)
		print_error("  - NO texture path\n");
	if (map_infos->so_path_parsed != 1)
		print_error("  - SO texture path\n");
	if (map_infos->we_path_parsed != 1)
		print_error("  - WE texture path\n");
	if (map_infos->ea_path_parsed != 1)
		print_error("  - EA texture path\n");
	if (map_infos->floor_color_parsed != 1)
		print_error("  - Floor color\n");
	if (map_infos->ceiling_color_parsed != 1)
		print_error("  - Ceiling color\n");
	return (WRONG_MAP);
}

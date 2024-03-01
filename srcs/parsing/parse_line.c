/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:27:57 by arashido          #+#    #+#             */
/*   Updated: 2024/03/01 19:24:47 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

// first check if the texture path is valid
static int	parse_texture_line(t_map_infos *map_infos, t_arr *array)
{
	if (array->length != 2)
	{
		print_error("Error\n");
		print_error("Invalid texture line format. Please provide only the texture identifier and the path.\n");
		return (WRONG_MAP);
	}
	if (!check_texture(array->strings[1]))
	{
		print_error("Error\n");
		print_error("Invalid or non-existent texture path. Please provide a valid and accessible file path for the texture.\n");
		return (WRONG_MAP);
	}
	if (ft_strcmp(array->strings[0], "NO") == 0)
		map_infos->no_path = ft_strdup(array->strings[1]);
	else if (ft_strcmp(array->strings[0], "SO") == 0)
		map_infos->so_path = ft_strdup(array->strings[1]);
	else if (ft_strcmp(array->strings[0], "WE") == 0)
		map_infos->we_path = ft_strdup(array->strings[1]);
	else if (ft_strcmp(array->strings[0], "EA") == 0)
		map_infos->ea_path = ft_strdup(array->strings[1]);
	return (SUCCESS);
}

static int	check_color_line(t_map_infos *map_infos, t_arr *array)
{
	char	**colors;
	t_color	*color;

	if (array->length != 2)
	{
		print_error("Error\n");
		print_error("Invalid color line format. Please provide only the color identifier and the color components.\n");
		return (WRONG_MAP);
	}
	if (ft_strcmp(array->strings[0], "F") == 0)
		color = &map_infos->floor_color;
	else if (ft_strcmp(array->strings[0], "C") == 0)
		color = &map_infos->ceiling_color;
	if (count_commas(array->strings[1]) != 2)
	{
		print_error("Error\n");
		print_error("Wrong format color. Please use 3 comma-seperated digits\n");
		return (WRONG_MAP);
	}
	colors = ft_split(array->strings[1], ',');
	if (verify_colors(color, colors) == WRONG_MAP)
	{
		free_array(colors);
		return (WRONG_MAP);
	}
	free_array(colors);
	return (SUCCESS);
}

int	check_texture_path(t_map_infos *map_infos, t_arr *array, int *parsed_flag,
		char *type)
{
	if (*parsed_flag)
	{
		print_error("Error\n");
		print_error("Duplicate texture path: ");
		print_error(type);
		return (WRONG_MAP);
	}
	else
	{
		if (parse_texture_line(map_infos, array) != SUCCESS)
			return (WRONG_MAP);
		*parsed_flag = 1;
	}
	return (SUCCESS);
}

int	handle_color_line(t_map_infos *map_infos, t_arr *array, int *parsed_flag,
		char *type)
{
	if (*parsed_flag)
	{
		print_error("Error\n");
		print_error("Same color: ");
		print_error(type);
		return (WRONG_MAP);
	}
	else
	{
		if (check_color_line(map_infos, array) != SUCCESS)
			return (WRONG_MAP);
		*parsed_flag = 1;
	}
	return (SUCCESS);
}

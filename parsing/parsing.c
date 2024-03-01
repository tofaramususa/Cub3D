/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:28:07 by arashido          #+#    #+#             */
/*   Updated: 2024/03/01 19:25:34 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	parse_map_to_stack(int fd, t_stack *q)
{
	char	*line;

	init_stack(q);
	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	while (line && !is_empty_line(line))
	{
		enstack(q, ft_strtrim(line, "\n"));
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	ft_free((void **)&line);
}

static int	parse_line(t_map_infos *map_infos, char *map_line)
{
	t_arr	strArr;
	//we need to free split_array
	strArr.strings = ft_split(map_line, ' ');
	strArr.length = arr_length(strArr.strings);
	if (beginswith(strArr.strings, "NO"))
		return (check_texture_path(map_infos, &strArr,
				&map_infos->no_path_parsed, "NO"));
	else if (beginswith(strArr.strings, "SO"))
		return (check_texture_path(map_infos, &strArr,
				&map_infos->so_path_parsed, "SO"));
	else if (beginswith(strArr.strings, "WE"))
		return (check_texture_path(map_infos, &strArr,
				&map_infos->we_path_parsed, "WE"));
	else if (beginswith(strArr.strings, "EA"))
		return (check_texture_path(map_infos, &strArr,
				&map_infos->ea_path_parsed, "EA"));
	else if (beginswith(strArr.strings, "F"))
		return (handle_color_line(map_infos, &strArr,
				&map_infos->floor_color_parsed, "floor"));
	else if (beginswith(strArr.strings, "C"))
		return (handle_color_line(map_infos, &strArr,
				&map_infos->ceiling_color_parsed, "ceiling"));
	return (SUCCESS);
}

int	all_elements_parsed(t_map_infos *map_infos)
{
	if (map_infos->no_path_parsed == 1 && map_infos->so_path_parsed == 1
		&& map_infos->we_path_parsed == 1 && map_infos->ea_path_parsed == 1
		&& map_infos->floor_color_parsed == 1
		&& map_infos->ceiling_color_parsed == 1)
		return (1);
	return (0);
}

int	parse_map(char *file_name, t_map_infos *map_infos)
{
	int		fd;
	char	*line;
	char	*map_line;

	fd = open_map_file(file_name);
	if (fd == -1)
		return (print_error_ms( "Error: Could not open file\n")); //change print_errors names
	line = get_next_line(fd); //need to add my own get next line
	while (line)
	{
		map_line = ft_strtrim(line, " \t\v\f\r\n");
		ft_free((void **)&line); //this frees the get next_line and gets next line
		if (*map_line && parse_line(map_infos, map_line) != SUCCESS)
			return (ft_free((void **)&map_line), close(fd), WRONG_MAP);
		ft_free((void **)&map_line);
		if (all_elements_parsed(map_infos))
			break ;
		line = get_next_line(fd);
	}
	if (!all_elements_parsed(map_infos))
		return (close(fd), print_missing_elements_error(map_infos));
	parse_map_to_stack(fd, &map_infos->stack);
	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	if (line && !is_empty_line(line))
	{
		printf("Invalid map, found line after map");
		free(line);
		return (close(fd), WRONG_MAP);
	}
	return (close(fd), SUCCESS);
}

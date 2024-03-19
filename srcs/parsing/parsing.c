/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:28:07 by arashido          #+#    #+#             */
/*   Updated: 2024/03/05 16:31:37 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdbool.h>
#include <unistd.h>

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
		add_node(q, ft_strtrim(line, "\n"));
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	ft_free((void **)&line);
}

static int	parse_line(t_map_infos *map_infos, char *map_line)
{
	t_arr	str_arr;

	str_arr.strings = ft_split(map_line, ' ');
	str_arr.length = arr_length(str_arr.strings);
	if (beginswith(str_arr.strings, "NO"))
		return (check_texture_path(map_infos, &str_arr,
				&map_infos->no_path_parsed, "NO"));
	else if (beginswith(str_arr.strings, "SO"))
		return (check_texture_path(map_infos, &str_arr,
				&map_infos->so_path_parsed, "SO"));
	else if (beginswith(str_arr.strings, "WE"))
		return (check_texture_path(map_infos, &str_arr,
				&map_infos->we_path_parsed, "WE"));
	else if (beginswith(str_arr.strings, "EA"))
		return (check_texture_path(map_infos, &str_arr,
				&map_infos->ea_path_parsed, "EA"));
	else if (beginswith(str_arr.strings, "F"))
		return (handle_color_line(map_infos, &str_arr,
				&map_infos->floor_color_parsed, "floor\n"));
	else if (beginswith(str_arr.strings, "C"))
		return (handle_color_line(map_infos, &str_arr,
				&map_infos->ceiling_color_parsed, "ceiling\n"));
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

bool	map_infos_norminette(int fd, t_map_infos *map_infos)
{
	char	*line;
	char	*map_line;

	line = get_next_line(fd);
	while (line)
	{
		map_line = ft_strtrim(line, " \t\v\f\r\n");
		ft_free((void **)&line);
		if (*map_line && parse_line(map_infos, map_line) != SUCCESS)
		{
			ft_free((void **)&map_line);
			close(fd);
			return (false);
		}
		ft_free((void **)&map_line);
		if (all_elements_parsed(map_infos))
			break ;
		line = get_next_line(fd);
	}
	return (true);
}

int	parse_map(char *file_name, t_map_infos *map_infos)
{
	int		fd;
	char	*line;

	fd = open_map_file(file_name);
	if (fd == -1)
		return (print_error_ms("Error\nCould not open file\n"), OPEN_ERR);
	if (map_infos_norminette(fd, map_infos) == false)
		return (WRONG_MAP);
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
		printf("Error\nInvalid map, found line after map\n");
		free(line);
		return (close(fd), WRONG_MAP);
	}
	return (close(fd), SUCCESS);
}

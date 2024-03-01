/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:28:02 by arashido          #+#    #+#             */
/*   Updated: 2024/03/01 19:25:34 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	beginswith(char **array, char *str)
{
	if (ft_strcmp(array[0], str) == 0)
		return (1);
	return (0);
}

int	arr_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
			&& line[i] != '\f' && line[i] != '\r' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	open_map_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_error(const char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
}

int	print_error_ms(const char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	return (1);
}
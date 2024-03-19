/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:19:08 by arashido          #+#    #+#             */
/*   Updated: 2024/03/05 15:49:56 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_error(const char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
}

int	print_error_ms(const char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	return (1);
}

int	norminette(int *fd, char **line, char *file_name)
{
	*fd = open_map_file(file_name);
	if (*fd == -1)
		return (*fd);
	*line = get_next_line(*fd);
	return (*fd);
}

int	norminette_2(char **line, int *fd)
{
	*line = get_next_line(*fd);
	while (line && is_empty_line(*line))
	{
		ft_free((void **)&line);
		*line = get_next_line(*fd);
	}
	if (*line && !is_empty_line(*line))
	{
		printf("Error\nInvalid map, found line after map\n");
		close(*fd);
		return (-1);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:28:22 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/02 21:28:16 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*read_text(int fd, char *buffer)
{
	char	*buf2;
	int		nbr_read;

	nbr_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	buf2 = ft_calloc(((size_t) BUFFER_SIZE + 1), sizeof(char));
	if (!buf2)
		return (NULL);
	while (!ft_strchr(buf2, '\n') && nbr_read != 0)
	{
		nbr_read = read(fd, buf2, BUFFER_SIZE);
		if (nbr_read == 0)
			break ;
		if (nbr_read <= -1)
		{
			free(buf2);
			return (NULL);
		}
		buf2[nbr_read] = '\0';
		buffer = ft_strjoin(buffer, buf2);
	}
	free(buf2);
	return (buffer);
}

char	*get_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = str[i];
	i++;
	line[i] = '\0';
	return (line);
}

char	*ft_update(char *str)
{
	size_t	i;
	size_t	j;
	char	*left_str;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	left_str = ft_calloc(((ft_strlen(str) - i) + 1), sizeof(char));
	if (!left_str)
		return (NULL);
	i++;
	while (str[i])
			left_str[j++] = str[i++];
	left_str[j] = '\0';
	free(str);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE > INT_MAX
		|| BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_text(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = ft_update(buffer);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:27:32 by arashido          #+#    #+#             */
/*   Updated: 2024/03/05 16:33:03 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		ft_free((void **)&(array[i]));
		i++;
	}
	ft_free((void **)&array);
}

void	free_2d_array(char ***map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while ((*map)[i])
	{
		ft_free((void **)&((*map)[i]));
		i++;
	}
	ft_free((void **)map);
}

void	free_map_infos(t_map_infos *map_infos)
{
	ft_free((void **)&(map_infos->no_path));
	ft_free((void **)&(map_infos->so_path));
	ft_free((void **)&(map_infos->we_path));
	ft_free((void **)&(map_infos->ea_path));
	free_stack(&map_infos->stack);
}

void	free_stack(t_stack *s)
{
	t_stack_node	*tmp;

	if (!s)
		return ;
	while (s->front)
	{
		tmp = s->front;
		s->front = s->front->next;
		ft_free((void **)&(tmp->val));
		ft_free((void **)&tmp);
	}
}

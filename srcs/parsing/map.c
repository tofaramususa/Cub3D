/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:27:51 by arashido          #+#    #+#             */
/*   Updated: 2024/03/01 18:42:20 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	count_rows_in_stack(t_stack *stack)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	tmp = stack->front;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	find_max_columns_in_stack(t_stack *stack)
{
	int				max;
	int				len;
	t_stack_node	*tmp;

	max = INT_MIN;
	tmp = stack->front;
	while (tmp)
	{
		len = ft_strlen(tmp->val);
		if (len > max)
			max = len;
		tmp = tmp->next;
	}
	return (max);
}

void	add_row_to_2d_array(char **map, t_stack *stack, int *index, int columns)
{
	int		i;
	char	*old_row;
	char	*new_row;
	int		old_row_len;

	i = 0;
	old_row = destack(stack);
	old_row_len = ft_strlen(old_row);
	new_row = (char *)malloc(sizeof(char) * (columns + 1));
	while (i < old_row_len)
	{
		new_row[i] = old_row[i];
		i++;
	}
	while (i < columns)
		new_row[i++] = ' ';
	new_row[i] = '\0';
	map[*index] = new_row;
	(*index)++;
	ft_free((void **)&old_row);
}

void	convert_stack_to_2d_array(t_map *map, t_stack *stack)
{
	int	index;

	index = 0;
	map->rows = count_rows_in_stack(stack);
	map->cols = find_max_columns_in_stack(stack);
	map->map_data = (char **)malloc(sizeof(char *) * (map->rows + 1));
	while (stack->front)
		add_row_to_2d_array(map->map_data, stack, &index, map->cols);
	map->map_data[index] = NULL;
}

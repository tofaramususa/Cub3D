/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:28:11 by arashido          #+#    #+#             */
/*   Updated: 2024/03/05 16:32:29 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_stack(t_stack *s)
{
	s->front = NULL;
	s->back = NULL;
}

void	add_node(t_stack *s, void *val)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->val = val;
	new_node->next = NULL;
	if (!s->front)
	{
		s->front = new_node;
		s->back = new_node;
	}
	else
	{
		s->back->next = new_node;
		s->back = new_node;
	}
}

void	*remove_node(t_stack *s)
{
	t_stack_node	*tmp;
	void			*val;

	if (!s->front)
		return (NULL);
	tmp = s->front;
	val = tmp->val;
	s->front = s->front->next;
	free(tmp);
	return (val);
}

char	*stack_to_str(t_stack *s)
{
	int				len;
	char			*str;
	char			*line;
	t_stack_node	*tmp;

	len = 0;
	tmp = s->front;
	while (tmp)
	{
		len += ft_strlen(tmp->val);
		tmp = tmp->next;
	}
	str = (char *)ft_calloc(len + 1, sizeof(char));
	while (s->front)
	{
		line = remove_node(s);
		ft_strlcat(str, line, len + 1);
		free(line);
	}
	return (str);
}

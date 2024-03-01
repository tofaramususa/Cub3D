/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:28:11 by arashido          #+#    #+#             */
/*   Updated: 2024/03/01 18:43:16 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_stack(t_stack *s)
{
	s->front = NULL;
	s->rear = NULL;
}

void	enstack(t_stack *s, void *val)
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
		s->rear = new_node;
	}
	else
	{
		s->rear->next = new_node;
		s->rear = new_node;
	}
}

void	*destack(t_stack *s)
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
		line = destack(s);
		ft_strlcat(str, line, len + 1);
		free(line);
	}
	return (str);
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

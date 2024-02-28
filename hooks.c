/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:44:08 by tmususa           #+#    #+#             */
/*   Updated: 2024/02/28 17:01:01 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	on_keyrelease(int key, void *info)
{
	t_data	*data;

	data = (t_data *)info;
	if (key == W)
		data->keys.w = false;
	else if (key == A)
		data->keys.a = false;
	else if (key == D)
		data->keys.d = false;
	else if (key == S)
		data->keys.s = false;
	else if (key == RIGHT)
		data->keys.right = false;
	else if (key == LEFT)
		data->keys.left = false;
	else if (key == UP)
		data->keys.up = false;
	else if (key == DOWN)
		data->keys.down = false;
	return (0);
}

int	exit_game(void *info)
{
	// t_data *data;
	(void)info;
	// free everything;
	return (0);
}

int	hook_loop(void *info)
{
	t_data	*data;

	data = (t_data *)info;
	if (data->keys.w)
		go_forward(data);
	else if (data->keys.s)
		go_backward(data);
	else if (data->keys.a)
		move_left(data);
	else if (data->keys.d)
		move_right(data);
	else if (data->keys.left)
		rotate_left(data);
	else if (data->keys.right)
		rotate_right(data);
	else if (data->keys.up)
		go_forward(data);
	else if (data->keys.down)
		go_backward(data);
	cast_rays(data, &data->player);
	return (0);
}

int	on_keypress(int key, void *info)
{
	t_data	*data;

	data = (t_data *)info;
	if (key == ESC)
		exit_game(data);
	else if (key == W)
		data->keys.w = true;
	else if (key == A)
		data->keys.a = true;
	else if (key == D)
		data->keys.d = true;
	else if (key == S)
		data->keys.s = true;
	else if (key == RIGHT)
		data->keys.right = true;
	else if (key == LEFT)
		data->keys.left = true;
	else if (key == UP)
		data->keys.up = true;
	else if (key == DOWN)
		data->keys.down = true;
	return (0);
}

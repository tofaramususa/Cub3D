/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:27:37 by arashido          #+#    #+#             */
/*   Updated: 2024/03/01 20:27:08 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	verify_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error("Error\nWrong number of arguments\n");
		return (INVALID_ARG);
	}
	if (ft_strlen(argv[1]) < 5 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4,
			".cub", 4) != 0)
	{
		print_error("Error\nWrong file extension\n");
		return (INVALID_ARG);
	}
	return (SUCCESS);
}

int	parse_arguments(int argc, char **argv, t_map_infos *map_infos, t_map *map)
{
	int	ret;

	if (verify_arguments(argc, argv) != SUCCESS)
		return (INVALID_ARG);
	ret = parse_map(argv[1], map_infos);
	if (ret == SUCCESS)
	{
		convert_stack_to_2d_array(map, &map_infos->stack);
		if (!is_valid_map(map))
			return (WRONG_MAP);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (parse_arguments(argc, argv, &data.map_infos, &data.map) != SUCCESS)
	{
		free_2d_array(&data->map.map_data);
		free_map_infos(&data->map_infos);
		return (1);
	}
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"cub3D");
	data.image.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.image.address = mlx_get_data_addr(data.image.img,
			&data.image.bits_pixel, &data.image.line_length,
			&data.image.endian);
	run_game(&data);
	exit_game(&data);
}

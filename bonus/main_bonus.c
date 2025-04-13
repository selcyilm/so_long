/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 21:13:03 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/04/13 23:04:14 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error_msg(1);
	check_if_file_valid(av[1], &map);
	map_init(&map);
	apply_flood_fill(&map);
	map.mlx = mlx_init(map.y * PIXEL, map.x * PIXEL + 40, "SO_LONG", true);
	if (!map.mlx)
		return (free_matrix(map.ber), error_msg(6), 1);
	map_build(&map);
	ft_printf("\tWe're not here to take part, we're here to take over.\n");
	map.message = mlx_put_string(map.mlx, "0", 80, map.x * PIXEL);
	mlx_key_hook(map.mlx, &move_key_hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_matrix(map.ber);
	map.ber = NULL;
}

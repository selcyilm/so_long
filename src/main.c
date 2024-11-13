#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error_msg(1);
	check_if_file_valid(av[1], &map);
	map_init(&map);
	apply_flood_fill(&map);
	ft_printf("x: %d, y: %d\n", map.x, map.y);
	map.mlx = mlx_init(map.y * 64, map.x * 64, "SO_LONG", true);
	if (!map.mlx)
		return (free_matrix(map.ber), error_msg(6), 1);
	map_build(&map);
	map.move_cnt = 0;
	mlx_key_hook(map.mlx, &move_key_hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_matrix(map.ber);
	map.ber = NULL;
}

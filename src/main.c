#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error_msg(1);
	check_if_file_valid(av[1], &map);
	map_init(&map);
	apply_flood_fill(&map);
	map.mlx = mlx_init(map.x * 96, map.y * 96, "SO_LONG", true);
	if (!map.mlx)
	{
		ft_printf("error init mlx!\n");
		error_msg(1);
	}
	map_build(&map);

	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_matrix(map.ber);
	map.ber = NULL;
}

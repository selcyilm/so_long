#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error_msg(1);
	check_if_file_valid(av[1], &map);
	map_init(&map);
	apply_flood_fill(&map);
	free_matrix(map.ber);
	map.ber = NULL;
}

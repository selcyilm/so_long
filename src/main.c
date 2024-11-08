#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error_msg(1);
	check_if_file_valid(av[1], &map);
	int i = 0;
	while (map.ber[i])
		ft_printf("%s", map.ber[i++]);
	map_init(&map);
	free_matrix(map.ber);
	map.ber = NULL;
}

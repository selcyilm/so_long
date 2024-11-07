#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	if (ac != 2)
		error_msg(1);
	if (check_map_name(av[1]) == false)
		error_msg(2);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error_msg(3);
	map.ber = ber_read(av[1], line_count(av[1]));
	int i = 0;
	while (map.ber[i])
		ft_printf("%s", map.ber[i++]);
	free_matrix(map.ber);
	map.ber = NULL;
}

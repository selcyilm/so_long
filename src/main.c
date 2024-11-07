#include "../include/so_long.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		error_msg(1);
	check_map_name(av[1]);
	ft_printf("File name: |%s|\n", av[1]);
}

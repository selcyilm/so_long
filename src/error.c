#include "../include/so_long.h"

void	error_msg(int num)
{
	if (num == 1)
		ft_printf("Error\nMissing arguments!\n");
	else if (num == 2)
		ft_printf("Error\nInvalid File name!\n");
	else if (num == 3)
		ft_printf("Error\nOpening file!\n");
	else if (num == 4)
		ft_printf("Error\nMalloc failed!\n");
	else if (num == 5)
		ft_printf("Error\nInvalid Map!\n");
	exit(1);
}

void	mlx_error(t_map *map)
{
	free_matrix(map->ber);
	mlx_close_window(map->mlx);
	mlx_terminate(map->mlx);
	ft_printf("Error\n%s\n", mlx_strerror(mlx_errno));
	exit(1);
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
			free(str[i++]);
	free(str);
}

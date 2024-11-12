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
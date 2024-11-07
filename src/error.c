#include "../include/so_long.h"

void	error_msg(int num)
{
	if (num == 1)
		ft_printf("Error: Missing arguments!\n");
	else if (num == 2)
		ft_printf("Error: Invalid File name!\n");
	else if (num == 3)
		ft_printf("Error: Opening file!\n");

	exit(1);
}
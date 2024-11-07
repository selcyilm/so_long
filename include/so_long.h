#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>

//ERROR MSG
void	error_msg(int num);
void	free_matrix(char **str);

//MAP CHECKING
void	check_map_name(char *str);
#endif
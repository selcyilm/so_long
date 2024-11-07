#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*space;
	mlx_image_t	*collect;
	char		**ber;
}	t_map;

//ERROR MSG
void	error_msg(int num);
void	free_matrix(char **str);

//MAP CHECKING
void	check_map_name(char *str);

//FILE
int		line_count(char *file_name);
char	**ber_read(char *file_name, int size);

#endif
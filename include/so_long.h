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
	int			s_cnt;
	int			w_cnt;
	int			c_cnt;
	int			e_cnt;
	int			p_cnt;
	int			x;
	int			y;
	int			p_x;
	int			p_y;
}	t_map;

//error.c
void	error_msg(int num);
void	mlx_error(t_map *map);
void	free_matrix(char **str);

//file_utils.c
void	check_if_file_valid(char *map_path, t_map *map);
bool	check_map_name(char *str);
int		line_count(char *file_name);
char	**ber_read(char *file_name, int size);

//map_validation.c
bool	check_invalid_char_map(char **str);
void	set_map_char_count(t_map *map);
bool	check_valid_number_of_chars(t_map *map);
bool	is_rectangle_map(char **str);
bool	check_wall_pos(char **str, int line_count, int last_index);

//valid_path_check.c
void	map_init(t_map *map);
bool	check_valid_path(char **str);
void	init_zero(t_map *map);

//flood_fill.c
void	set_start_pos(t_map *map);
char	**flood_fill(char **ber, int x, int y);
bool	valid_path_check(char **ber);
void	apply_flood_fill(t_map *map);
void	print_matrix(char **str);
#endif
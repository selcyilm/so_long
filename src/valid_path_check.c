#include "../include/so_long.h"

void	map_init(t_map *map)
{
	init_zero(map);
	set_map_char_count(map);
	if (check_invalid_char_map(map->ber) == false)
		return (free_matrix(map->ber), error_msg(5));
	else if (check_valid_number_of_chars(map) == false)
		return (free_matrix(map->ber), error_msg(5));
	else if (is_rectangle_map(map->ber) == false)
		return (free_matrix(map->ber), error_msg(5));
	else if (check_wall_pos(map->ber, map->x, map->y) == false)
		return (free_matrix(map->ber), error_msg(5));
	else if (check_valid_path(map->ber) == false)
		return (free_matrix(map->ber), error_msg(5));
}

bool	check_valid_path(char **str)
{
	(void) str;
	return (true);
}

void	init_zero(t_map *map)
{
	map->c_cnt = 0;
	map->e_cnt = 0;
	map->p_cnt = 0;
	map->s_cnt = 0;
	map->w_cnt = 0;
	map->x = 0;
	map->y = 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   valid_path_check.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 21:44:00 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/14 21:44:02 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	map_init(t_map *map)
{
	set_map_char_count(map);
	if (check_invalid_char_map(map->ber) == false)
		return (free_matrix(map->ber), error_msg(5));
	else if (check_valid_number_of_chars(map) == false)
		return (free_matrix(map->ber), error_msg(5));
	else if (is_rectangle_map(map->ber) == false)
		return (free_matrix(map->ber), error_msg(5));
	else if (check_wall_pos(map->ber, map->x, map->y) == false)
		return (free_matrix(map->ber), error_msg(5));
}

void	init_zero(t_map *map)
{
	map->c_cnt = 0;
	map->e_cnt = 0;
	map->p_cnt = 0;
	map->s_cnt = 0;
	map->w_cnt = 0;
	map->v_cnt = 0;
	map->x = 0;
	map->y = 0;
	map->move_cnt = 0;
	map->e_pos = 0;
	map->collectable_flood = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   message_move_bonus.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/15 13:45:31 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/15 13:45:32 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	msg_moves_screen(t_map *map)
{
	char	*str;

	str = ft_itoa(map->move_cnt);
	if (!str)
		error_msg_mlx(map);
	if (map->message)
		mlx_delete_image(map->mlx, map->message);
	map->message = mlx_put_string(map->mlx,
			str, 80, map->x * PIXEL);
	free(str);
}

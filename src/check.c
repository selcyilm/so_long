/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 21:13:40 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/14 21:13:41 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_pos(t_map *map, int x, int y)
{
	x /= PIXEL;
	y /= PIXEL;
	map->ber[y][x] = '0';
}

bool	check_object(t_map *map, char object, int x, int y)
{
	x += map->player->instances[0].x / PIXEL;
	y += map->player->instances[0].y / PIXEL;
	if (map->ber[y][x] == object)
		return (true);
	return (false);
}

void	check_collectable(t_map *map)
{
	int	i;

	if (map->c_cnt == 0)
	{
		if (check_object(map, 'E', 0, 0))
		{
			map->player->instances[0].enabled = false;
			mlx_close_window(map->mlx);
			ft_printf("\tSurprise, surprise! The King is back!\n");
		}
	}
	else if (check_object(map, 'C', 0, 0))
	{
		i = 0;
		while (map->player->instances[0].x != map->collect->instances[i].x || \
				map->player->instances[0].y != map->collect->instances[i].y)
			i++;
		map->collect->instances[i].enabled = false;
		change_pos(map, map->collect->instances[i].x,
			map->collect->instances[i].y);
		map->c_cnt--;
		if (map->c_cnt == 0)
			change_exit(map);
	}
}

void	change_exit(t_map *map)
{
	int	x;
	int	y;

	x = map->exit->instances->x;
	y = map->exit->instances->y;
	mlx_delete_image(map->mlx, map->exit);
	text_to_img(map, &map->exit, "./textures/exit_open.png");
	if (mlx_image_to_window(map->mlx, map->exit, x, y) < 0)
		error_msg_mlx(map);
	mlx_set_instance_depth(map->exit->instances, LAYER_EXIT);
}

void	change_player(t_map *map, char *path)
{
	int	x;
	int	y;

	x = map->player->instances->x;
	y = map->player->instances->y;
	mlx_delete_image(map->mlx, map->player);
	text_to_img(map, &map->player, path);
	if (mlx_image_to_window(map->mlx, map->player, x, y) < 0)
		error_msg_mlx(map);
	mlx_set_instance_depth(map->player->instances, LAYER_PLAYER);
}

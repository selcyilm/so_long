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
		}
	}
	else if (check_object(map, 'C', 0, 0))
	{
		i = 0;
		while (map->player->instances[0].x != map->collect->instances[i].x ||
				map->player->instances[0].y != map->collect->instances[i].y)
				i++;
		map->collect->instances[i].enabled = false;
		change_pos(map, map->collect->instances[i].x, map->collect->instances[i].y);
		map->c_cnt--;
		if (map->c_cnt == 0)
		{
			//change the img of exit
		}
	}
}
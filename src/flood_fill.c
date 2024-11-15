/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   flood_fill.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 21:21:50 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/14 21:21:51 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_start_pos(t_map *map)
{
	int	i;
	int	j;

	map->p_x = 0;
	map->p_y = 0;
	i = 0;
	while (map->ber[i])
	{
		j = 0;
		while (map->ber[i][j])
		{
			if (map->ber[i][j] == 'P')
			{
				map->p_x = i;
				map->p_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_map *map, char **ber, int x, int y)
{
	if (ber[x][y] == '1' || ber[x][y] == 'F')
		return ;
	if (ber[x][y] == 'C')
		map->collect_flood--;
	if (ber[x][y] == 'E')
		map->e_pos = 1;
	ber[x][y] = '1';
	flood_fill(map, ber, x + 1, y);
	flood_fill(map, ber, x - 1, y);
	flood_fill(map, ber, x, y + 1);
	flood_fill(map, ber, x, y - 1);
}

bool	valid_path_check(t_map *map)
{
	if (map->e_pos != 1 || map->collect_flood != 0)
		return (false);
	return (true);
}

char	**sl_strdup(char **ber, t_map *map)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(map->x + 1, sizeof(char *));
	if (!str)
		return (free_matrix(ber), error_msg(4), NULL);
	while (ber[i])
	{
		str[i] = ft_strdup(ber[i]);
		if (!str[i])
			return (free_matrix(ber), free_matrix(str), error_msg(4), NULL);
		i++;
	}
	return (str);
}

void	apply_flood_fill(t_map *map)
{
	char	**copy;

	copy = sl_strdup(map->ber, map);
	set_start_pos(map);
	map->collect_flood = map->c_cnt;
	flood_fill(map, copy, map->p_x, map->p_y);
	if (!valid_path_check(map))
		return (free_matrix(map->ber), free_matrix(copy), error_msg(5));
	free_matrix(copy);
}

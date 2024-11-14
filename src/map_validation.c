/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   map_validation.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 21:28:29 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/14 21:28:31 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//check for invalid char in the map
bool	check_invalid_char_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0' && str[i][j] != '\n')
		{
			if (str[i][j] == '1' || str[i][j] == '0' || str[i][j] == 'C' ||
				str[i][j] == 'E' || str[i][j] == 'P')
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

//create a function for how many char in this map and use them for every char
void	set_map_char_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->ber[i])
	{
		j = 0;
		while (map->ber[i][j])
		{
			if (map->ber[i][j] == '0')
				map->s_cnt++;
			else if (map->ber[i][j] == '1')
				map->w_cnt++;
			else if (map->ber[i][j] == 'C')
				map->c_cnt++;
			else if (map->ber[i][j] == 'E')
				map->e_cnt++;
			else if (map->ber[i][j] == 'P')
				map->p_cnt++;
			j++;
		}
		i++;
	}
	map->s_cnt += map->c_cnt + map->p_cnt + map->e_cnt;
}

bool	check_valid_number_of_chars(t_map *map)
{
	if (map->w_cnt == 0)
		return (false);
	if (map->c_cnt == 0)
		return (false);
	if (map->e_cnt != 1)
		return (false);
	if (map->p_cnt != 1)
		return (false);
	return (true);
}

//check for rectangle shape
bool	is_rectangle_map(char **str)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
			j++;
		size += j;
		i++;
	}
	if (size % i == 0)
		return (true);
	return (false);
}

//check if surrounded by wals
bool	check_wall_pos(char **str, int line_count, int last_index)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (i == 0 && str[i][j] != '1')
				return (false);
			if (i != 0 && j == 0 && str[i][j] != '1')
				return (false);
			if (i == line_count - 1 && str[i][j] != '1')
				return (false);
			if (j == last_index - 1 && str[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

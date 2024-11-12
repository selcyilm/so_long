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

char	**flood_fill(char **ber, int x, int y)
{
	if (ber[x][y] != '1')
	{
		if (ber[x][y] == '0' || ber[x][y] == 'P' || 
		ber[x][y] == 'E' || ber[x][y] == 'C' || ber[x][y] == 'F')
			ber[x][y] = '1';
		else
			return (ber);
		flood_fill(ber, x + 1, y);
		flood_fill(ber, x - 1, y);
		flood_fill(ber, x, y + 1);
		flood_fill(ber, x, y - 1);
	}
	return (ber);
}

bool	valid_path_check(char **ber)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ber[i])
	{
		j = 0;
		while (ber[i][j] && ber[i][j] != '\n')
		{
			if (ber[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

char **sl_strdup(char **ber, t_map *map)
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

void	print_matrix(char **str)
{
	int	i;

	i = 0;
	ft_printf("\n--------------\n");
	while (str[i])
		ft_printf("%s", str[i++]);
	ft_printf("\n--------------\n");
}

void	apply_flood_fill(t_map *map)
{
	char	**copy;
	
	copy = sl_strdup(map->ber, map);
	//print_matrix(copy);
	set_start_pos(map);
	flood_fill(copy, map->p_x, map->p_y);
	//print_matrix(copy);
	if (!valid_path_check(copy))
		return (free_matrix(map->ber), free_matrix(copy), error_msg(5));
	free_matrix(copy);
}

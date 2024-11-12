#include "../include/so_long.h"

void	check_if_file_valid(char *map_path, t_map *map)
{
	init_zero(map);
	if (check_map_name(map_path) == false)
		error_msg(2);
	map->x = line_count(map_path);
	if (map->x == 0)
		return (error_msg(5));
	map->ber = ber_read(map_path, map->x);
	if (!map->ber)
		map->y = ft_strlen(map->ber[0]) - 1;
}

//check if the file name is valid .ber
bool	check_map_name(char *str)
{
	while (*str != '.')
	{
		str++;
		if (!*str)
			return (false);
	}
	if (ft_strncmp(str, ".ber", ft_strlen(str)) != 0)
		return (false);
	return (true);
}

//create line count function
int	line_count(char *file_name)
{
	int		i;
	char	*line;
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_msg(3);
	i = 0;
	while ((line = get_next_line(fd)) != 0)
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

//read all the things and store to char **ber
char	**ber_read(char *file_name, int size)
{
	int		i;
	char	**ber;
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_msg(3);
	ber = ft_calloc(sizeof(char *), size + 1);
	if (ber == NULL)
		error_msg(4);
	i = 0;
	while ((ber[i] = get_next_line(fd)) != NULL)
		i++;
	if (i != size)
		return (free_matrix(ber), error_msg(4), NULL);
	close(fd);
	return (ber);
}

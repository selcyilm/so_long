#include "../include/so_long.h"

//check if the file name is valid .ber
void	check_map_name(char *str)
{
	while (*str != '.')
	{
		str++;
		if (!*str)
			error_msg(2);
	}
	if (ft_strncmp(str, ".ber", ft_strlen(str)) != 0)
		error_msg(2);
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

//create to free 2d array
void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	*str = 0;
}
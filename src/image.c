#include "../include/so_long.h"

void	text_to_img(t_map *map, mlx_image_t *img, char *path)
{
	mlx_texture_t *texture;

	if (!(texture = mlx_load_png(path)))
		error_msg_mlx(map);
	if (!(img = mlx_texture_to_image(map->mlx, texture)))
		error_msg_mlx(map);
	mlx_delete_texture(texture);
}

int	img_to_window(t_map *map, char c, int x, int y)
{
	int	i;

	i = -1;
	x *= 96;
	y *= 96;
	if (c == '1')
		i = mlx_image_to_window(map->mlx, map->wall, x, y);
	else if (c == '0')
		i = mlx_image_to_window(map->mlx, map->space, x, y);
	else if (c == 'C')
		i = mlx_image_to_window(map->mlx, map->collect, x, y);
	else if (c == 'P')
		i = mlx_image_to_window(map->mlx, map->player, x, y);
	else if (c == 'E')
		i = mlx_image_to_window(map->mlx, map->exit, x, y);
	return (i);
}

void	map_build(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	text_to_img(map, map->wall, "./textures/wall.png");
	text_to_img(map, map->collect, "./textures/collect.png");
	text_to_img(map, map->space, "./textures/space.png");
	text_to_img(map, map->player, "./textures/player.png");
	text_to_img(map, map->exit, "./textures/exit.png");
	while (x < map->x)
	{
		y = 0;
		while (y < map->y)
		{
			if (img_to_window(map, map->ber[x][y], x, y) < 0)
				error_msg_mlx(map);
			y++;
		}
		x++;
	}
	init_images_depth(map);
}

void	init_images_depth(t_map *map)
{
	int	i;

	map->player->instances[0].z = 3;
	map->exit->instances[0].z = 1;
	i = 0;
	while (i < map->s_cnt)
		map->space->instances[i++].z = 0;
	i = 0;
	while (i < map->w_cnt)
		map->wall->instances[i++].z = 1;
	i = 0;
	while (i < map->c_cnt)
		map->collect->instances[i++].z = 2;
}


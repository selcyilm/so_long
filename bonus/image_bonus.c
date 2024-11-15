/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   image.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 21:24:04 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/14 21:24:05 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	text_to_img(t_map *map, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error_msg_mlx(map);
	*img = mlx_texture_to_image(map->mlx, texture);
	if (!*img)
		error_msg_mlx(map);
	mlx_delete_texture(texture);
}

int	img_to_window(t_map *map, char c, int x, int y)
{
	int	i;

	i = -1;
	x *= PIXEL;
	y *= PIXEL;
	if (c == '1')
		i = mlx_image_to_window(map->mlx, map->wall, x, y);
	else if (c == '0' || c == 'C' || c == 'P' || c == 'E' || c == 'F')
	{
		i = mlx_image_to_window(map->mlx, map->space, x, y);
		if (i < 0)
			return (i);
		if (c == 'C')
			i = mlx_image_to_window(map->mlx, map->collect, x, y);
		else if (c == 'P')
			i = mlx_image_to_window(map->mlx, map->player, x, y);
		else if (c == 'E')
			i = mlx_image_to_window(map->mlx, map->exit, x, y);
		else if (c == 'F')
			i = mlx_image_to_window(map->mlx, map->villain, x, y);
	}
	return (i);
}

void	map_build(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	text_to_img(map, &map->wall, "./textures/wall.png");
	text_to_img(map, &map->collect, "./textures/collect.png");
	text_to_img(map, &map->space, "./textures/space.png");
	text_to_img(map, &map->player, "./textures/player.png");
	text_to_img(map, &map->exit, "./textures/exit_close.png");
	text_to_img(map, &map->villain, "./textures/villain.png");
	while (x < map->x)
	{
		y = 0;
		while (y < map->y)
		{
			if (img_to_window(map, map->ber[x][y], y, x) < 0)
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

	mlx_set_instance_depth(map->player->instances, LAYER_PLAYER);
	mlx_set_instance_depth(map->exit->instances, LAYER_EXIT);
	i = 0;
	while (i < map->s_cnt)
		mlx_set_instance_depth(&map->space->instances[i++], LAYER_FLOOR);
	i = 0;
	while (i < map->w_cnt)
		mlx_set_instance_depth(&map->wall->instances[i++], LAYER_WALL);
	i = 0;
	while (i < map->c_cnt)
		mlx_set_instance_depth(&map->collect->instances[i++],
			LAYER_COLLECTABLE);
	i = 0;
	while (i < map->v_cnt)
		mlx_set_instance_depth(&map->villain->instances[i++],
			LAYER_COLLECTABLE);
}

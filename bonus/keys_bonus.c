/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   keys.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/14 21:28:06 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/14 21:28:07 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_up(t_map *map)
{
	if (check_object(map, '1', 0, -1))
	{
		ft_printf("\tWho the f is that wal!\n");
		return ;
	}
	map->player->instances[0].y -= PIXEL;
	map->move_cnt++;
	if (check_object(map, 'F', 0, 0))
	{
		ft_printf("GAME OVER!\n");
		mlx_close_window(map->mlx);
		return ;
	}
	check_collectable(map);
}

void	move_right(t_map *map)
{
	change_player(map, "./textures/player.png");
	if (check_object(map, '1', 1, 0))
	{
		ft_printf("\tWho the f is that wal!\n");
		return ;
	}
	map->player->instances[0].x += PIXEL;
	map->move_cnt++;
	if (check_object(map, 'F', 0, 0))
	{
		ft_printf("GAME OVER!\n");
		mlx_close_window(map->mlx);
		return ;
	}
	check_collectable(map);
}

void	move_left(t_map *map)
{
	change_player(map, "./textures/player_left.png");
	if (check_object(map, '1', -1, 0))
	{
		ft_printf("\tWho the f is that wal!\n");
		return ;
	}
	map->player->instances[0].x -= PIXEL;
	map->move_cnt++;
	if (check_object(map, 'F', 0, 0))
	{
		ft_printf("GAME OVER!\n");
		mlx_close_window(map->mlx);
		return ;
	}
	check_collectable(map);
}

void	move_down(t_map *map)
{
	if (check_object(map, '1', 0, 1))
	{
		ft_printf("\tWho the f is that wal!\n");
		return ;
	}
	map->player->instances[0].y += PIXEL;
	map->move_cnt++;
	if (check_object(map, 'F', 0, 0))
	{
		ft_printf("GAME OVER!\n");
		mlx_close_window(map->mlx);
		return ;
	}
	check_collectable(map);
}

void	move_key_hook(mlx_key_data_t key, void *param)
{
	t_map	*map;

	map = param;
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		if (key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
			move_right(map);
		else if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
			move_left(map);
		else if (key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
			move_up(map);
		else if (key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
			move_down(map);
		else if (key.key == MLX_KEY_ESCAPE)
			mlx_close_window(map->mlx);
		msg_moves_screen(map);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:51:17 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:19:12 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	get_xpm2(t_game *game, int size)
{
	game->wall_right = mlx_xpm_file_to_image(game->mlx, WALL_RIGHT,
			&size, &size);
		game->wall_left_up = mlx_xpm_file_to_image(game->mlx, WALL_LEFT_UP,
			&size, &size);
		game->wall_right_up = mlx_xpm_file_to_image(game->mlx, WALL_RIGHT_UP,
			&size, &size);
		game->wall_left_down = mlx_xpm_file_to_image(game->mlx, WALL_LEFT_DOWN,
			&size, &size);
	game->wall_right_down = mlx_xpm_file_to_image(game->mlx, WALL_RIGHT_DOWN,
			&size, &size);
		game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR,
			&size, &size);
		game->collectable = mlx_xpm_file_to_image(game->mlx, COLLECTABLE,
			&size, &size);
		game->collectable2 = mlx_xpm_file_to_image(game->mlx, COLLECTABLE2,
			&size, &size);
		game->collectable3 = mlx_xpm_file_to_image(game->mlx, COLLECTABLE3,
			&size, &size);
		game->collectable4 = mlx_xpm_file_to_image(game->mlx, COLLECTABLE4,
			&size, &size);
		game->collectable5 = mlx_xpm_file_to_image(game->mlx, COLLECTABLE5,
			&size, &size);
		game->collectable6 = mlx_xpm_file_to_image(game->mlx, COLLECTABLE6,
			&size, &size);
}

void	divide_wall_elm(t_game *game, int x, int y)
{
	if (x == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_left, x * 64, y * 64);
	else if (x == (game->map_x - 1))
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_right, x * 64, y * 64);
	else if (y == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_up, x * 64, y * 64);
	else if (y == (game->map_y - 1))
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_down, x * 64, y * 64);
}

void	duplicate_move_player(t_game *game, int keycode, int key)
{
	if (keycode == D || (key == D && (keycode == W || keycode == S)))
	{
		if (game->map_area[game->player_y][game->player_x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_right, game->player_x * 64, game->player_y * 64);
		else if (game->map_area[game->player_y][game->player_x] == 'M')
			loose(game);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->player, game->player_x * 64, game->player_y * 64);
	}
	else if (keycode == W || keycode == S)
	{
		if (game->map_area[game->player_y][game->player_x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_right, game->player_x * 64, game->player_y * 64);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->player, game->player_x * 64, game->player_y * 64);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:28:15 by leborges          #+#    #+#             */
/*   Updated: 2023/04/14 21:35:56 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == W)
		move_player(game, 'v', -1, keycode);
	else if (keycode == A)
		move_player(game, 'h', -1, keycode);
	else if (keycode == S)
		move_player(game, 'v', 1, keycode);
	else if (keycode == D)
		move_player(game, 'h', 1, keycode);
	else if (keycode == ESC)
		close_window(game);
	return (0);
}

void	move_player(t_game *game, char dir, int pos, int keycode)
{
	char	*temp;

	if (dir == 'v')
	{
		if (game->map_area[game->player_y + pos][game->player_x] == '1')
			return ;
		put_floor(game);
		game->player_y += pos;
	}
	else if (dir == 'h')
	{
		if (game->map_area[game->player_y][game->player_x + pos] == '1')
			return ;
		put_floor(game);
		game->player_x += pos;
	}
	check_collectables(game);
	put_player(game, keycode);
	game->count_steps += 1;
	print_moves(game->count_steps);
	temp = ft_itoa(game->count_steps);
	random_fun(game);
	mlx_string_put(game->mlx, game->win, 100,
		50, 134, temp);
	free(temp);
}

void	put_player(t_game *game, int keycode)
{
	static int	key;

	if (keycode == A || (key == A && (keycode == W || keycode == S)))
	{
		if (game->map_area[game->player_y][game->player_x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_left, game->player_x * 64, game->player_y * 64);
		else if (game->map_area[game->player_y][game->player_x] == 'M')
			loose(game);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->player_left, game->player_x * 64, game->player_y * 64);
	}
	else if (keycode == D || (key == D && (keycode == W || keycode == S)))
		duplicate_move_player(game, keycode, key);
	else if (keycode == W || keycode == S)
		duplicate_move_player(game, keycode, key);
	if (keycode == A || keycode == D)
		key = keycode;
}

void	check_collectables(t_game *game)
{
	if (game->map_area[game->player_y][game->player_x] == 'C')
	{
		remove_from_array(game, game->player_x, game->player_y);
		game->map_area[game->player_y][game->player_x] = '0';
	}
	if (game->collect_num == 0)
	{
		if (game->map_area[game->player_y][game->player_x] == 'E')
			win(game);
	}
}

void	put_floor(t_game *game)
{
	if (game->map_area[game->player_y][game->player_x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, game->player_x * 64, game->player_y * 64);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, game->player_x * 64, game->player_y * 64);
}

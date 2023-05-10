/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:02:29 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:05:27 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	rand_enemy(int nothing)
{
	int	num;

	(void)nothing;
	num = rand() % 30;
	if (num >= 0 && num <= 15)
		return (-1);
	else if (num >= 16 && num <= 20)
		return (0);
	else
		return (1);
}

void	move_enemy(t_game *game)
{
	int	x;
	int	y;

	x = rand_enemy(0);
	y = rand_enemy(0);
	if (x == -1 || x == 1)
		y = 0;
	else if (y == -1 || y == 1)
		x = 0;
	if (game->enemy_count > 0)
		put_enemy(game, x, y);
}

void	put_enemy(t_game *game, int x, int y)
{
	int	i;
	int	num;

	num = game->enemy_count;
	i = rand() % num;
	if (game->map_area[game->enemy_y[i] + y][game->enemy_x[i] + x] == '1'
		|| game->map_area[game->enemy_y[i] + y][game->enemy_x[i] + x] == 'C' ||
	game->map_area[game->enemy_y[i] + y][game->enemy_x[i] + x] == 'E'
		|| game->map_area[game->enemy_y[i] + y][game->enemy_x[i] + x] == 'M')
		return ;
	game->enemy_x[i] += x;
	game->enemy_y[i] += y;
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy, game->enemy_x[i] * 64, game->enemy_y[i] * 64);
	if (game->enemy_x[i] == game->player_x
		&& game->enemy_y[i] == game->player_y)
		loose(game);
	else
	{
		game->map_area[game->enemy_y[i] - y][game->enemy_x[i] - x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			(game->enemy_x[i] - x) * 64, (game->enemy_y[i] - y) * 64);
		game->map_area[game->enemy_y[i]][game->enemy_x[i]] = 'M';
	}
}

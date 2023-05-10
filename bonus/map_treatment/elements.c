/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:55:59 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 21:06:28 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <stdlib.h>

void	malloc_enemy_positions(t_game *game)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	x = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map_area[y][x] == 'M')
				game->enemy_count++;
			x++;
		}
		y++;
	}
	game->enemy_x = malloc(game->enemy_count * sizeof(int));
	game->enemy_y = malloc(game->enemy_count * sizeof(int));
}

void	check_player_collect(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map_area[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map_area[y][x] == 'C')
				game->collect_num += 1;
			x++;
		}
		y++;
	}
	if (game->collect_num == 0)
		error(game);
	else
		collect_positions(game);
}

void	check_enemies(t_game *game)
{
	int	y;
	int	x;
	int	flag;

	flag = 0;
	y = 0;
	x = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map_area[y][x] == 'M')
				flag += 1;
			x++;
		}
		y++;
	}
	if (flag > 0)
		check_enemy_positions(game);
}

void	check_enemy_positions(t_game *game)
{
	int	x;
	int	y;
	int	i;

	malloc_enemy_positions(game);
	x = 0;
	y = 0;
	i = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{	
			if (game->map_area[y][x] == 'M')
			{
				game->enemy_x[i] = x;
				game->enemy_y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	check_all_elements(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map_area[y][x] != '0' && game->map_area[y][x] != '1'
				&& game->map_area[y][x] != 'E'
				&& game->map_area[y][x] != 'C' && game->map_area[y][x] != 'P'
				&& game->map_area[y][x] != 'M')
				error(game);
			x++;
		}
		y++;
	}
	check_doubles(game);
	check_player_collect(game);
	check_enemies(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:55:59 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 13:38:55 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}

void	check_all_elements(t_game *game)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map_area[y][x] != '0' && game->map_area[y][x] != '1'
				&& game->map_area[y][x] != 'E'
				&& game->map_area[y][x] != 'C' && game->map_area[y][x] != 'P')
				error(game);
			else if (game->map_area[y][x] == 'E' || game->map_area[y][x] == 'P')
				flag += 1;
			x++;
		}
		y++;
	}
	if (flag != 2)
		error(game);
	check_player_collect(game);
}

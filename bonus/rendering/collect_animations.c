/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:22:01 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:49:43 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	collect_positions(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	game->collect_x = malloc(sizeof(int) * game->collect_num);
	game->collect_y = malloc(sizeof(int) * game->collect_num);
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{	
			if (game->map_area[y][x] == 'C')
			{
				game->collect_x[i] = x;
				game->collect_y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	collect_animation(t_game *game)
{
	static int	count;
	int			i;

	i = 0;
	count++;
	if (count == 5000)
		collect_animation2(game, count, i);
	else if (count == 15000)
		collect_animation2(game, count, i);
	else if (count == 40000)
		collect_animation3(game, count, i);
	else if (count == 55000)
		collect_animation3(game, count, i);
	else if (count == 80000)
		collect_animation4(game, count, i);
	else if (count == 100000)
	{
		collect_animation4(game, count, i);
		count = 0;
	}
}

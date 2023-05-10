/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:49:12 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 20:49:29 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	check_doubles(t_game *game)
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
			if (game->map_area[y][x] == 'E' || game->map_area[y][x] == 'P')
				flag += 1;
			x++;
		}
		y++;
	}
	if (flag != 2)
		error(game);
}

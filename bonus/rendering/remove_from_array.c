/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:38:53 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:01 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	remove_from_array(t_game *game, int num1, int num2)
{
	int	i;

	i = 0;
	while (i < game->collect_num)
	{
		if (game->collect_x[i] == num1 && game->collect_y[i] == num2)
			break ;
		i++;
	}
	remove_position(game, i);
	game->collect_num -= 1;
}

void	remove_position(t_game *game, int num)
{
	int	i;

	i = num;
	while (i < game->collect_num)
	{
		game->collect_x[i] = game->collect_x[i + 1];
		game->collect_y[i] = game->collect_y[i + 1];
		i++;
	}
}

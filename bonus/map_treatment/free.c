/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:46:35 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 21:09:47 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	free_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		free(game->map_area[y]);
		y++;
	}
	free(game->map_area);
}

void	free_map_path(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		free(game->map_area_path[y]);
		y++;
	}
	free(game->map_area_path);
}

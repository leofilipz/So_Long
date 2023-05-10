/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_collect_animation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:37:32 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:51:19 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	collect_animation2(t_game *game, int count, int i)
{
	if (count == 5000)
	{
		while (game->collect_x[i] != '\0' && game->collect_y[i] != '\0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->collectable,
				game->collect_x[i] * 64, game->collect_y[i] * 64);
			i++;
		}
		i = 0;
	}
	else if (count == 15000)
	{
		while (game->collect_x[i] != '\0' && game->collect_y[i] != '\0')
		{				
			mlx_put_image_to_window(game->mlx, game->win, game->collectable2,
				game->collect_x[i] * 64, game->collect_y[i] * 64);
			i++;
		}
		i = 0;
	}
}

void	collect_animation3(t_game *game, int count, int i)
{
	if (count == 40000)
	{
		while (game->collect_x[i] != '\0' && game->collect_y[i] != '\0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->collectable3,
				game->collect_x[i] * 64, game->collect_y[i] * 64);
			i++;
		}
		i = 0;
	}
	else if (count == 55000)
	{
		while (game->collect_x[i] != '\0' && game->collect_y[i] != '\0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->collectable4,
				game->collect_x[i] * 64, game->collect_y[i] * 64);
			i++;
		}
		i = 0;
	}
}

void	collect_animation4(t_game *game, int count, int i)
{
	if (count == 80000)
	{
		while (game->collect_x[i] != '\0' && game->collect_y[i] != '\0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->collectable5,
				game->collect_x[i] * 64, game->collect_y[i] * 64);
			i++;
		}
		i = 0;
	}
	else if (count == 100000)
	{
		while (game->collect_x[i] != '\0' && game->collect_y[i] != '\0')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->collectable6,
				game->collect_x[i] * 64, game->collect_y[i] * 64);
			i++;
		}
		i = 0;
	}
}

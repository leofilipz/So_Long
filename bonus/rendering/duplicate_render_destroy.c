/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:14:06 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:04:40 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	destroy_xpms2(t_game *game)
{
	mlx_destroy_image(game->mlx, game->enemy);
	mlx_destroy_image(game->mlx, game->enemy_2);
	mlx_destroy_image(game->mlx, game->enemy_3);
	mlx_destroy_image(game->mlx, game->enemy_4);
	mlx_destroy_image(game->mlx, game->collectable2);
	mlx_destroy_image(game->mlx, game->collectable3);
	mlx_destroy_image(game->mlx, game->collectable4);
	mlx_destroy_image(game->mlx, game->collectable5);
	mlx_destroy_image(game->mlx, game->collectable6);
}

void	render_animation2(t_game *game, int count, int i)
{
	if (count == 5000)
	{
		while (i < game->enemy_count)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy, game->enemy_x[i] * 64, game->enemy_y[i] * 64);
			i++;
		}
		move_enemy(game);
	}
	else if (count == 20000)
	{
		while (i < game->enemy_count)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy_2, game->enemy_x[i] * 64, game->enemy_y[i] * 64);
			i++;
		}
		move_enemy(game);
	}
}

void	render_animation3(t_game *game, int count, int i)
{
	if (count == 35000)
	{
		while (i < game->enemy_count)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy_3, game->enemy_x[i] * 64, game->enemy_y[i] * 64);
			i++;
		}
		move_enemy(game);
	}
	else if (count == 50000)
	{
		while (i < game->enemy_count)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy_4, game->enemy_x[i] * 64, game->enemy_y[i] * 64);
			i++;
		}
		move_enemy(game);
	}
}

void	render_animation4(t_game *game, int count, int i)
{
	if (count == 65000)
	{
		while (i < game->enemy_count)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy_3, game->enemy_x[i] * 64, game->enemy_y[i] * 64);
			i++;
		}
		move_enemy(game);
	}
	else if (count == 80000)
	{
		while (i < game->enemy_count)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy_2, game->enemy_x[i] * 64, game->enemy_y[i] * 64);
			i++;
		}
		move_enemy(game);
	}
}

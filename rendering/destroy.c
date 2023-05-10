/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:55:30 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 19:25:46 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_xpms(t_game *game)
{
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->exit_left);
	mlx_destroy_image(game->mlx, game->exit_right);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->player_left);
	mlx_destroy_image(game->mlx, game->collectable);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->wall2);
	mlx_destroy_image(game->mlx, game->wall_up);
	mlx_destroy_image(game->mlx, game->wall_left);
	mlx_destroy_image(game->mlx, game->wall_right);
	mlx_destroy_image(game->mlx, game->wall_down);
	mlx_destroy_image(game->mlx, game->wall_left_down);
	mlx_destroy_image(game->mlx, game->wall_right_down);
	mlx_destroy_image(game->mlx, game->wall_left_up);
	mlx_destroy_image(game->mlx, game->wall_right_up);
	mlx_destroy_image(game->mlx, game->floor);
}

void	destroy(t_game *game)
{
	destroy_xpms(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map_path(game);
	free_map(game);
}

int	close_window(t_game *game)
{
	destroy(game);
	exit (0);
	return (0);
}

void	win(t_game *game)
{
	write(1, "YOU WON", 7);
	destroy(game);
	exit (0);
}

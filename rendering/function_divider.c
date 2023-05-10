/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_divider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:23:32 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 13:34:48 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	divide_for_getxpm(t_game *game)
{
	int	size;

	size = SIZE;
	game->wall_left_down = mlx_xpm_file_to_image(game->mlx,
			WALL_LEFT_DOWN, &size, &size);
	game->wall_right_down = mlx_xpm_file_to_image(game->mlx,
			WALL_RIGHT_DOWN, &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &size, &size);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			COLLECTABLE, &size, &size);
}

void	divide_wall_elm(t_game *game, int x, int y)
{
	if (x == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_left, x * 64, y * 64);
	else if (x == (game->map_x - 1))
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_right, x * 64, y * 64);
	else if (y == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_up, x * 64, y * 64);
	else if (y == (game->map_y - 1))
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_down, x * 64, y * 64);
}

void	divide_put_player(t_game *game)
{
	if (game->map_area[game->player_y][game->player_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_right, game->player_x * 64, game->player_y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, game->player_x * 64, game->player_y * 64);
}

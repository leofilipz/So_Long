/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:39:49 by leborges          #+#    #+#             */
/*   Updated: 2023/04/05 13:43:27 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_pos(t_game *game, int x, int y)
{
	if (game->map_area[y][x] == '1')
		return (0);
	else if (game->map_area[y][x] == '0')
		return (1);
	else if (game->map_area[y][x] == 'C')
		return (2);
	else if (game->map_area[y][x] == 'E')
		return (3);
	else if (game->map_area[y][x] == 'P')
		return (4);
	else
		return (5);
}

void	get_xpm(t_game *game)
{
	int	size;

	size = SIZE;
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
	game->exit_left = mlx_xpm_file_to_image(game->mlx, EXIT_LEFT, &size, &size);
	game->exit_right = mlx_xpm_file_to_image(game->mlx,
			EXIT_RIGHT, &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx,
			PLAYER, &size, &size);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			PLAYER_LEFT, &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->wall2 = mlx_xpm_file_to_image(game->mlx, WALL2, &size, &size);
	game->wall_up = mlx_xpm_file_to_image(game->mlx, WALL_UP, &size, &size);
	game->wall_down = mlx_xpm_file_to_image(game->mlx, WALL_DOWN, &size, &size);
	game->wall_left = mlx_xpm_file_to_image(game->mlx, WALL_LEFT, &size, &size);
	game->wall_right = mlx_xpm_file_to_image(game->mlx,
			WALL_RIGHT, &size, &size);
	game->wall_left_up = mlx_xpm_file_to_image(game->mlx,
			WALL_LEFT_UP, &size, &size);
	game->wall_right_up = mlx_xpm_file_to_image(game->mlx,
			WALL_RIGHT_UP, &size, &size);
	divide_for_getxpm(game);
}

void	put_xpm(t_game *game, int elm, int x, int y)
{
	if (elm == 0)
		check_wall_elm(game, x, y);
	else if (elm == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, x * 64, y * 64);
	else if (elm == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectable, x * 64, y * 64);
	else if (elm == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, x * 64, y * 64);
	else if (elm == 4)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, x * 64, y * 64);
}

void	check_wall_elm(t_game *game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_left_up, x * 64, y * 64);
	else if (x == (game->map_x - 1) && y == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_right_up, x * 64, y * 64);
	else if (x == 0 && y == (game->map_y - 1))
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_left_down, x * 64, y * 64);
	else if (x == (game->map_x - 1) && y == (game->map_y - 1))
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_right_down, x * 64, y * 64);
	else if (x == 0 || x == (game->map_x - 1)
		|| y == 0 || y == (game->map_y - 1))
		divide_wall_elm(game, x, y);
	else
	{
		if (x == ((game->map_x -1) / 2))
			mlx_put_image_to_window(game->mlx, game->win,
				game->wall2, x * 64, y * 64);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->wall, x * 64, y * 64);
	}
}

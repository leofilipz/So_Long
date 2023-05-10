/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:25:48 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 19:18:41 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_path(t_game *game)
{
	int		y;
	int		i;
	char	*str;

	i = 0;
	y = game->map_y;
	open_map(game);
	game->map_area_path = malloc(sizeof(char *) * y);
	if (!game->map_area_path)
		destroy(game);
	while (i < y)
	{
		str = get_next_line(game->map_fd);
		game->map_area_path[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	close_map(game);
}

bool	fill(t_game *game, char begin, int row, int col)
{
	static bool		exit = false;
	static int		cols = 0;

	if (row < 0 || col < 0 || row >= game->map_y || col >= game->map_x)
		return (false);
	else if (game->map_area_path[row][col] == 'X')
		return (false);
	else if (game->map_area_path[row][col] == '1')
		return (false);
	else if (game->map_area_path[row][col] == 'E')
		exit = true;
	if (game->map_area_path[row][col] == 'C')
		cols++;
	game->map_area_path[row][col] = 'X';
	fill(game, begin, row + 1, col);
	fill(game, begin, row, col + 1);
	fill(game, begin, row - 1, col);
	fill(game, begin, row, col - 1);
	return (cols == game->collect_num && exit);
}

int	floodfill(t_game *game)
{
	char	begin;
	int		row;
	int		col;
	bool	valid;

	begin = game->map_area_path[game->player_y][game->player_x];
	row = game->player_y;
	col = game->player_x;
	valid = fill(game, begin, row, col);
	return (valid);
}

void	check_path(t_game *game)
{
	malloc_path(game);
	if (!floodfill(game))
	{
		free_map_path(game);
		error(game);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:49:12 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 21:11:03 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	map_create(t_game *game)
{
	int		y;
	int		i;
	char	*str;

	i = 0;
	y = game->map_y;
	open_map(game);
	game->map_area = malloc(sizeof(char *) * y);
	if (!game->map_area)
		destroy(game);
	while (i < y)
	{
		str = get_next_line(game->map_fd);
		game->map_area[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	get_x(game);
	close_map(game);
}

void	get_x(t_game *game)
{
	char	*x;

	x = game->map_area[0];
	game->map_x = ft_strlenn(x);
}

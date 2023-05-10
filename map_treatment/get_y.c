/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:17:43 by leborges          #+#    #+#             */
/*   Updated: 2023/04/05 13:14:25 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_y(t_game *game)
{
	char	*str;
	int		lines;

	lines = 0;
	open_map(game);
	while (1)
	{
		str = get_next_line(game->map_fd);
		if (!str)
			break ;
		lines++;
		free(str);
	}
	if (lines == 0)
		write(1, "Empty file/n", 11);
	game->map_y = lines;
	close_map(game);
}

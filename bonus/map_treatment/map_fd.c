/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:17:53 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 21:11:45 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	open_map(t_game *game)
{
	game->map_fd = open(game->map, O_RDONLY);
}

void	close_map(t_game *game)
{
	close(game->map_fd);
}

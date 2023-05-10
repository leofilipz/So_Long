/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:21:50 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 17:24:17 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(t_game *game)
{
	write(1, "Error, not a valid map", 22);
	free_map(game);
	exit (EXIT_FAILURE);
}

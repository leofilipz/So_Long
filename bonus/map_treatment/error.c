/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:21:50 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 21:09:37 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	error(t_game *game)
{
	write(1, "Error, not a valid map", 22);
	free_map(game);
	exit (EXIT_FAILURE);
}

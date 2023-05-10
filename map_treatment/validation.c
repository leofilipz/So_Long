/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:43:41 by leborges          #+#    #+#             */
/*   Updated: 2023/04/05 13:13:20 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_rect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		if (ft_strlenn(game->map_area[i]) != game->map_x)
			error(game);
		i++;
	}
}

void	check_surroundings(t_game *game)
{
	int	rows;
	int	columns;
	int	i;
	int	j;

	rows = game->map_y;
	columns = game->map_x;
	i = 0;
	j = 0;
	while (j < columns)
	{
		if (game->map_area[i][j] != '1' || game->map_area[rows - 1][j] != '1')
			error(game);
		j++;
	}
	while (i < rows)
	{
		if (game->map_area[i][0] != '1' ||
			game->map_area[i][columns - 1] != '1')
			error(game);
		i++;
	}
}

void	check_ber(t_game *game)
{
	int	pos;

	pos = ft_strlenn(game->map) - 4;
	if (ft_strncmp(".ber", &game->map[pos], 4) != 0)
	{
		write(1, "Error, not a valid map file", 27);
		exit (EXIT_FAILURE);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*s1 - *s2);
}

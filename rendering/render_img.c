/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:39:55 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 13:07:32 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_img(t_game *game)
{
	int	x;
	int	y;
	int	elm;

	x = 0;
	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			elm = check_pos(game, x, y);
			put_xpm(game, elm, x, y);
			x++;
		}
		y++;
	}
}

void	print_moves(int n)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	free(str);
}

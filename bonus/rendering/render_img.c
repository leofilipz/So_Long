/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:39:55 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:56 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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

int	render_animation(t_game *game)
{
	static int	count;
	int			i;

	i = 0;
	count++;
	if (count == 5000)
		render_animation2(game, count, i);
	else if (count == 20000)
		render_animation2(game, count, i);
	else if (count == 35000)
		render_animation3(game, count, i);
	else if (count == 50000)
		render_animation3(game, count, i);
	else if (count == 65000)
		render_animation4(game, count, i);
	else if (count == 80000)
	{
		render_animation4(game, count, i);
		i = 0;
		count = 0;
	}
	collect_animation(game);
	return (0);
}

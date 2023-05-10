/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:32:51 by leborges          #+#    #+#             */
/*   Updated: 2023/04/10 13:09:49 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_x * 64,
			game->map_y * 64, "So little!");
	game->img = mlx_new_image(game->mlx, (game->map_x * 64),
			(game->map_y * 64));
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	mlx_hook(game->win, 2, 1L << 0, key_handler, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	get_xpm(game);
	render_img(game);
	mlx_string_put(game->mlx, game->win, 60, 50, 0, "MOVES: ");
	mlx_loop_hook(game->mlx, render_animation, game);
	mlx_destroy_image(game->mlx, game->img);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	(void)ac;
	game.map = av[1];
	game.count_steps = 0;
	game.enemy_count = 0;
	check_ber(&game);
	open_map(&game);
	get_y(&game);
	map_create(&game);
	check_surroundings(&game);
	check_rect(&game);
	check_all_elements(&game);
	check_path(&game);
	init_game(&game);
}

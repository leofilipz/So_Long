/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:17:31 by leborges          #+#    #+#             */
/*   Updated: 2023/04/14 21:33:41 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WALL "./imgs/wall.xpm"
# define WALL2 "./imgs/wall2.xpm"
# define WALL_UP "./imgs/wall_up.xpm"
# define WALL_DOWN "./imgs/wall_down.xpm"
# define WALL_LEFT_UP "./imgs/wall_left_up.xpm"
# define WALL_RIGHT_UP "./imgs/wall_right_up.xpm"
# define WALL_LEFT "./imgs/wall_left.xpm"
# define WALL_RIGHT "./imgs/wall_right.xpm"
# define WALL_LEFT_DOWN "./imgs/wall_left_down.xpm"
# define WALL_RIGHT_DOWN "./imgs/wall_right_down.xpm"
# define PLAYER "./imgs/player.xpm"
# define DEAD_PLAYER "./imgs/dead_player.xpm"
# define PLAYER_LEFT "./imgs/player_left.xpm"
# define EXIT "./imgs/exit.xpm"
# define EXIT_LEFT "./imgs/exit_left.xpm"
# define EXIT_RIGHT "./imgs/exit_right.xpm"
# define FLOOR "./imgs/floor.xpm"
# define COLLECTABLE "./imgs/collect.xpm"
# define COLLECTABLE2 "./imgs/collect_2.xpm"
# define COLLECTABLE3 "./imgs/collect_3.xpm"
# define COLLECTABLE4 "./imgs/collect_4.xpm"
# define COLLECTABLE5 "./imgs/collect_5.xpm"
# define COLLECTABLE6 "./imgs/collect_6.xpm"
# define ENEMY "./imgs/enemy.xpm"
# define ENEMY_2 "./imgs/enemy_2.xpm"
# define ENEMY_3 "./imgs/enemy_3.xpm"
# define ENEMY_4 "./imgs/enemy_4.xpm"

# define SIZE 64

# include "../utils/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <time.h>

typedef enum keycodes
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
}				t_keys;

typedef struct s_game
{
	char	**map_area;
	char	**map_area_path;
	char	*map;
	int		map_fd;
	int		map_y;
	int		map_x;
	void	*mlx;
	void	*win;
	void	*exit;
	void	*exit_left;
	void	*exit_right;
	void	*collectable;
	void	*collectable2;
	void	*collectable3;
	void	*collectable4;
	void	*collectable5;
	void	*collectable6;
	int		*collect_x;
	int		*collect_y;
	void	*player;
	void	*dead_player;
	void	*player_left;
	void	*wall;
	void	*wall2;
	void	*wall_up;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*wall_left_up;
	void	*wall_right_up;
	void	*wall_left_down;
	void	*wall_right_down;
	void	*enemy;
	void	*enemy_2;
	void	*enemy_3;
	void	*enemy_4;
	void	*floor;
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*enemy_x;
	int		*enemy_y;
	int		enemy_count;
	int		player_x;
	int		player_y;
	int		collect_num;
	int		count_steps;
}				t_game;

char	*get_next_line(int fd);
int		ft_strlenn(char *str);
void	open_map(t_game *game);
void	close_map(t_game *game);
void	error(t_game *game);
void	check_surroundings(t_game *game);
void	get_y(t_game *game);
int		main(int ac, char **av);
char	*ft_strtrim(char *s1, char *set);
void	get_x(t_game *game);
void	map_create(t_game *game);
void	check_rect(t_game *game);
void	check_ber(t_game *game);
void	free_map(t_game *game);
void	init_game(t_game *game);
void	render_img(t_game *game);
int		check_pos(t_game *game, int x, int y);
void	get_xpm(t_game *game);
void	put_xpm(t_game *game, int elm, int x, int y);
void	check_wall_elm(t_game *game, int x, int y);
void	check_all_elements(t_game *game);
int		key_handler(int keycode, t_game *game);
void	put_player(t_game *game, int keycode);
void	move_player(t_game *game, char dir, int pos, int keycode);
void	put_floor(t_game *game);
void	destroy_xpms(t_game *game);
void	destroy(t_game *game);
int		close_window(t_game *game);
void	win(t_game *game);
void	free_map(t_game *game);
void	check_collectables(t_game *game);
void	malloc_enemy_positions(t_game *game);
void	check_enemy_positions(t_game *game);
void	check_player_collect(t_game *game);
int		render_animation(t_game *game);
void	collect_positions(t_game *game);
void	collect_animation(t_game *game);
void	remove_from_array(t_game *game, int num1, int num2);
void	remove_position(t_game *game, int num);
void	move_enemy(t_game *game);
int		rand_enemy(int nothing);
void	put_enemy(t_game *game, int x, int y);
void	render_moves_enemy(t_game *game);
void	loose(t_game *game);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	print_moves(int n);
void	check_enemies(t_game *game);
void	malloc_path(t_game *game);
bool	fill(t_game *game, char begin, int row, int col);
int		floodfill(t_game *game);
void	check_path(t_game *game);
void	free_map_path(t_game *game);
void	check_doubles(t_game *game);
void	destroy_xpms2(t_game *game);
void	put_enemy2(t_game *game, int x, int y);
void	render_animation2(t_game *game, int count, int i);
void	render_animation3(t_game *game, int count, int i);
void	render_animation4(t_game *game, int count, int i);
void	get_xpm2(t_game *game, int size);
void	divide_wall_elm(t_game *game, int x, int y);
void	duplicate_move_player(t_game *game, int keycode, int key);
void	collect_animation2(t_game *game, int count, int i);
void	collect_animation3(t_game *game, int count, int i);
void	collect_animation4(t_game *game, int count, int i);
void	random_fun(t_game *game);

#endif

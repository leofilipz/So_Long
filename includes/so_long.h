/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:17:31 by leborges          #+#    #+#             */
/*   Updated: 2023/04/06 19:19:20 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define PLAYER_LEFT "./imgs/player_left.xpm"
# define EXIT "./imgs/exit.xpm"
# define EXIT_LEFT "./imgs/exit_left.xpm"
# define EXIT_RIGHT "./imgs/exit_right.xpm"
# define FLOOR "./imgs/floor.xpm"
# define COLLECTABLE "./imgs/collect.xpm"

# define SIZE 64

# include "../utils/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>

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
	char	**map_area_path;
	char	**map_area;
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
	void	*player;
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
	void	*floor;
	int		height;
	int		width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		player_x;
	int		player_y;
	int		collect_num;
	int		count_steps;
}				t_game;

char	*get_next_line(int fd);
int		ft_strlenn(char *str);
void	error(t_game *game);
void	open_map(t_game *game);
void	close_map(t_game *game);
void	check_rect(t_game *game);
void	check_surroundings(t_game *game);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_ber(t_game *game);
void	get_y(t_game *game);
int		main(int ac, char **av);
char	*ft_strtrim(char *s1, char *set);
void	get_x(t_game *game);
void	map_create(t_game *game);
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
void	check_player_collect(t_game *game);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	print_moves(int n);
void	divide_for_getxpm(t_game *game);
void	divide_wall_elm(t_game *game, int x, int y);
void	divide_put_player(t_game *game);
void	malloc_path(t_game *game);
bool	fill(t_game *game, char begin, int row, int col);
int		floodfill(t_game *game);
void	check_path(t_game *game);
void	free_map_path(t_game *game);
#endif

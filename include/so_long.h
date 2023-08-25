/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:51 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/24 16:25:58 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* header*/
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/src/get_next_line.h"

/* mlx library */
# include "MLX42.h"

/* library */
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

/* define */
# define MAP_WIDTH	7100
# define MAP_HEIGHT	7100
# define IMG_WIDTH	71
# define IMG_HEIGHT	71
# define NUM_FRAMES	4

/* char */
# define CHAR_MAP			"01PECMS"
# define CHAR_FILL			"CEPMS"
# define IS_FILLED			"1X"
# define CHAR_WALL			49
# define CHAR_EXIT			69
# define CHAR_PLAYER		80
# define CHAR_COLLLECT		67
# define CHAR_FLOOR			48
# define CHAR_ENEMY			77
# define CHAR_STRONG		83

/* player path */
# define PNG_PLAYER			"./assets/charactor/player.png"
# define PNG_PLAYER_FLIPPED	"./assets/charactor/player_flipped.png"

/* enemy path */
# define PNG_ENEMY			"./assets/charactor/enemy.png"
# define PNG_ENEMY_FLIPPED	"./assets/charactor/enemy_flipped.png"
# define PNG_STRONG			"./assets/charactor/enemy_strong.png"
# define PNG_STRONG_FLIPPED	"./assets/charactor/enemy_strong_flipped.png"

/* collect path */
# define PNG_COLLECT		"./assets/collect/treasure.png"

# define PNG_EXIT_OPEN		"./assets/exit/steps.png"
# define PNG_EXIT_CLOSE		"./assets/exit/exit_close.png"

/* wall path */
# define PNG_WALL			"./assets/walls/walls_1.png"

/* floor path */
# define PNG_FLOOR0			"./assets/floor/floor01_1.png"
# define PNG_FLOOR1			"./assets/floor/floor02_1.png"

/* animation speed */
# define ANIMATION_SPEED	42

/* miniaudio */
# define MINIAUDIO_IMPLEMENTATION

/* audio path */
# define WAV_MUSIC			"./assets/music/Fight.wav"
// # define PNG_FLOOR1			"./assets/floor/floor02_1.png"

/* struct */
typedef struct s_multi{
	mlx_image_t	*image;
	int			x;
	int			y;
}				t_multi;

typedef struct s_img{
	mlx_image_t	*floor[2];
	mlx_image_t	*wall;
	t_multi		exits[2];
	t_multi		player;
	t_multi		enemy[100];
	t_multi		strong[3];
	t_multi		collect[1000];
}				t_img;

typedef struct s_map{
	char	**repo;
	char	**fill;
	int		columns;
	int		rows;
	int		collects;
	int		enemies;
	int		strongs;
	int		player;
	int		exits;
	int		walls;
	int		floor;
}				t_map;

typedef struct s_position{
	int					x;
	int					y;
	unsigned int		move;
}				t_position;

/* game */
typedef struct s_game{	
	mlx_t		*mlx;
	int			fd;
	t_img		img;
	t_map		map;
	t_position	position;
	int			count;
	int			level;
	int			finish_game;
}				t_game;

/* error */
void	ft_error_general(char *msg);
void	ft_error_and_free_map(char *msg, t_game *game);
void	ft_free_map_repo(char **target);
void	ft_free_map_fill(char **map, int cols);

/* utility */
int		ft_readline(char *str);
void	ft_mlx_image_to_window(t_game *game, mlx_image_t *mlx_image, \
	int x, int y);
void	place_png_to_img(t_game *game, mlx_image_t **img, char *path);
void	place_texture(t_game *game);
int		ft_get_len(long nb);

/* init layer map */
void	init_layer(t_game *game);
void	check_surround_wall(int x, int y, t_game *game);
void	check_argument(int ac, char **av, t_game *game);
void	check_possibility_clear_game(t_game *game);
void	collect_map_struct(char c, t_game *game, int x, int y);

/* init game */
void	init_value(t_game *game);
void	set_player_position(t_multi *info, t_position *position);
void	init_mlx(t_game *game);

/* init map */
void	map_2d_malloc(t_game *game);
void	check_map_len(t_game *game, char *line, int index);
void	init_map(char **av, t_game *game);

/* init image */
void	init_floor(t_game *game);
void	init_player(t_game *game, int x, int y);
void	init_enemy(t_game *game, int x, int y);
void	init_strong(t_game *game, int x, int y);
void	init_collect(t_game *game, int x, int y, int *count);
void	init_exit(t_game *game, int x, int y);

/* place image and counter to the window */
void	place_floor_with_texture(t_game *game);
void	place_layer_with_texture(t_game *game);
void	place_counter_and_level(t_game *game);

/* event */
void	key_hook(mlx_key_data_t keydata, void *param);
void	player_moves(mlx_key_data_t keydata, int y, int x, t_game *game);
void	collect_item(t_game *game, int x, int y);
void	if_finish(t_game *game, int x, int y);

/* enemies event */
void	if_touch_enemy(t_game *game, int x, int y);
void	write_counter(t_game *game);
void	write_level(t_game *game);
void	enemy_watch_player(t_game *game, int x, int y);
void	enemy_moves(t_game *game, int x, int y);
void	enemy_moves_sub(t_game *game, int strong_x, int strong_y, int i);
void	animate(void *param);
int		animate_enemies(t_game *game, int i, int flag, char *image);

/* delete image */
void	delete_item(t_game *game, int x, int y);
void	delete_collectible(t_game *game);
void	delete_player(t_game *game);
void	delete_floor(t_game *game);
void	delete_all_image(t_game *game);
void	delete_enemies(t_game *game);

/* flood fill */
void	copy_map_to_fill(t_game *game);
void	flood_loop(t_game *game, char **map_fill, char replacement);
void	flood_fill(t_game *game, int x, int y, char replacement);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:13:42 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/24 16:46:34 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/miniaudio/miniaudio.h"

void	clean_up(t_game *game, ma_engine *engine)
{
	delete_all_image(game);
	ft_free_map_repo(game->map.repo);
	mlx_terminate(game->mlx);
	ma_engine_uninit(engine);
}

int	main(int ac, char **av)
{
	t_game		game;
	ma_result	result;
	ma_engine	engine;

	check_argument(ac, av, &game);
	game.fd = open(av[1], O_RDONLY);
	if (game.fd < 0 || game.fd == 0 || result != MA_SUCCESS)
		ft_error_general("Failed to open file\n");
	init_value(&game);
	init_map(av, &game);
	init_layer(&game);
	init_mlx(&game);
	place_texture(&game);
	result = ma_engine_init(NULL, &engine);
	ma_engine_play_sound(&engine, WAV_MUSIC, NULL);
	mlx_loop_hook(game.mlx, &animate, &game.mlx);
	mlx_key_hook(game.mlx, &key_hook, &game.mlx);
	mlx_loop(game.mlx);
	clean_up(&game, &engine);
}

void	animate(void *param)
{
	t_game		*game;
	static int	count;
	static int	i;
	static int	flag;

	game = param;
	++count;
	if (game->map.strongs == 0)
		return ;
	if (count > ANIMATION_SPEED)
	{
		if (flag == 0)
			flag = animate_enemies(game, i, flag, PNG_STRONG_FLIPPED);
		else if (flag == 1)
			flag = animate_enemies(game, i, flag, PNG_STRONG);
		i++;
		if (i == game->map.strongs)
			i = 0;
		count = 1;
	}
}

int	animate_enemies(t_game *game, int i, int flag, char *path)
{
	int	strong_x;
	int	strong_y;

	strong_x = game->img.strong[i].x;
	strong_y = game->img.strong[i].y;
	mlx_delete_image(game->mlx, game->img.strong[i].image);
	place_png_to_img(game, &game->img.strong[i].image, path);
	mlx_image_to_window(game->mlx, game->img.strong[i].image, \
		strong_x * IMG_WIDTH, strong_y * IMG_HEIGHT);
	i++;
	if (i == game->map.strongs && flag == 0)
		return (1);
	if ((i == game->map.strongs && flag == 1) || flag == 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:00:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 20:56:16 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game, int x, int y)
{
	place_png_to_img(game, &game->img.player.image, PNG_PLAYER);
	set_player_position(&game->img.player, &game->position);
	game->map.repo[y][x] = '0';
	mlx_image_to_window(game->mlx, game->img.player.image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	init_enemy(t_game *game, int x, int y)
{
	int	i;

	i = game->map.enemies;
	place_png_to_img(game, &game->img.enemy[i].image, PNG_ENEMY);
	game->img.enemy[i].y = y;
	game->img.enemy[i].x = x;
	mlx_image_to_window(game->mlx, game->img.enemy[i].image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
	game->map.enemies++;
}

void	init_strong(t_game *game, int x, int y)
{
	int	i;

	i = game->map.strongs;
	place_png_to_img(game, &game->img.strong[i].image, PNG_STRONG);
	game->img.strong[i].y = y;
	game->img.strong[i].x = x;
	mlx_image_to_window(game->mlx, game->img.strong[i].image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
	game->map.strongs++;
}

void	init_collect(t_game *game, int x, int y, int *count)
{
	place_png_to_img(game, &game->img.collect[*count].image, PNG_COLLECT);
	game->img.collect[*count].x = x;
	game->img.collect[*count].y = y;
	mlx_image_to_window(game->mlx, game->img.collect[*count].image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
	(*count)++;
}

void	init_exit(t_game *game, int x, int y)
{
	place_png_to_img(game, &game->img.exits[0].image, PNG_EXIT_CLOSE);
	game->img.exits[0].x = x;
	game->img.exits[0].y = y;
	place_png_to_img(game, &game->img.exits[1].image, PNG_EXIT_OPEN);
	game->img.exits[1].x = x;
	game->img.exits[1].y = y;
	mlx_image_to_window(game->mlx, game->img.exits[0].image, \
		x * IMG_WIDTH, y * IMG_HEIGHT);
}

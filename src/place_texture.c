/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:30:31 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 20:56:26 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_texture(t_game *game)
{
	place_png_to_img(game, &game->img.floor[0], PNG_FLOOR0);
	place_png_to_img(game, &game->img.floor[1], PNG_FLOOR1);
	place_png_to_img(game, &game->img.wall, PNG_WALL);
	place_floor_with_texture(game);
	place_layer_with_texture(game);
	place_counter_and_level(game);
}

void	place_floor_with_texture(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.columns)
	{
		x = 0;
		while (x < game->map.rows)
		{
			if ((x % 2 == 1 && y % 2 != 1) || (x % 2 != 1 && y % 2 == 1))
				ft_mlx_image_to_window(game, game->img.floor[0], x, y);
			else
				ft_mlx_image_to_window(game, game->img.floor[1], x, y);
			x++;
		}
		y++;
	}
}

void	place_layer_with_texture(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.columns)
	{
		x = -1;
		while (++x < game->map.rows)
		{
			if (game->map.repo[y][x] == CHAR_WALL)
				mlx_image_to_window(game->mlx, game->img.wall, \
					x * IMG_WIDTH, y * IMG_HEIGHT);
			else if (game->map.repo[y][x] == CHAR_COLLLECT)
				init_collect(game, x, y, &game->count);
			else if (game->map.repo[y][x] == CHAR_EXIT)
				init_exit(game, x, y);
			else if (game->map.repo[y][x] == CHAR_ENEMY)
				init_enemy(game, x, y);
			else if (game->map.repo[y][x] == CHAR_PLAYER)
				init_player(game, x, y);
			else if (game->map.repo[y][x] == CHAR_STRONG)
				init_strong(game, x, y);
		}
	}
	game->count = 0;
}

void	place_counter_and_level(t_game *game)
{
	mlx_put_string(game->mlx, "Steps: ", 10, 10);
	mlx_put_string(game->mlx, "Level: ", 10, 30);
	write_counter(game);
	write_level(game);
}

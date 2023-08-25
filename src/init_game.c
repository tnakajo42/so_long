/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:00:56 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/23 18:32:08 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_value(t_game *game)
{
	game->position.x = 0;
	game->position.y = 0;
	game->position.move = 0;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collects = 0;
	game->map.enemies = 0;
	game->map.strongs = 0;
	game->map.exits = 0;
	game->map.player = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.repo = NULL;
	game->count = 0;
	game->level = 41;
	game->finish_game = 0;
	game->map.fill = NULL;
}

void	set_player_position(t_multi *info, t_position *position)
{
	info->x = position->x;
	info->y = position->y;
	ft_printf("Player position set to (%d,%d)\n", position->x, position->y);
}

void	set_enemy_position(t_multi *info, t_position *position)
{
	info->x = position->x;
	info->y = position->y;
	ft_printf("enemy position set to (%d,%d)\n", position->x, position->y);
}

void	init_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(IMG_WIDTH * game->map.rows, \
		IMG_HEIGHT * game->map.columns, "so long", true);
	if (!game->mlx)
	{
		ft_error_and_free_map("Failed to initialize MLX.", game);
		exit(1);
	}
}

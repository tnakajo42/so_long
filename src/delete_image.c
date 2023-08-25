/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:09:02 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 20:53:54 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_item(t_game *game, int x, int y)
{
	int	i;
	int	collect_x;
	int	collect_y;

	collect_x = 0;
	collect_y = 0;
	game->map.repo[y][x] = '0';
	i = 0;
	while (i < game->map.collects && game->count < game->map.collects)
	{
		if (game->count >= game->map.collects)
			break ;
		collect_x = game->img.collect[i].x;
		collect_y = game->img.collect[i].y;
		if (collect_x == x && collect_y == y)
		{
			mlx_delete_image(game->mlx, game->img.collect[i].image);
			game->count++;
		}
		i++;
	}
}

void	delete_collectible(t_game *game)
{
	int	finded;
	int	y;
	int	x;

	y = 0;
	while (y < game->map.columns)
	{
		x = 0;
		while (x < game->map.rows)
		{
			if (game->map.repo[y][x] == CHAR_COLLLECT)
				delete_item(game, x, y);
			x++;
		}
		y++;
	}
	if (game->count != game->map.collects)
		ft_error_and_free_map("could not delete all floor image", game);
}

void	delete_player(t_game *game)
{
	if (!game->img.player.image)
		return ;
	mlx_delete_image(game->mlx, game->img.player.image);
}

void	delete_floor(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_delete_image(game->mlx, game->img.floor[i]);
		i++;
	}
}

void	delete_all_image(t_game *game)
{
	delete_collectible(game);
	delete_floor(game);
	delete_player(game);
	delete_enemies(game);
	mlx_delete_image(game->mlx, game->img.exits[0].image);
	mlx_delete_image(game->mlx, game->img.exits[1].image);
	mlx_delete_image(game->mlx, game->img.wall);
}

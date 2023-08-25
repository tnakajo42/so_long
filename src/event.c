/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:36:32 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 21:51:46 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		*y;
	int		*x;

	game = param;
	y = &game->img.player.image->instances[0].y;
	x = &game->img.player.image->instances[0].x;
	player_moves(keydata, *y, *x, game);
	enemy_watch_player(game, *x, *y);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT || \
			keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			enemy_moves(game, *x, *y);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP || \
			keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			enemy_moves(game, *x, *y);
	}
	if_touch_enemy(game, *x, *y);
	collect_item(game, *x, *y);
	if_finish(game, *x, *y);
}

void	player_moves(mlx_key_data_t keydata, int y, int x, t_game *game)
{
	if (keydata.action == MLX_PRESS && \
		(keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && \
		game->map.repo[(y - IMG_HEIGHT) / IMG_HEIGHT][x / IMG_WIDTH] != \
		CHAR_WALL)
		game->img.player.image->instances[0].y -= IMG_HEIGHT;
	else if (keydata.action == MLX_PRESS && \
		(keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && \
		game->map.repo[(y + IMG_HEIGHT) / IMG_HEIGHT][x / IMG_WIDTH] != \
		CHAR_WALL)
		game->img.player.image->instances[0].y += IMG_HEIGHT;
	else if (keydata.action == MLX_PRESS && \
		(keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && \
		game->map.repo[y / IMG_HEIGHT][(x - IMG_WIDTH) / IMG_HEIGHT] != \
		CHAR_WALL)
		game->img.player.image->instances[0].x -= IMG_WIDTH;
	else if (keydata.action == MLX_PRESS && \
		(keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && \
		game->map.repo[y / IMG_HEIGHT][(x + IMG_WIDTH) / IMG_WIDTH] != \
		CHAR_WALL)
		game->img.player.image->instances[0].x += IMG_WIDTH;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else
		return ;
	write_counter(game);
}

void	collect_item(t_game *game, int x, int y)
{
	int	i;
	int	collect_x;
	int	collect_y;

	collect_x = 0;
	collect_y = 0;
	if (game->map.repo && game->map.repo[y / IMG_HEIGHT][x / IMG_WIDTH] == \
		CHAR_COLLLECT)
	{
		game->map.repo[y / IMG_HEIGHT][x / IMG_WIDTH] = CHAR_FLOOR;
		i = 0;
		while (i < game->map.collects && game->count < game->map.collects)
		{
			if (game->count >= game->map.collects)
				break ;
			collect_x = game->img.collect[i].x;
			collect_y = game->img.collect[i].y;
			if (collect_x == x / IMG_WIDTH && collect_y == y / IMG_HEIGHT)
			{
				mlx_delete_image(game->mlx, game->img.collect[i].image);
				game->count++;
			}
			i++;
		}
	}
}

void	if_finish(t_game *game, int x, int y)
{
	if (game->count == game->map.collects && game->finish_game != 1)
	{
		ft_printf("\\\\\\ LEVEL UP!! You've got strong. ////\n");
		mlx_delete_image(game->mlx, game->img.exits[0].image);
		mlx_image_to_window(game->mlx, game->img.exits[1].image, \
			game->img.exits[0].x * IMG_WIDTH, \
			game->img.exits[0].y * IMG_HEIGHT);
		game->finish_game = 1;
		game->level++;
		write_level(game);
	}
	if (game->finish_game == 1 && \
		game->map.repo[y / IMG_HEIGHT][x / IMG_WIDTH] == CHAR_EXIT)
		mlx_close_window(game->mlx);
}

void	if_touch_enemy(t_game *game, int x, int y)
{
	if (game->map.repo && (game->map.repo[y / IMG_HEIGHT][x / IMG_WIDTH] == \
		CHAR_ENEMY || game->map.repo[y / IMG_HEIGHT][x / IMG_WIDTH] == \
		CHAR_STRONG))
	{
		game->map.repo[y / IMG_HEIGHT][x / IMG_WIDTH] = CHAR_COLLLECT;
		ft_printf("--- OMG! You've touched a enemy.\n");
		mlx_close_window(game->mlx);
	}
}

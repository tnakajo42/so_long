/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:36:32 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 21:47:59 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_counter(t_game *game)
{
	char				*move_count;
	int					size;
	static mlx_image_t	*counter;

	move_count = NULL;
	if (counter)
		mlx_delete_image(game->mlx, counter);
	size = ft_get_len(game->position.move);
	move_count = ft_itoa(game->position.move);
	if (!move_count)
		ft_error_and_free_map("CAN'T count your steps", game);
	if (ft_get_len(game->position.move) >= game->map.rows)
		ft_error_and_free_map("too many steps in this map", game);
	counter = mlx_put_string(game->mlx, move_count, 90, 10);
	free(move_count);
	ft_printf("Moves => %i times\n", game->position.move++);
}

void	write_level(t_game *game)
{
	char				*level_count;
	static mlx_image_t	*counter;

	level_count = NULL;
	if (counter)
		mlx_delete_image(game->mlx, counter);
	level_count = ft_itoa(game->level);
	if (!level_count)
		ft_error_and_free_map("CAN'T count your levels", game);
	counter = mlx_put_string(game->mlx, level_count, 90, 30);
	free(level_count);
}

void	enemy_watch_player(t_game *game, int x, int y)
{
	int	i;
	int	enemy_x;
	int	enemy_y;

	i = -1;
	while (++i < game->map.enemies)
	{
		enemy_x = game->img.enemy[i].x;
		enemy_y = game->img.enemy[i].y;
		if (x / IMG_WIDTH < enemy_x)
		{
			mlx_delete_image(game->mlx, game->img.enemy[i].image);
			place_png_to_img(game, &game->img.enemy[i].image, \
				PNG_ENEMY_FLIPPED);
			mlx_image_to_window(game->mlx, game->img.enemy[i].image, \
				enemy_x * IMG_WIDTH, enemy_y * IMG_HEIGHT);
		}
		else if (x / IMG_WIDTH > enemy_x)
		{
			mlx_delete_image(game->mlx, game->img.enemy[i].image);
			place_png_to_img(game, &game->img.enemy[i].image, PNG_ENEMY);
			mlx_image_to_window(game->mlx, game->img.enemy[i].image, \
				enemy_x * IMG_WIDTH, enemy_y * IMG_HEIGHT);
		}
	}
}

void	enemy_moves(t_game *game, int x, int y)
{
	int	i;
	int	s_x;
	int	s_y;

	i = -1;
	while (++i < game->map.strongs)
	{
		s_x = game->img.strong[i].x;
		s_y = game->img.strong[i].y;
		mlx_delete_image(game->mlx, game->img.strong[i].image);
		game->map.repo[s_y][s_x] = CHAR_FLOOR;
		if (x / IMG_WIDTH < s_x && game->map.repo[s_y][s_x - 1] == CHAR_FLOOR)
			s_x--;
		else if (y / IMG_HEIGHT < s_y && game->map.repo[s_y - 1][s_x] == \
			CHAR_FLOOR)
			s_y--;
		else if (x / IMG_WIDTH > s_x && game->map.repo[s_y][s_x + 1] == \
			CHAR_FLOOR)
			s_x++;
		else if (game->map.repo[s_y + 1][s_x] == CHAR_FLOOR)
			s_y++;
		enemy_moves_sub(game, s_x, s_y, i);
	}
}

void	enemy_moves_sub(t_game *game, int strong_x, int strong_y, int i)
{
	game->map.repo[strong_y][strong_x] = CHAR_STRONG;
	place_png_to_img(game, &game->img.strong[i].image, PNG_STRONG_FLIPPED);
	mlx_image_to_window(game->mlx, game->img.strong[i].image, \
		strong_x * IMG_WIDTH, strong_y * IMG_HEIGHT);
	if (game->img.strong[i].x > strong_x)
		game->img.strong[i].x--;
	else if (game->img.strong[i].y > strong_y)
		game->img.strong[i].y--;
	else if (game->img.strong[i].x < strong_x)
		game->img.strong[i].x++;
	else if (game->img.strong[i].y < strong_y)
		game->img.strong[i].y++;
}

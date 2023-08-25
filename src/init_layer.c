/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:13:24 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/25 16:42:29 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_layer(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (game->map.repo[y])
	{
		x = 0;
		while (game->map.repo[y][x])
		{
			collect_map_struct(game->map.repo[y][x], game, x, y);
			check_surround_wall(x, y, game);
			x++;
		}
		y++;
	}
	check_possibility_clear_game(game);
	copy_map_to_fill(game);
	flood_loop(game, game->map.fill, 'X');
}

void	check_surround_wall(int x, int y, t_game *game)
{
	if (game->map.repo == NULL || game->map.columns == 0)
		ft_error_and_free_map("Map not initialized.", game);
	if (game->map.repo[0][x] != '1' || game->map.repo[y][0] != '1')
		ft_error_and_free_map("Map is not surrounded by walls.", game);
	if (game->map.columns - 1 >= 0)
	{
		if (game->map.repo[game->map.columns - 1][x] != '1')
			ft_error_and_free_map("Map is not surrounded by walls.", game);
	}
	if (game->map.rows - 1 >= 0)
	{
		if (game->map.repo[y][game->map.rows - 1] != '1')
			ft_error_and_free_map("Map is not surrounded by walls.", game);
	}
}

void	check_argument(int ac, char **av, t_game *game)
{
	int	file_len;

	if (ac != 2)
		ft_error_general("Check number of arguments. \
			Try: make switch_charractor && ./so_long ./map/map_bonus.ber");
	file_len = ft_strlen(av[1]);
	if (ft_strnstr(&av[1][file_len - 4], ".ber", 4) == NULL)
		ft_error_general("Invalid map file.");
}

void	check_possibility_clear_game(t_game *game)
{
	if (game->map.walls < 12)
		ft_error_and_free_map("Map must have at least 12 walls.", \
		game);
	if (game->map.collects < 1 && game->map.collects > 1000)
		ft_error_and_free_map("Map must have items from 1 to 1000.", game);
	if (game->map.enemies > 100)
		ft_error_and_free_map("Map must have at most 100 enemies", game);
	if (game->map.strongs > 3)
		ft_error_and_free_map("Map must have at most 3 S enemies", game);
	if (!game->map.exits || game->map.exits > 1)
		ft_error_and_free_map("Map must have exactly one exit.", game);
	if (!game->map.player || game->map.player > 1)
		ft_error_and_free_map("Map must have exactly one player.", game);
}

void	collect_map_struct(char c, t_game *game, int x, int y)
{
	if (ft_strchr(CHAR_MAP, c) == NULL)
		ft_error_and_free_map("Invalid map. Map contains invalid character.", \
		game);
	if (c == CHAR_WALL)
		game->map.walls++;
	if (c == CHAR_PLAYER)
	{
		game->position.x = x;
		game->position.y = y;
		game->map.player++;
	}
	if (c == CHAR_COLLLECT)
		game->map.collects++;
	if (c == CHAR_FLOOR)
		game->map.floor++;
	if (c == CHAR_EXIT)
		game->map.exits++;
}

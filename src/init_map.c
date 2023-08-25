/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:30:14 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 21:31:43 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_2d_malloc(t_game *game)
{
	if (!game->map.repo)
	{
		game->map.repo = (char **)malloc(sizeof(char *) * 270);
		if (!game->map.repo)
			ft_error_general("Failed to allocate memory for map.");
		ft_memset(game->map.repo, 0, 270);
	}
}

void	check_map_len(t_game *game, char *line, int index)
{
	int	len;

	len = ft_readline(line);
	if (index == 0)
		game->map.rows = len;
	if (len >= MAP_WIDTH / IMG_WIDTH)
		ft_error_and_free_map("Map file too wide.\n", game);
	return ;
}

void	is_emtpy_file(char *line)
{
	int	len;

	if (line == NULL)
		ft_error_general("Map file is empty.");
	len = ft_readline(line);
}

void	init_map(char **av, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->fd);
	is_emtpy_file(line);
	i = 0;
	while (line && !(line[0] == '\n'))
	{
		if (i >= MAP_HEIGHT / IMG_HEIGHT)
			ft_error_and_free_map("Map file too high.\n", game);
		if (game->map.repo == NULL)
			map_2d_malloc(game);
		game->map.repo[i] = malloc(sizeof(char) * (ft_readline(line) + 1));
		if (!game->map.repo[i])
			ft_error_and_free_map("Map file is something wrong.\n", game);
		check_map_len(game, line, i);
		ft_strlcpy(game->map.repo[i], line, game->map.rows + 1);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.columns = i;
	free(line);
	close(game->fd);
}

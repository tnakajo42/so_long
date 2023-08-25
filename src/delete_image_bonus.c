/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:09:02 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 20:53:45 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_enemies(t_game *game)
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
			if (game->map.repo[y][x] == CHAR_ENEMY)
				delete_item(game, x, y);
			else if (game->map.repo[y][x] == CHAR_STRONG)
				delete_item(game, x, y);
			x++;
		}
		y++;
	}
}

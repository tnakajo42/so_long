/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:33:08 by tnakajo           #+#    #+#             */
/*   Updated: 2023/08/22 20:45:59 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_readline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (i);
}

void	ft_mlx_image_to_window(t_game *game, mlx_image_t *mlx_image, \
			int x, int y)
{
	mlx_image_to_window(game->mlx, mlx_image, x * IMG_WIDTH, y * IMG_HEIGHT);
	if (!mlx_image)
	{
		ft_free_map_repo(game->map.repo);
		ft_error_general("mlx image uninit");
	}
}

void	place_png_to_img(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*my_texture;

	my_texture = mlx_load_png(path);
	if (!my_texture)
		ft_error_and_free_map("wow! texture fucked up.", game);
	*img = mlx_texture_to_image(game->mlx, my_texture);
	mlx_delete_texture(my_texture);
	if (!*img)
		ft_error_and_free_map("wow! image fucked up.", game);
}

int	ft_get_len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

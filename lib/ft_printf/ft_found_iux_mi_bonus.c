/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_iux_mi_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:21:16 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 22:31:04 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_x_mi_bonus(size_t x, int i, char flag, int n)
{
	int	len;

	len = 0;
	len = ft_x_len_bonus(x, len);
	if (!x && n == 0)
		return (i);
	if (flag == '.' && n == 0 && x == 0)
		return (i);
	else if (flag == '#')
	{
		i = ft_found_s("0x", 0) + ft_found_x(x, 0);
		i = ft_flagf_bonus(len, n - 2, ' ', i);
	}
	else if (flag == '0' || flag == '.')
		i = ft_flagf_bonus(len, n, '0', i) + ft_found_x(x, i);
	else if (flag == 'Z')
	{
		if (x != 0)
			i = ft_found_s("0x", i);
		i = ft_flagf_bonus(len, n, '0', 0) + ft_found_x(x, i);
	}
	else
		i = ft_flagf_bonus(len, n, ' ', i) + ft_found_x(x, i);
	return (i);
}

int	ft_found_bigx_mi_bonus(size_t bigx, int i, char flag, int n)
{
	int	len;

	len = 0;
	len = ft_x_len_bonus(bigx, len);
	if (!bigx && n == 0)
		return (i);
	if (flag == '.' && n == 0 && bigx == 0)
		return (i);
	else if (flag == '#')
	{
		i = ft_found_s("0X", 0) + ft_found_bigx(bigx, 0);
		i = ft_flagf_bonus(len, n - 2, ' ', i);
	}
	else if (flag == '0' || flag == '.')
		i = ft_flagf_bonus(len, n, '0', i) + ft_found_bigx(bigx, i);
	else if (flag == 'Z')
	{
		if (bigx != 0)
			i = ft_found_s("0X", i);
		i = ft_flagf_bonus(len, n, '0', 0) + ft_found_bigx(bigx, i);
	}
	else
		i = ft_flagf_bonus(len, n, ' ', i) + ft_found_bigx(bigx, i);
	return (i);
}

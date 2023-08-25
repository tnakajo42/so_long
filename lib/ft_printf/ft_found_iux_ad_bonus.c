/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_iux_ad_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:21:16 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 23:03:49 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_u_ad_bonus(unsigned int u, int i, char flag, int n)
{
	if (u == 0)
	{
		i = ft_flagf_bonus(0, n, ' ', i);
		return (i);
	}
	return (ft_found_u_bonus(u, i, flag, n));
}

int	ft_found_x_ad_bonus(size_t x, int i, char flag, int n)
{
	if (x == 0)
	{
		i = ft_flagf_bonus(0, n, ' ', i);
		return (i);
	}
	return (ft_found_x_bonus(x, i, flag, n));
}

int	ft_found_bigx_ad_bonus(size_t bigx, int i, char flag, int n)
{
	if (bigx == 0)
	{
		i = ft_flagf_bonus(0, n, ' ', i);
		return (i);
	}
	return (ft_found_bigx_bonus(bigx, i, flag, n));
}

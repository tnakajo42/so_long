/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_iux_od_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:21:16 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/10 18:26:13 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_u_od_bonus(unsigned int u, int i)
{
	if (!u)
		return (i);
	else
		i = ft_found_u(u, i);
	return (i);
}

int	ft_found_x_od_bonus(size_t x, int i)
{
	if (!x)
		return (i);
	else
		i = ft_found_x(x, i);
	return (i);
}

int	ft_found_bigx_od_bonus(size_t bigx, int i)
{
	if (!bigx)
		return (i);
	else
		i = ft_found_bigx(bigx, i);
	return (i);
}

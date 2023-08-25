/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_iux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:48:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/02 17:44:54 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_u(unsigned int u, int i)
{
	if (u < 10)
		i = ft_found_c(u + '0', i);
	else if (u >= 10)
	{
		i = ft_found_u(u / 10, i);
		i = ft_found_c(u % 10 + '0', i);
	}
	return (i);
}

int	ft_found_x(size_t x, int i)
{
	unsigned int	u;

	u = (unsigned int)x;
	if (u == 0)
		i = ft_found_c('0', i);
	else if (u >= 16)
	{
		i = ft_found_x(u / 16, i);
		i = ft_found_x(u % 16, i);
	}
	else
	{
		if (u <= 9)
			i = ft_found_c(u + '0', i);
		else
			i = ft_found_c(u - 10 + 'a', i);
	}
	return (i);
}

int	ft_found_bigx(size_t bigx, int i)
{
	unsigned int	u;

	u = (unsigned int)bigx;
	if (u == 0)
		i = ft_found_c('0', i);
	else if (u >= 16)
	{
		i = ft_found_bigx(u / 16, i);
		i = ft_found_bigx(u % 16, i);
	}
	else
	{
		if (bigx <= 9)
			i = ft_found_c(u + '0', i);
		else
			i = ft_found_c(u - 10 + 'A', i);
	}
	return (i);
}

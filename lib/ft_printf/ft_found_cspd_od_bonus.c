/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_cspd_od_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:18 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 23:04:02 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_p_od_bonus(size_t p, int i)
{
	if (!p)
		i = ft_found_s("(nil)", i);
	else
		i = ft_found_p(p, i);
	return (i);
}

int	ft_found_i_plus_d_od_bonus(int d, int i)
{
	if (!d)
		return (i);
	else
		i = ft_found_i_plus_d(d, i);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_cspd_ad_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:00:01 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 16:58:05 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_s_ad_bonus(char *s, int i, char flag, int n)
{
	if (i == 1)
		i--;
	if (!s && flag == '-')
		i = ft_flagf_bonus(0, n, ' ', 0);
	else if (!s)
		i = ft_flagf_bonus(0, n, ' ', 0);
	else
		i = ft_flagf_bonus(0, n, ' ', 0);
	return (i);
}

int	ft_found_i_plus_d_ad_bonus(int d, int i, char flag, int n)
{
	if (d == 0)
	{
		i = ft_flagf_bonus(0, n, ' ', i);
		return (i);
	}
	return (ft_found_i_plus_d_bonus(d, i, flag, n));
}

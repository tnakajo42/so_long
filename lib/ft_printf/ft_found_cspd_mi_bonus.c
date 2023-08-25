/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_cspd_mi_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:48:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 22:22:34 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_s_mi_bonus(char *s, int i, char flag, int n)
{
	int	len;
	int	dot_i;

	dot_i = 0;
	if (i == 1)
		i--;
	if (!s && flag == '.')
		return (i);
	else if (!s)
		i = ft_found_s("(null)", 0);
	else
	{
		len = ft_strlen_bonus(s);
		while (s[dot_i] && dot_i < n)
			i = ft_found_c(s[dot_i++], i);
	}
	return (i);
}

int	ft_found_i_plus_d_mi_bonus(int d, int i, int n)
{
	char	*d_;
	int		len;

	d_ = ft_itoa_bonus(d);
	len = ft_strlen_bonus(d_);
	if (!d && n == 0)
		return (i);
	if (i == 1 && (d >= 0))
		write(1, " ", 1);
	else if (i == 1)
		i--;
	if (d < 0 || d == -2147483648)
		i = ft_print_minusd_bonus(d_, n, '.', i);
	else
		i = ft_flagf_bonus(len, n, '0', i) + ft_found_i_plus_d(d, i);
	free(d_);
	return (i);
}

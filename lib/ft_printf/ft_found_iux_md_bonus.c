/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_iux_md_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:21:16 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 00:18:52 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_u_md_bonus(unsigned int u, int b, int a)
{
	int		i;
	int		j;
	char	*u_;
	int		len;

	i = 0;
	j = 0;
	u_ = ft_itoa_bonus((long)u);
	len = ft_strlen_bonus(u_);
	if (len < a)
		i = ft_flagf_bonus(a, b, ' ', i);
	else
		i = ft_flagf_bonus(len, b, ' ', i);
	i = ft_flagf_bonus(len, a, '0', i);
	if (b <= len && a >= len && a != 0)
		while (a < len--)
			if (len < b)
				i = ft_found_c(' ', i);
	if (a == 0 && u == 0)
		i = ft_found_c(' ', i);
	else
		i = ft_found_s(u_, i);
	free (u_);
	return (i);
}

int	ft_found_x_md_bonus(size_t x, int b, int a, char flag)
{
	int		i;
	int		len;
	int		a_;

	i = 0;
	len = ft_x_len_bonus(x, 0);
	a_ = a;
	if (len < a)
		i = ft_flagf_bonus(a, b, ' ', i);
	else
		i = ft_flagf_bonus(len, b, ' ', i);
	if (flag == '#' && x != 0)
		i = ft_found_s("0x", i);
	i = ft_flagf_bonus(len, a, '0', i);
	if (b <= len && a >= len && a != 0)
		while (a < len--)
			if (len < b)
				i = ft_found_c(' ', i);
	if (a_ == 0 && x == 0)
		return (ft_found_c(' ', i));
	i = ft_found_x(x, i);
	return (i);
}

int	ft_found_bigx_md_bonus(size_t bigx, int b, int a, char flag)
{
	int		i;
	int		len;
	int		a_;

	i = 0;
	len = ft_x_len_bonus(bigx, 0);
	a_ = a;
	if (len < a)
		i = ft_flagf_bonus(a, b, ' ', i);
	else
		i = ft_flagf_bonus(len, b, ' ', i);
	if (flag == '#' && bigx != 0)
		i = ft_found_s("0X", i);
	i = ft_flagf_bonus(len, a, '0', i);
	if (b <= len && a >= len && a != 0)
		while (a < len--)
			if (len < b)
				i = ft_found_c(' ', i);
	if (a_ == 0 && bigx == 0)
		return (ft_found_c(' ', i));
	i = ft_found_bigx(bigx, i);
	return (i);
}

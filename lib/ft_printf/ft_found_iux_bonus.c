/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_iux_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:48:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 23:11:58 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_u_bonus(unsigned int u, int i, char flag, int n)
{
	int		len;
	char	*u_;

	u_ = ft_itoa_bonus((long)u);
	len = ft_strlen_bonus(u_);
	if (!u && n == 0)
	{
		free (u_);
		return (i);
	}
	if (i == 1)
		i--;
	if (flag == '-')
		i = ft_found_u(u, i) + ft_flagf_bonus(len, n, ' ', i);
	else if (flag == '0' || flag == '.')
		i = ft_flagf_bonus(len, n, '0', i) + ft_found_u(u, i);
	else
		i = ft_flagf_bonus(len, n, ' ', i) + ft_found_u(u, i);
	free (u_);
	return (i);
}

int	ft_found_x_bonus(size_t x, int i, char flag, int n)
{
	int	len;

	len = ft_x_len_bonus(x, 0);
	if (flag == '.' && n == 0 && x == 0)
		return (i);
	if (flag == '-')
		i = ft_found_x(x, i) + ft_flagf_bonus(len, n, ' ', i);
	else if (flag == '0' || flag == '.')
		i = ft_flagf_bonus(len, n, '0', i) + ft_found_x(x, i);
	else if (flag == 'Z')
	{
		if (x != 0)
			i = ft_found_s("0x", i);
		i = ft_flagf_bonus(len + 2, n, '0', 0) + ft_found_x(x, i);
	}
	else if (flag == '#')
	{
		i = ft_flagf_bonus(len + 2, n, ' ', i);
		if (x != 0)
			i = ft_found_s("0x", i);
		i = ft_found_x(x, i);
	}
	else
		i = ft_flagf_bonus(len, n, ' ', i) + ft_found_x(x, i);
	return (i);
}

int	ft_found_bigx_bonus(size_t bigx, int i, char flag, int n)
{
	int	len;

	len = ft_x_len_bonus(bigx, 0);
	if (flag == '.' && n == 0 && bigx == 0)
		return (i);
	if (flag == '-')
		i = ft_found_bigx(bigx, i) + ft_flagf_bonus(len, n, ' ', i);
	else if (flag == '0' || flag == '.')
		i = ft_flagf_bonus(len, n, '0', i) + ft_found_bigx(bigx, i);
	else if (flag == 'Z')
	{
		if (bigx != 0)
			i = ft_found_s("0X", i);
		i = ft_flagf_bonus(len + 2, n, '0', 0) + ft_found_bigx(bigx, i);
	}
	else if (flag == '#')
	{
		i = ft_flagf_bonus(len + 2, n, ' ', i);
		if (bigx != 0)
			i = ft_found_s("0X", i);
		i = ft_found_bigx(bigx, i);
	}
	else
		i = ft_flagf_bonus(len, n, ' ', i) + ft_found_bigx(bigx, i);
	return (i);
}

int	ft_x_len_bonus(size_t x, int len)
{
	unsigned int	u;

	u = (unsigned int)x;
	if (u == 0)
		len++;
	else if (u >= 16)
	{
		len = ft_x_len_bonus(u / 16, len);
		len = ft_x_len_bonus(u % 16, len);
	}
	else
		len++;
	return (len);
}

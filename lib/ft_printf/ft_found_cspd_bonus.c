/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_cspd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:48:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 17:32:26 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_found_not_s_bonus(int i, char flag, int n);

int	ft_found_c_bonus(int c, int i, char flag, int n)
{
	if (i == 1)
		i--;
	if (flag == '-')
	{
		i = ft_found_c(c, i);
		while (n-- > 1)
			i = ft_found_c(' ', i);
	}
	else if (flag == '0' || flag == ' ')
	{
		while (n-- > 1)
			i = ft_found_c(' ', i);
		i = ft_found_c(c, i);
	}
	else
		i = ft_found_c(c, i);
	return (i);
}

int	ft_found_s_bonus(char *s, int i, char flag, int n)
{
	int	len;
	int	dot_i;

	dot_i = 0;
	if (i == 1)
		i--;
	if (!s)
		i = ft_found_not_s_bonus(i, flag, n);
	else if (s)
	{
		len = ft_strlen_bonus(s);
		if (flag == '-' && n != 0)
			i = ft_found_s(s, i) + ft_flagf_bonus(len, n, ' ', i);
		else if (flag == '.')
			while (s[dot_i] && dot_i < n)
				i = ft_found_c(s[dot_i++], i);
		else if (flag == ' ')
			i = ft_flagf_bonus(len, n, ' ', i) + ft_found_s(s, i);
		else if (n != 0)
			i = ft_found_s(s, i);
	}
	return (i);
}

static int	ft_found_not_s_bonus(int i, char flag, int n)
{
	if (flag == '-')
		i = ft_found_s("(null)", 0) + ft_flagf_bonus(6, n, ' ', 0);
	else if (flag == '.' && n >= 6)
		i = ft_found_s("(null)", 0);
	else if (flag != '.')
		i = ft_flagf_bonus(6, n, ' ', 0) + ft_found_s("(null)", 0);
	return (i);
}

int	ft_found_p_bonus(size_t p, int i, char flag, int n)
{
	int	len;

	if (!p && n == 0)
		return (ft_found_s("(nil)", i));
	len = 2;
	len = ft_p_len_bonus(p, len);
	if (i == 1)
		write(1, " ", 1);
	if (flag == '-')
	{
		if (!p)
			i = ft_found_p(p, i) + ft_flagf_bonus(len, n - 2, ' ', i);
		else
			i = ft_found_p(p, i) + ft_flagf_bonus(len, n, ' ', i);
	}
	else
	{
		if (!p)
			i = ft_flagf_bonus(len, n - 2, ' ', i) + ft_found_p(p, i);
		else
			i = ft_flagf_bonus(len, n, ' ', i) + ft_found_p(p, i);
	}
	return (i);
}

int	ft_found_i_plus_d_bonus(int d, int i, char f, int n)
{
	char	*d_;
	int		len;

	if ((!d || d == 0) && n == 0 && f == '.')
		return (i);
	d_ = ft_itoa_bonus(d);
	len = ft_strlen_bonus(d_);
	if (i == 1 && (d >= 0))
		write(1, " ", 1);
	else if (i == 1)
		i--;
	if ((d < 0 || d == -2147483648) && (f == '0' || f == '.' || f == 'Z'))
		i = ft_print_minusd_bonus(d_, n, f, i);
	else if (f == 'Z' && (f == '0' || f == '.' || f == 'Z'))
		i += ft_flagf_bonus(len, n, ' ', 0) + ft_found_i_plus_d(d, 0);
	else if (f == '0' || f == '.' || f == 'Z')
		i += ft_flagf_bonus(len, n, '0', 0) + ft_found_i_plus_d(d, 0);
	else if (f == '-')
		i += ft_found_i_plus_d(d, 0) + ft_flagf_bonus(len, n, ' ', 0);
	else if (f == ' ')
		i += ft_flagf_bonus(len, n, ' ', 0) + ft_found_i_plus_d(d, 0);
	free(d_);
	return (i);
}

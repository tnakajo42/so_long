/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_cspd_md_mi_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:48:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 00:12:51 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_found_i_plus_d_md_mi_sub_bonus(char *d_, int a, int len);

int	ft_found_s_md_mi_bonus(char *s, int b, int a)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (!s && a >= 6)
		i = ft_found_s("(null)", 0) + ft_flagf_bonus(6, b, ' ', 0);
	else if (!s)
		i = ft_flagf_bonus(0, b, ' ', 0);
	else
	{
		len = ft_strlen_bonus(s);
		j = 0;
		while (s[j] && a-- > 0)
			i = ft_found_c(s[j++], i);
		while ((b--) - j > 0)
			i = ft_found_c(' ', i);
		i = ft_flagf_bonus(len, b, ' ', i);
	}
	return (i);
}

int	ft_found_p_md_mi_bonus(size_t p, int b, int a, char flag)
{
	int	i;
	int	len;

	if (!p)
		i = ft_found_p(p, 0) + ft_flagf_bonus(5, b, ' ', 0);
	else
	{
		i = 0;
		len = ft_p_len_bonus(p, i);
		if (flag == '+')
		{
			b--;
			i = ft_found_c('+', i);
		}
		i = ft_found_s("0x", i);
		i += ft_flagf_bonus(len, a, '0', 0) + ft_to_hex(p, 0);
		if (len < b)
			while (len < b-- - 2 && a < b - 1)
				i = ft_found_c(' ', i);
	}
	return (i);
}

int	ft_found_i_plus_d_md_mi_bonus(int d, int b, int a)
{
	int		i;
	int		j;
	char	*d_;
	int		len;

	j = 0;
	d_ = ft_itoa_bonus(d);
	len = ft_strlen_bonus(d_);
	i = ft_found_i_plus_d_md_mi_sub_bonus(d_, a, len);
	if (d_[j] == '-')
		j++;
	if (a == 0 && d == 0)
		while (b - i > 0)
			i = ft_found_c(' ', i);
	else
	{
		while (d_[j])
			i = ft_found_c(d_[j++], i);
		while (b - i > 0)
			i = ft_found_c(' ', i);
	}
	free (d_);
	return (i);
}

static int	ft_found_i_plus_d_md_mi_sub_bonus(char *d_, int a, int len)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	j = 0;
	d = ft_atoi_bonus(d_);
	if (d_[j] == '-')
	{
		i = ft_found_c('-', i);
		a++;
		j++;
	}
	if (len < a)
		i = ft_flagf_bonus(len, a, '0', i);
	return (i);
}

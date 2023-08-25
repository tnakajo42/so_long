/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:55:14 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 22:19:08 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isdigit_bonus(const char *f, int j, int bonus_len);
static int	ft_printd_bonus(const char *f, va_list args, int j, int i);
static int	ft_others_bonus(const char *f, va_list args, int i);

int	ft_printf_bonus(const char *f, va_list args, int j, int i)
{
	int	j_;
	int	k;

	k = ft_check_bonus(f, j, "-0123456789.# +");
	k = j + k;
	j_ = j;
	if (ft_isdigit_bonus(f, j, k))
		return (ft_printd_bonus(f, args, j, i));
	if (f[k - 1] == '.')
		return (ft_printf_od_bonus(f[k], args, i));
	while (f[j])
	{
		if (f[j] == '#' && (f[k] == 'x' || f[k] == 'X'))
			return (ft_found_sharp_bonus(f[k], args, "0", i));
		if (f[j] == '+' && (f[k] == 'd' || f[k] == 'i'))
			return (ft_found_plus_bonus(args, i));
		j++;
	}
	while (f[j_])
		if (f[j_++] == ' ' && (f[k] == 'd' || f[k] == 'i' || f[k] == 's'))
			return (ft_found_space_bonus(f[k], args, i));
	return (ft_others_bonus(&f[k], args, i));
}

static int	ft_isdigit_bonus(const char *f, int j, int bonus_len)
{
	int	i;

	i = 0;
	while (f[j] && j < bonus_len)
	{
		if (f[j] >= 48 && f[j] <= 57)
			i++;
		j++;
	}
	if (i > 0)
		return (2048);
	return (0);
}

static int	ft_printd_bonus(const char *f, va_list args, int j, int i)
{
	int		k;
	int		n;
	int		n_;
	char	*a;

	k = ft_check_bonus(f, j, "-0123456789.# +") + j;
	n = ft_checknum_bonus(f, j, "123456789", k) + j;
	n_ = ft_checknum_bonus(f, j, "0123456789", k) + j;
	while (n_++ < k - 1)
		if (f[n_] == '.' && f[k - 1] != '.')
			return (i + ft_found_md_bonus(f, args, j, n_));
	if (f[k - 1] == '.')
		return (ft_printd_ad_bonus(f, args, j, i));
	else
		a = ft_m_bonus((char *)malloc((k - n + 1) * sizeof(char)), f, n, k - n);
	while (j <= n--)
		if (f[n] == '-' || f[n] == '0' || f[n] == '.' || f[n] == '#')
			return (i + ft_found_mnd_bonus(f, args, a, j));
	return (i + ft_not_found_mnd_bonus(f, args, a, j));
}

int	ft_checknum_bonus(const char *f, int j, char *flags, int k)
{
	int	i;
	int	l;

	i = 0;
	while (f[j] && j < k)
	{
		l = 0;
		while (flags[l])
		{
			if (f[j] == flags[l])
				return (i);
			l++;
		}
		j++;
		i++;
	}
	i--;
	return (i);
}

static int	ft_others_bonus(const char *f, va_list args, int i)
{
	if (*f == 'c')
		i = ft_found_c(va_arg(args, int), i);
	else if (*f == 's')
		i = ft_found_s(va_arg(args, char *), i);
	else if (*f == 'p')
		i = ft_found_p(va_arg(args, size_t), i);
	else if (*f == 'd' || *f == 'i')
		i = ft_found_i_plus_d(va_arg(args, int), i);
	else if (*f == 'u')
		i = ft_found_u(va_arg(args, unsigned int), i);
	else if (*f == 'x')
		i = ft_found_x(va_arg(args, size_t), i);
	else if (*f == 'X')
		i = ft_found_bigx(va_arg(args, size_t), i);
	else if (*f == '%')
		i = ft_found_c('%', i);
	else
		i = -1;
	return (i);
}

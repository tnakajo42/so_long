/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_md_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:20:40 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 21:33:05 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_mnssp_md_sub_bonus(const char *f, va_list args, int j, int m);
static int	ft_found_mnssp_md_bonus(const char *f, va_list args, int j, int m);
static int	ft_printf_md_bonus(const char f, va_list args, int b, int a);
static int	ft_printf_zdn_bonus(const char *f, va_list args, int j);

int	ft_found_md_bonus(const char *f, va_list args, int j, int m)
{
	int		i;
	int		k;
	int		n;
	char	*b;
	char	*a;

	k = ft_check_bonus(f, j, "-0123456789.# +") + j;
	n = ft_checknum_bonus(f, j, "123456789", k) + j;
	if (n != j)
		return (ft_found_mnssp_md_bonus(f, args, j, m));
	b = ft_m_bonus((char *)malloc((m - n + 1) * sizeof(char)), f, n, m - n);
	m++;
	a = ft_m_bonus((char *)malloc((k - m + 1) * sizeof(char)), f, m, k - m);
	i = ft_printf_md_bonus(f[k], args, ft_atoi_bonus(b), ft_atoi_bonus(a));
	free (b);
	free (a);
	return (i);
}

static int	ft_found_mnssp_md_bonus(const char *f, va_list args, int j, int m)
{
	int		j_;
	int		k;
	int		n;
	char	*b;
	char	*a;

	j_ = j;
	k = ft_check_bonus(f, j, "-0123456789.# +") + j;
	n = ft_checknum_bonus(f, j, "123456789", k) + j;
	if (m - n + 1 == 0)
		return (ft_printf_zdn_bonus(f, args, j));
	b = ft_m_bonus((char *)malloc((m - n + 1) * sizeof(char)), f, n, m - n);
	m++;
	a = ft_m_bonus((char *)malloc((k - m + 1) * sizeof(char)), f, m, k - m);
	while (f[j] && j < n)
		if (f[j++] == '-')
			return (ft_m_md_bonus(f[k], args, b, a));
	m--;
	free (a);
	free (b);
	return (ft_mnssp_md_sub_bonus(f, args, j_, m));
}

static int	ft_mnssp_md_sub_bonus(const char *f, va_list args, int j, int m)
{
	int		j_;
	int		k;
	int		n;
	char	*b;
	char	*a;

	j_ = j;
	k = ft_check_bonus(f, j, "-0123456789.# +") + j;
	n = ft_checknum_bonus(f, j, "123456789", k) + j;
	b = ft_m_bonus((char *)malloc((m - n + 1) * sizeof(char)), f, n, m - n);
	m++;
	a = ft_m_bonus((char *)malloc((k - m + 1) * sizeof(char)), f, m, k - m);
	while (f[j] && j < n)
		if (f[j++] == '+')
			return (ft_p_md_bonus(f[k], args, b, a));
	while (f[j_] && j_ < n)
	{
		if (f[j_] == '0')
			return (ft_z_md_bonus(f[k], args, b, a));
		if (f[j_++] == '#')
			return (ft_sh_md_bonus(f[k], args, b, a));
	}
	return (ft_sp_md_bonus(f[k], args, b, a));
}

static int	ft_printf_md_bonus(const char f, va_list args, int b, int a)
{
	int	i;

	i = 0;
	if (f == 'c')
		i = ft_found_c_md_bonus(va_arg(args, int), b, '_');
	else if (f == 's')
		i = ft_found_s_md_bonus(va_arg(args, char *), b, a);
	else if (f == 'p')
		i = ft_found_p_md_bonus(va_arg(args, size_t), b, a, '_');
	else if (f == 'd' || f == 'i')
		i = ft_found_i_plus_d_md_bonus(va_arg(args, int), b, a);
	else if (f == 'u')
		i = ft_found_u_md_bonus(va_arg(args, unsigned int), b, a);
	else if (f == 'x')
		i = ft_found_x_md_bonus(va_arg(args, size_t), b, a, '_');
	else if (f == 'X')
		i = ft_found_bigx_md_bonus(va_arg(args, size_t), b, a, '_');
	else if (f == '%')
		i = ft_found_c_bonus('%', i, ' ', 0);
	else
		i++;
	return (i);
}

static int	ft_printf_zdn_bonus(const char *f, va_list args, int j)
{
	int		k;
	int		n;
	char	*a;

	k = ft_check_bonus(f, j, "-0123456789.# +") + j;
	n = ft_checknum_bonus(f, j, "123456789", k) + j;
	a = ft_m_bonus((char *)malloc((k - n + 1) * sizeof(char)), f, n, k - n);
	return (ft_found_mnd_bonus(f, args, a, ++j));
}

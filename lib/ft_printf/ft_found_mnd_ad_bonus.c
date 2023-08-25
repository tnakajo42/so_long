/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_mnd_ad_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:10:37 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 23:07:51 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_not_mnd_ad_bonus(const char f, va_list args, int i, int n);

int	ft_found_mnd_ad_bonus(const char *f, va_list args, char *a, int j)
{
	int	i;
	int	k;

	i = 0;
	k = ft_check_bonus(f, j, "-0123456789.# +") + j;
	while (f[j] && j < k)
	{
		if (f[j] == ' ')
			i = 1;
		if (f[j] == '-')
			return (ft_found_minus_ad_bonus(f[k], args, a, i));
		if (f[j] == '0')
			return (ft_found_zero_ad_bonus(f[k], args, a, i));
		if (f[j] == '#')
			return (ft_found_sharp_bonus(f[k], args, a, i));
		j++;
	}
	return (i);
}

int	ft_not_found_mnd_ad_bonus(const char *f, va_list args, char *a, int j)
{
	int	i;
	int	k;
	int	n;

	i = 0;
	k = ft_check_bonus(f, j, "-0123456789.# +") + j;
	n = ft_atoi_bonus((char *)a);
	while (f[j] && j < k)
	{
		if (f[j] == ' ')
			i = 1;
		j++;
	}
	i = ft_not_mnd_ad_bonus(f[k], args, i, n);
	free(a);
	return (i);
}

static int	ft_not_mnd_ad_bonus(const char f, va_list args, int i, int n)
{
	if (f == 'c')
		i = ft_found_c_bonus(va_arg(args, int), i, ' ', n);
	else if (f == 's')
		i = ft_found_s_ad_bonus(va_arg(args, char *), i, ' ', n);
	else if (f == 'p')
		i = ft_found_p_bonus(va_arg(args, size_t), i, ' ', n);
	else if (f == 'd' || f == 'i')
		i = ft_found_i_plus_d_ad_bonus(va_arg(args, int), i, ' ', n);
	else if (f == 'u')
		i = ft_found_u_ad_bonus(va_arg(args, unsigned int), i, ' ', n);
	else if (f == 'x')
		i = ft_found_x_ad_bonus(va_arg(args, size_t), i, ' ', n);
	else if (f == 'X')
		i = ft_found_bigx_ad_bonus(va_arg(args, size_t), i, ' ', n);
	else if (f == '%')
		i = ft_found_c_bonus('%', i, ' ', 0);
	else
		i++;
	return (i);
}

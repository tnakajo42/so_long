/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagf_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:28:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 00:28:20 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagf_bonus(int len, int n, char flag, int i)
{
	while (len < n--)
		i = ft_found_c(flag, i);
	return (i);
}

int	ft_print_minusd_bonus(char *d_, int n, char flag, int i)
{
	int	d_i;
	int	len;

	d_i = 1;
	len = ft_strlen_bonus(d_);
	if (flag == 'Z')
		i = ft_flagf_bonus(len, n++, ' ', i) + ft_found_c('-', i);
	else
	{
		i = ft_found_c('-', i);
		if (flag == '.')
			n++;
		i = ft_flagf_bonus(len, n, '0', i);
	}
	while (d_[d_i])
		i = ft_found_c(d_[d_i++], i);
	return (i);
}

int	ft_p_len_bonus(size_t hex, int len)
{
	if (hex == 0)
		len++;
	else if (hex >= 16)
	{
		len = ft_p_len_bonus(hex / 16, len);
		len = ft_p_len_bonus(hex % 16, len);
	}
	else
		len++;
	return (len);
}

int	ft_md_sub_bonus(const char f, va_list args, int b_, int a_)
{
	int	i;

	i = 0;
	if (f == 's')
		i = ft_found_s_md_bonus(va_arg(args, char *), b_, a_);
	else if (f == 'd' || f == 'i')
		i = ft_found_i_plus_d_md_bonus(va_arg(args, int), b_, a_);
	else if (f == 'u')
		i = ft_found_u_md_bonus(va_arg(args, unsigned int), b_, a_);
	return (i);
}

int	ft_md_mi_sub_bonus(const char f, va_list args, int b_, int a_)
{
	int	i;

	i = 0;
	if (f == 's')
		i = ft_found_s_md_mi_bonus(va_arg(args, char *), b_, a_);
	else if (f == 'd' || f == 'i')
		i = ft_found_i_plus_d_md_mi_bonus(va_arg(args, int), b_, a_);
	else if (f == 'u')
		i = ft_found_u_md_mi_bonus(va_arg(args, unsigned int), b_, a_);
	return (i);
}

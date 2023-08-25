/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_cspd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:48:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/07 21:08:19 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_c(int c, int i)
{
	i++;
	write(1, &c, 1);
	return (i);
}

int	ft_found_s(char *s, int i)
{
	if (!s)
		i = ft_found_s("(null)", i);
	else
	{
		while (*s)
		{
			write(1, &(*s), 1);
			s++;
			i++;
		}
	}
	return (i);
}

int	ft_to_hex(size_t hex, int i)
{
	if (hex == 0)
		i = ft_found_c('0', i);
	else if (hex >= 16)
	{
		i = ft_to_hex(hex / 16, i);
		i = ft_to_hex(hex % 16, i);
	}
	else
	{
		if (hex <= 9)
			i = ft_found_c(hex + '0', i);
		else
			i = ft_found_c(hex - 10 + 'a', i);
	}
	return (i);
}

int	ft_found_p(size_t p, int i)
{
	if (p)
	{
		i = ft_found_c('0', i);
		i = ft_found_c('x', i);
		i = ft_to_hex(p, i);
	}
	else
		i = ft_found_s("(nil)", i);
	return (i);
}

int	ft_found_i_plus_d(int d, int i)
{
	if (d == -2147483648)
	{
		write (1, "-2147483648", 11);
		i = i + 11;
	}
	else if (d >= 0 && d < 10)
		i = ft_found_c(d + '0', i);
	else if (d < 0)
	{
		i = ft_found_c('-', i);
		i = ft_found_i_plus_d(-d, i);
	}
	else
	{
		i = ft_found_i_plus_d(d / 10, i);
		i = ft_found_c(d % 10 + '0', i);
	}
	return (i);
}

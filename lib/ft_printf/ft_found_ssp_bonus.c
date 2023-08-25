/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_ssp_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:26:55 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 17:25:54 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_sharp_bonus(const char format, va_list args, char *a, int i)
{
	int				n;
	unsigned int	x;

	n = ft_atoi_bonus((char *)a);
	x = (unsigned int)va_arg(args, size_t);
	if (format == 'x')
		i = ft_found_x_bonus(x, i, '#', n);
	else
		i = ft_found_bigx_bonus(x, i, '#', n);
	if (n != 0)
		free(a);
	return (i);
}

int	ft_found_zsharp_bonus(const char format, va_list args, char *a, int i)
{
	int				n;
	unsigned int	x;

	n = ft_atoi_bonus((char *)a);
	x = (unsigned int)va_arg(args, size_t);
	if (format == 'x')
		i = ft_found_x_bonus(x, i, 'Z', n);
	else
		i = ft_found_bigx_bonus(x, i, 'Z', n);
	if (n != 0)
		free(a);
	return (i);
}

int	ft_found_space_bonus(const char format, va_list args, int i)
{
	int		d;

	if (format == 's')
		i = ft_found_s(va_arg(args, char *), i);
	if (format == 'd' || format == 'i')
	{
		d = va_arg(args, int);
		if (d >= 0)
		{
			i++;
			write(1, " ", 1);
		}
		i = ft_found_i_plus_d(d, i);
	}
	return (i);
}

int	ft_found_plus_bonus(va_list args, int i)
{
	int	d;

	d = va_arg(args, int);
	if (d >= 0)
	{
		i++;
		write(1, "+", 1);
	}
	i = ft_found_i_plus_d(d, i);
	return (i);
}

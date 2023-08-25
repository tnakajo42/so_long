/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:45:09 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/12 17:22:22 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_next_percent(const char *format, va_list args, int i);
static int	ft_next_percent_bonus(const char *f, va_list args, int j, int i);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		bonus_len;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		bonus_len = 0;
		if (format[j] == '%')
		{
			bonus_len = ft_check_bonus(format, ++j, "-0123456789.# +");
			i = ft_next_percent_bonus(format, args, j, i);
		}
		else if (i >= 0)
			i = ft_found_c(format[j], i);
		if (i < 0)
			return (i);
		j = j + bonus_len + 1;
	}
	va_end(args);
	return (i);
}

static int	ft_next_percent_bonus(const char *f, va_list args, int j, int i)
{
	int	bonus_len;

	bonus_len = ft_check_bonus(f, j, "-0123456789.# +");
	if (bonus_len > 0)
		i = ft_printf_bonus(f, args, j, i);
	else
		i = ft_next_percent(&f[j], args, i);
	return (i);
}

static int	ft_next_percent(const char *format, va_list args, int i)
{
	if (*format == 'c')
		i = ft_found_c(va_arg(args, int), i);
	else if (*format == 's')
		i = ft_found_s(va_arg(args, char *), i);
	else if (*format == 'p')
		i = ft_found_p(va_arg(args, size_t), i);
	else if (*format == 'd' || *format == 'i')
		i = ft_found_i_plus_d(va_arg(args, int), i);
	else if (*format == 'u')
		i = ft_found_u(va_arg(args, unsigned int), i);
	else if (*format == 'x')
		i = ft_found_x(va_arg(args, size_t), i);
	else if (*format == 'X')
		i = ft_found_bigx(va_arg(args, size_t), i);
	else if (*format == '%')
		i = ft_found_c('%', i);
	else
		i = -1;
	return (i);
}

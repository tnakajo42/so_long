/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:43:03 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/01 15:56:35 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_cspdiux(char format, char *cspdiux);

int	ft_check_bonus(const char *format, int j, char *flags)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	while (format[j])
	{
		k = ft_check_cspdiux(format[j], "cspdiuxX%");
		if (k > 0)
			return (i);
		l = 0;
		while (flags[k])
		{
			if (format[j] == flags[k])
			{
				i++;
				l++;
			}
			k++;
		}
		if (l == 0)
			return (i);
		j++;
	}
	return (i);
}

static int	ft_check_cspdiux(char format, char *cspdiux)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (cspdiux[i])
	{
		if (format == cspdiux[i])
			k++;
		i++;
	}
	return (k);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:27:40 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/02 18:13:09 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*ft_strrev(char *str)
{
	char	tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_bonus(str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

char	*ft_itoa_bonus(long n)
{
	size_t	i;
	char	*str;
	long	nb;
	size_t	len;

	len = num_len(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	nb = n;
	i = 0;
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		nb = -nb;
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:17:16 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/04 16:56:02 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_m_bonus(void *dest, const void *src, size_t n, size_t j)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < j)
	{
		d[i] = s[n];
		n++;
		i++;
	}
	d[i] = '\0';
	return (dest);
}

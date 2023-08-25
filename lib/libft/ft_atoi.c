/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:15:54 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/07 16:20:03 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	return (number * sign);
}

/* void	main(void)
{
	char	*c;

	printf("\n---------------atoi---------------\n\n");
	c = "		123-42";
	printf("uppercase atoi: %d\n", atoi(c));
	printf("uppercase ft_atoi: %d\n", ft_atoi(c));
	c = "---3-2 e";
	printf("lowercase atoi: %d\n", atoi(c));
	printf("lowercase ft_atoi: %d\n", ft_atoi(c));
	c = "+2";
	printf("not digit case atoi: %d\n", atoi(c));
	printf("not digit case ft_atoi: %d\n", ft_atoi(c));
	printf("\n-------------------------------------\n\n");
} */

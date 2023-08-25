/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:14:57 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/06 19:52:05 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

/*
void	main(void)
{
	char	c;
	int		ascii_number;

	ascii_number = 0;
	printf("\n---------------isprint---------------\n\n");
	c = 0x80;
	printf("not ascii case isprint: %d\n", isprint(c));
	printf("not ascii case ft_isprint: %d\n", ft_isprint(c));
	while (ascii_number <= 127)
	{
		printf("%d isprint    : %d\n", ascii_number, isprint(ascii_number));
		printf("%d ft_isprint : %d\n", ascii_number, ft_isprint(ascii_number));
		ascii_number++;
	}
	printf("\n-------------------------------------\n\n");
}
*/

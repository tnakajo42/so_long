/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:05:05 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/06 19:51:43 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
void	main(void)
{
	char	c;
	int		ascii_number;

	ascii_number = 0;
	printf("\n---------------isascii---------------\n\n");
	c = 0x80;
	printf("not ascii case isascii: %d\n", isascii(c));
	printf("not ascii case ft_isascii: %d\n", ft_isascii(c));
	while (ascii_number <= 127)
	{
		printf("%d isascii    : %d\n", ascii_number, isascii(ascii_number));
		printf("%d ft_isascii : %d\n", ascii_number, ft_isascii(ascii_number));
		ascii_number++;
	}
	printf("\n-------------------------------------\n\n");
}
*/

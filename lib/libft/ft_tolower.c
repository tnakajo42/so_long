/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:20:15 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/06 19:49:31 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*
void	main(void)
{
	char	c;

	printf("\n---------------tolower---------------\n\n");
	c = 'Q';
	printf("uppercase tolower: %d\n", tolower(c));
	printf("uppercase ft_tolower: %d\n", ft_tolower(c));
	c = 'q';
	printf("lowercase tolower: %d\n", tolower(c));
	printf("lowercase ft_tolower: %d\n", ft_tolower(c));
	c = '0';
	printf("not digit case tolower: %d\n", tolower(c));
	printf("not digit case ft_tolower: %d\n", ft_tolower(c));
	c = '   ';
	printf("not digit case tolower: %d\n", tolower(c));
	printf("not digit case ft_tolower: %d\n", ft_tolower(c));
	printf("\n-------------------------------------\n\n");
}
*/

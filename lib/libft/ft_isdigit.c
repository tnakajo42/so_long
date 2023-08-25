/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:17:47 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/06 17:32:56 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

/*
void	main(void)
{
	char	c;

	printf("\n---------------isdigit---------------\n\n");
	c = 'Q';
	printf("uppercase isdigit: %d\n", isdigit(c));
	printf("uppercase ft_isdigit: %d\n", ft_isdigit(c));
	c = 'q';
	printf("lowercase isdigit: %d\n", isdigit(c));
	printf("lowercase ft_isdigit: %d\n", ft_isdigit(c));
	c = '0';
	printf("not digit case isdigit: %d\n", isdigit(c));
	printf("not digit case ft_isdigit: %d\n", ft_isdigit(c));
	c = '	';
	printf("not digit case isdigit: %d\n", isdigit(c));
	printf("not digit case ft_isdigit: %d\n", ft_isdigit(c));
	printf("\n-------------------------------------\n\n");
}
*/

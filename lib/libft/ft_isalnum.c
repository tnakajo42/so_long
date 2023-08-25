/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:04:10 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/06 17:32:20 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (8);
	if (c >= 65 && c <= 90)
		return (8);
	if (c >= 97 && c <= 122)
		return (8);
	return (0);
}

/*
void	main(void)
{
	char	c;

	printf("\n---------------isalnum---------------\n\n");
	c = 'A';
	printf("%c uppercase isalnum: %d\n", c, isalnum(c));
	printf("%c uppercase ft_isalnum: %d\n", c, ft_isalnum(c));
	c = 'z';
	printf("%c lowercase isalnum: %d\n", c, isalnum(c));
	printf("%c lowercase ft_isalnum: %d\n", c, ft_isalnum(c));
	c = '9';
	printf("%c digit case isalnum: %d\n", c, isalnum(c));
	printf("%c digit case ft_isalnum: %d\n", c, ft_isalnum(c));
	c = '	';
	printf("%c not alpha case isalnum: %d\n", c, isalnum(c));
	printf("%c not alpha case ft_isalnum: %d\n", c, ft_isalnum(c));
	c = '+';
	printf("%c not alpha case isalnum: %d\n", c, isalnum(c));
	printf("%c not alpha case ft_isalnum: %d\n", c, ft_isalnum(c));
	printf("\n-------------------------------------\n\n");
}
*/

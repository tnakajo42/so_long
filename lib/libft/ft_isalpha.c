/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:41:06 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/06 18:03:53 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1024);
	if (c >= 97 && c <= 122)
		return (1024);
	return (0);
}

/*
void	main(void)
{
	char	c;

	printf("\n---------------isalpha---------------\n\n");
	c = 'A';
	printf("uppercase isalpha: %d\n", isalpha(c));
	printf("uppercase ft_isalpha: %d\n", ft_isalpha(c));
	c = 'q';
	printf("lowercase isalpha: %d\n", isalpha(c));
	printf("lowercase ft_isalpha: %d\n", ft_isalpha(c));
	c = '+';
	printf("not alpha case isalpha: %d\n", isalpha(c));
	printf("not alpha case ft_isalpha: %d\n", ft_isalpha(c));
	c = '	';
	printf("not alpha case isalpha: %d\n", isalpha(c));
	printf("not alpha case ft_isalpha: %d\n", ft_isalpha(c));
	c = "";
	printf("not alpha case isalpha: %d\n", isalpha(c));
	printf("not alpha case ft_isalpha: %d\n", ft_isalpha(c));
	printf("\n-------------------------------------\n\n");
}
*/

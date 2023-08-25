/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:28:45 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/06 19:49:43 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/*
void	main(void)
{
	char	c;

	printf("\n---------------toupper---------------\n\n");
	c = 'Q';
	printf("uppercase toupper: %d\n", toupper(c));
	printf("uppercase ft_toupper: %d\n", ft_toupper(c));
	c = 'q';
	printf("lowercase toupper: %d\n", toupper(c));
	printf("lowercase ft_toupper: %d\n", ft_toupper(c));
	c = '0';
	printf("not digit case toupper: %d\n", toupper(c));
	printf("not digit case ft_toupper: %d\n", ft_toupper(c));
	c = '   ';
	printf("not digit case toupper: %d\n", toupper(c));
	printf("not digit case ft_toupper: %d\n", ft_toupper(c));
	printf("\n-------------------------------------\n\n");
}
*/

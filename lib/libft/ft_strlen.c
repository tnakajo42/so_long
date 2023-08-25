/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:14:29 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/20 21:15:27 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
void	main(void)
{
	char	*c;

	printf("\n---------------strlen---------------\n\n");
	c = "ZZZ 		 F\nF";
	printf("uppercase strlen: %d\n", strlen(c));
	printf("uppercase ft_strlen: %d\n", ft_strlen(c));
	c = " q	aaaa	s";
	printf("lowercase strlen: %d\n", strlen(c));
	printf("lowercase ft_strlen: %d\n", ft_strlen(c));
	c = "	0";
	printf("strlen: %d\n", strlen(c));
	printf("ft_strlen: %d\n", ft_strlen(c));
	c = "";
	printf("strlen: %d\n", strlen(c));
	printf("ft_strlen: %d\n", ft_strlen(c));
	printf("\n-------------------------------------\n\n");
}
*/

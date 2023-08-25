/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:38:48 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 21:01:25 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stddef.h> */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		arr[i] = '\0';
		i++;
	}
}

/* int	main(void)
{
	unsigned char p[10] ="hay yo";
	int i = 0;
	
	ft_bzero(p, 3);
	printf("%s\n", p);
	while (i < 3 || p[i])
	{
		printf("%c\n", p[i]);
		i++;
	}
	return (0);
} */

/* void	main(void)
{
	unsigned char	str1[100] = "http://www.tutorialspoint.com";
	unsigned char	str2[100] = "http://www.tutorialspoint.com";
	unsigned int	size;
	unsigned int	i;

	size = 10;
	printf("\n---------------bzero---------------\n\n");
	bzero(str1, size);
	i = 0;
	while (i < size || str1[i])
	{
		printf("%d:", str1[i]);
		i++;
	}
	printf("\n\n---------------ft_bzero------------\n\n");
	ft_bzero(str2, size);
	i = 0;
	while (i < size || str2[i])
	{
		printf("%d:", str1[i]);
		i++;
	}
	printf("\n\n-----------------------------------\n\n");
} */

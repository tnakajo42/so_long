/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:46:41 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/12 22:25:37 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <bsd/string.h> */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (i + 1 < size)
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	if (i == 0 || j < size)
		dst[j] = '\0';
	return (i);
}

/*
 * to test
 * gcc ft_strlcpy.c -lbsd && ./a.out
 */
/* int	main(void)
{
	int	i;
	char	s1[100] = "Hello, world!";
	char	s2[100] = "Hello, world!";

	i = 15;
	// printf("%ld\n", ft_strlcpy(s1, s1 + 4, 20));
	// printf("%s\n", s1);
	// printf("%ld\n", strlcpy(s2, s2 + 4, 20));
	// printf("%s\n", s2);
	printf("%ld\n", ft_strlcpy(s1, "", i));
	printf("%s\n", s1);
	printf("%ld\n", strlcpy(s2, "", i));
	printf("%s\n", s2);
	printf("%ld\n", ft_strlcpy(s1, "have a nice weekend", i));
	printf("%s\n", s1);
	printf("%ld\n", strlcpy(s2, "have a nice weekend", i));
	printf("%s\n", s2);
	return (0);
} */

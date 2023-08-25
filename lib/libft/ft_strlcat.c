/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:49 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/22 20:04:24 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <bsd/string.h> */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	while (i < size && dst[i])
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + len);
}

/*
 * to test
 * clear && gcc ft_strlcat.c -lbsd && ./a.out
 */
/* int	main(void)
{
	// char	d1[7] = "1234567";
	// memset(s1, 'r', 15);
	// char	s1[30] = "zxcvbnmasdfghjklqwertyuiop1234";
	char	d2[7] = "1234567";
	// // memset(s3, 'r', 15);
	char	s2[30] = "zxcvbnmasdfghjklqwertyuiop1234";
	int		i;

	i = 40;
	// ft_strlcat(s1, s2, 5);
	// printf("\n-------strlcat----------\n\n");
	// printf("%ld\n", strlcat(d1, s1, i));
	// printf("%s\n", d1);
	printf("\n-------ft_strlcat-------\n\n");
	printf("%ld\n", ft_strlcat(d2, s2, i));
	printf("%s\n", d2);
	printf("\n------------------------\n");
	return (0);
} */

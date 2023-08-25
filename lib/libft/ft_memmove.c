/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:01:15 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/22 18:40:31 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/* void	*ft_memmove_2(void *dest, const void *src, size_t n)
{
	char	*dest_;
	char	*src_;
	char	*tmp;
	size_t	i;

	dest_ = (char *)dest;
	src_ = (char *)src;
	tmp = (char *)malloc(n);
	i = 0;
	while (i < n)
	{
		tmp[i] = src_[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_[i] = tmp[i];
		i++;
	}
	return (dest);
} */

/* int	main(void)
{
	char	str1[] = "Hello, world!";
	char	str2[] = "Hello, world!";
	char	str3[] = "Hello, world!";
	char	str4[] = "Hello, world!";
	char	str5[] = "lorem ipsum dolor sit amet";
	char	str6[] = "lorem ipsum dolor sit amet";
	char	*dest1;
	char	*dest2;
	dest1 = str5 + 1;
	dest2 = str6 + 1;

	// Move the first 6 characters of the string to the end of the string.
	// This creates the string "world!Hello,".
	printf("\n");
	memmove(str1, str1, 2);
	printf("memmove    --> %s\n", str1);
	ft_memmove(str3, str3, 2);
	printf("ft_memmove --> %s\n", str3);
	
	// printf("\n");
	// memmove(str1, str1 + 3, 3);
	// printf("memmove    --> %s\n", str1);
	// ft_memmove(str3, str3 + 3, 3);
	// printf("ft_memmove --> %s\n", str3);

	// printf("\n");
	// memmove(str1 + 5, str1 + 2, 2);
	// printf("memmove    --> %s\n", str1);
	// ft_memmove(str3 + 5, str3 + 2, 2);
	// printf("ft_memmove --> %s\n", str3);
	
	// printf("\n");
	// memmove(dest1, str5 + 2, 8);
	// printf("memmove    --> %s\n", dest1);
	// ft_memmove(dest2, str6 + 2, 8);
	// printf("ft_memmove --> %s\n", dest2);
	// printf("\n");
	return (0);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:03:18 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/22 21:00:54 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	*s1 = "he2llo";
	char	*s2 = "hea\0llo";
	char	*s3 = "he2llo";
	char	*s4 = "hea\0llo";
	int		i;

	i = 4;
	printf("%d\n", memcmp(s1, s2, i));
	printf("%d\n", ft_memcmp(s3, s4, i));
	return (0);
} */

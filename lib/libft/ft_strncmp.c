/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:32:48 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 22:10:04 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	// char	str1[100] = "He\0llo";
	// char	str2[100] = "Hell";
	int		result;
	int		i;

	i = 6;
	// printf("%d\n", strncmp(str1, str2, i));
	// printf("%d\n", ft_strncmp(str1, str2, i));
	// Compare the numbers of characters of str1 and str2
	// result = ft_strncmp("test\200", "test\0", i);
	result = strncmp("test\200", "test\0", i);
	printf("%d\n", result, i);
	if (result == 0)
		printf("The strings are equal.\n");
	else if (result < 0)
		printf("str1 is less than str2.\n");
	else
		printf("str1 is greater than str2.\n");
	result = ft_strncmp("test\200", "test\0", i);
	printf("%d\n", result);
	if (result == 0)
		printf("The strings are equal.\n");
	else if (result < 0)
		printf("str1 is less than str2.\n");
	else
		printf("str1 is greater than str2.\n");
	return (0);
} */

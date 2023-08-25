/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:05:10 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/22 19:34:47 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <bsd/string.h> */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	sign;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		sign = 0;
		if (big[i] == little[sign])
		{
			while (i + sign < len && big[i + sign] == little[sign])
			{
				sign++;
				if (little[sign] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

/*
 * to test
 * gcc ft_strnstr.c -lbsd && ./a.out
int	main(void)
{
	// Search for the substring "hello" within the string "hello world"
	char str1[100] = "hello world!!";
	char str2[100] = "world";

	// Print the result
	// printf("%s\n", ft_strnstr("abc", "b", 20)); // Output: "hello"
	printf("%s\n", strnstr("abc", "b", 20)); // Output: "hello"

	// char str[] = "Hello, world!";
	// char substr[] = "world";

	// // Search for "world" in the first 5 characters of "Hello, world!"
	// // char result[] = ft_strnstr(str, substr, 5);

	// if (ft_strnstr(str, substr, 5) != NULL) {
	// 	printf("Found '%s' in '%s'\n", substr, str);
	// } else {
	//     printf("Could not find '%s' in '%s'\n", substr, str);
	// }

	return (0);
}
*/

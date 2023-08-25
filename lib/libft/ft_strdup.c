/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:32:10 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 21:52:15 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/* int	main(void)
{
	char	str1[] = "hello, world! It will be a good day";
	char	str2[] = "hello, world! It will be a good day";
	// char	*str_dup;

	// char *str1 = "Hello, world!";
	// char *str2 = "Hello, world!";
	char *dup1 = strdup(str1);
	char *dup2 = ft_strdup(str2);

	printf("\nstrdup    --> Original string   : %s\n", str1);
	printf("strdup    --> Duplicated string : %s\n", dup1);
	free(dup1);
	printf("\nft_strdup --> Original string   : %s\n", str2);
	printf("ft_strdup --> Duplicated string : %s\n", dup2);
	free(dup2);
	printf("\n");
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:23:45 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/22 21:31:57 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

/* char	*ft_strchr_2(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
 */
/* char	*ft_strchr_3(const char *s, int c)
{
	int	sign;

	sign = 0;
	while (s[sign] != '\0')
	{
		if (s[sign] == c)
			return ((char *)&s[sign]);
		sign++;
	}
	if (c == 0)
		return ((char *)&s[sign]);
	return (NULL);
} */

/* void	main(void)
{
	char	*c;
	char	ch;

	printf("\n---------------strchr---------------\n\n");
	c = "http://www.tutorialspoint.com";
	// ch = '.';
	ch = '\0';
	printf("strchr:%s;\n", strchr(c, ch));
	printf("ft_strchr:%s;\n", ft_strchr(c, ch));
	c = "---.3-2 e";
	printf("lowercase strchr:%s;\n", strchr(c, ch));
	printf("lowercase ft_strchr:%s;\n", ft_strchr(c, ch));
	c = "-";
	printf("not digit case strchr:%s;\n", strchr(c, ch));
	printf("not digit case ft_strchr:%s;\n", ft_strchr(c, ch));
	printf("\n-------------------------------------\n\n");
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:24:08 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 21:39:00 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}

/* char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	sign;

	i = 0;
	sign = -1;
	while (s[i])
	{
		if (s[i] == c)
			sign = i;
		i++;
	}
	if (c == '\0' || sign != -1)
		return ((char *)&s[sign]);
	return (NULL);
} */

/* char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			ptr = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (ptr);
} */

/* void	main(void)
{
	char	*c;
	char	ch;

	printf("\n---------------strrchr---------------\n\n");
	c = "bonjour";
	ch = 'o';
	// printf("ft_strrchr: %d\n", ft_strrchr(c, ch));
	printf("strrchr: %s\n", strrchr(c, ch));
	printf("ft_strrchr: %s\n", ft_strrchr(c, ch));
	c = "---3\0-2 e";
	ch = '\0';
	printf("lowercase strrchr: %s\n", strrchr(c, ch));
	printf("lowercase ft_strrchr: %s\n", ft_strrchr(c, ch));
	c = "";
	ch = '\0';
	printf("not digit case strrchr: %s\n", strrchr(c, ch));
	printf("not digit case ft_strrchr: %s\n", ft_strrchr(c, ch));
	printf("\n-------------------------------------\n\n");
} */

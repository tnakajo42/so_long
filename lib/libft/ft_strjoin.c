/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:49:42 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 21:32:46 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

/* int main (void)
{
	char			str1[] = "hello ifmmp jgnnq";
	char			str2[] = "xxxxxxxx";
	char			*ptr = ft_strjoin(str1, str2);
	// char			*ptr = ft_substr(str, 400, 20);
	int				i;

	while (ptr[i])
	{
		printf("%c\n", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
} */

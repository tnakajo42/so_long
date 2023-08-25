/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:45:18 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/23 15:56:44 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i++ < len)
		dst[i - 1] = s[start + i - 1];
	dst[i - 1] = '\0';
	return (dst);
}

/* char	*ft_substr_2(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[start + i])
	{
		if (i < len)
		{
			str[i] = s[start + i];
			j++;
		}
		i++;
	}
	if (i == 0 || len + start < i)
		str[j] = '\0';
	return (str);
} */

/* int main (void)
{
    char			str[] = "hello ifmmp jgnnq";
    // char			str[] = "hello ifmmp";
    unsigned int	start =  2222;
    unsigned int	len =  10;
	char			*bullshit;
    char			*ptr = ft_substr(str, start, len);
    // char			*ptr = ft_substr(str, 400, 20);
	int				i;

	// printf("%s\n", ptr);
	// bullshit = (char *)&ptr[30];
	// bullshit = "FULL BULLSHIT";
	// i = 0;
	// if (ptr)
	// {
		while (ptr[i])
		{
			printf("%c\n", ptr[i]);
			i++;
		}	
	// }
	// else
	// 	printf("%s\n", "nothing :P");

    free(ptr);

	(void)bullshit;
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:11:57 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 20:30:50 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* char ft_ft(unsigned int c, char s)
	char	ch;
	ch = ft_toupper(s);
	return (ch);
}

int main(void)
{
	char *str = "hello, world!";
	char *modified_str = ft_strmapi(str, ft_ft);
	printf("Original string: %s\nModified string: %s\n", str, modified_str);
	free(modified_str);
	return 0;
} */

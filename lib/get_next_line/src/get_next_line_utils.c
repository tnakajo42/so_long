/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:58:49 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/16 17:39:14 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_char(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

char	*ft_str_dup_b(char *str, int c)
{
	int		i;
	char	*str_dup;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i])
		i++;
	str_dup = (char *)malloc(sizeof(char) * (i + 1));
	str_dup[i] = '\0';
	while (i)
	{
		i--;
		str_dup[i] = str[i];
	}
	return (str_dup);
}

char	*ft_str_dup_a(char *str, int c)
{
	int		i;
	int		len;
	char	*str_dup;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i])
		i++;
	len = ft_str_len(str);
	str_dup = (char *)malloc(sizeof(char) * (len - i + 1));
	str_dup[len - i] = '\0';
	while (len - i)
	{
		len--;
		str_dup[len - i] = str[len];
	}
	return (str_dup);
}

/* char	*ft_str_dup(char *str)
{
	char	*str_dup;
	size_t	i;

	str_dup = (char *)malloc(sizeof(char) * ft_str_len(str) + 1);
	if (!str_dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_dup[i] = str[i];
		i++;
	}
	str_dup[i] = '\0';
	free (str);
	return (str_dup);
} */

char	*ft_str_cat(char *str1, char *str2)
{
	int		len_str1;
	int		len_str2;
	char	*dest;

	len_str1 = ft_str_len(str1);
	len_str2 = ft_str_len(str2);
	dest = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!dest)
		return (NULL);
	if (str1)
		ft_str_cat_sub(dest, str1, 0);
	if (str2)
		ft_str_cat_sub(dest, str2, len_str1);
	dest[len_str1 + len_str2] = '\0';
	return (dest);
}

void	ft_str_cat_sub(char *dest, char *src, int start)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[start + i] = src[i];
		i++;
	}
}

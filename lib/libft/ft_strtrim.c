/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:37:10 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 21:57:02 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		front;
	size_t		rear;
	size_t		i;
	char		*str;

	front = 0;
	i = 0;
	rear = ft_strlen(s1);
	if (s1 == 0 || set == 0)
		return (NULL);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (rear > front && ft_strchr(set, s1[rear - 1]))
		rear--;
	str = (char *)malloc(sizeof(char) * (rear - front + 1));
	if (!str)
		return (NULL);
	while (front < rear)
	{
		str[i] = s1[front];
		i++;
		front++;
	}
	str[i] = '\0';
	return (str);
}

/* int	main(void)
{
	char	*me = "abcqAAABBBaaAAA bc bc aaAAbbBBBBbc";
	char	*set = "bc";
	char	*str = ft_strtrim(me, set);

	printf("Original string %s\n", me);
	printf("After Trimmed string %s\n", str);
	free(str);
	return (0);
} */

/* size_t	ft_strtrimlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	len;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	len = ft_strlen(set);
	while (s1[i])
	{
		while (set[j] && k == 0)
		{
			if (s1[i] == set[j])
			{
				i++;
				j++;
				if (len == j)
					l--;
			}
			else
			{
				k = 1;
				i = i - j + 1;
			}
		}
		j = 0;
		k = 0;
		l++;
	}
	return (l);
}

size_t	ft_trimstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(set);
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				j++;
				if (len == j)
					return (i);
			}
		}
		i = i - j + 1;
		j = 0;
	}
	return (-1);
}

size_t	ft_trimend(char const *s1, char const *set, size_t trim_start)
{
	size_t	i;
	size_t	len;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	while (len_s1 > trim_start)
	{
		i = 0;
		len = ft_strlen(set);
		while (len + 1 > 0)
		{
			if (s1[len_s1] == set[len])
			{
				len_s1--;
				len--;
				i++;
				if (len == -1)
					return (len_s1);
			}
		}
		len_s1 = len_s1 + i - 1;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	len;
	size_t	len_trim;
	size_t	trim_start;
	size_t	trim_end;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	len = ft_strlen(set);
	len_trim = ft_strtrimlen(s1, set);
	trim_start = ft_trimstart(s1, set);
	if (trim_start != -1)
		trim_end = ft_trimend(s1, set, trim_start);
	printf("ft_strlen(set) -> %ld\n", len);
	printf("ft_strlen(s1) --> %ld\n", ft_strlen(s1));
	printf("ft_strlentrim --> %ld\n", len_trim);
	printf("trim_start    --> %ld\n", trim_start);
	printf("trim_end      --> %ld\n", trim_end);
	return ("test");

	str = (char *)malloc(sizeof(char) * (len_trim + 1));
	if (!str)
		return (NULL);
	printf("%c\n", s1[i]);
	while (i < len_trim)
	{
		printf("%ld\n", i);
		printf("%s\n", str);
		while (set[j])
		{
			printf("in while set[4] > %c\n", set[j]);
			printf("in while s1 ----> %c\n", s1[i]);
			if (s1[i] == set[j])
			{
				// i++;
				// j++;
				printf("%c\n", s1[i]);
				printf("%ld\n", len);
				printf("%ld\n", j);
				if (j = len - 1)
				{
					// k = 1;
					printf("------------------------------\n");
				}
			}
			i++;
			j++;
			// if (len == j)
			// 	k = 1;
		}
		if (k == 0)
		{
			i = i - j;
			str[l] = s1[i];
			printf("%s\n", str);
		}
		else
			printf("****************************\n");
		i++;
		// printf("------------------------------\n", s1[i]);
		l++;
		j = 0;
		k = 0;
	}
	// printf("%d\n", i);
	// printf("%d\n", j);
	// printf("%d\n", k);
	printf("%s\n", str);
	return (str);
}

int main (void)
{
	char			str1[] = "ello hello hello";
	char			str2[] = "ello";
	char			*ptr = ft_strtrim(str1, str2);
	// char			*ptr = ft_substr(str, 400, 20);
	// int				i;

	// i = 0;
	// while (ptr[i])
	// {
	// 	printf("%c\n", ptr[i]);
	// 	i++;
	// }
	// free(ptr);
	return (0);
} */

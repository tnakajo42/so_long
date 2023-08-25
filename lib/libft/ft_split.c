/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:49:45 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/24 13:05:58 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdcount(const char *str, char c)
{
	int	trigger;
	int	count;

	trigger = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

static int	ft_word_size(const char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void	ft_free(char **str, int j)
{
	while (j)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		size;
	char	**str;

	i = 0;
	j = 0;
	word = ft_wdcount(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_word_size(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
			ft_free(str, j);
		i = size + i;
		j++;
	}
	str[j] = NULL;
	return (str);
}

/* size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_delimitercount(const char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && k == 0)
		{
			k = 1;
			j++;
		}
		else if (str[i] == c)
			k = 0;
		i++;
	}
	return (j);
}

static char	*ft_tmpwords(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**split;

	split = (char **)malloc(sizeof(char *) * ft_delimitercount(s, c));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	// while (s[i])
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			split[j++] = ft_tmpwords(s, k, i);	
			k = -1;
		}
		i++;
	}
	split[j] = NULL; // why it is needed?
	// should I use free function?
	return (split);
} */

/* char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	i = 0;
	j = 0;
	k = 0;
	split = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (!split)
		return (NULL);
	printf("hey\n");
	while (s[i])
	{
		if (s[i] == c)
		{
			j++;
			k = 0;
		}
		split[j][k] = s[i];
		i++;
		k++;
	}
	printf("hey almost\n");
	return (split);
} */

/* int	main(void)
{
	char	*s1 = "  hello f abc    def";
	char	c = ' ';
	char	**ptr = ft_split(s1, c);
	int		i;

	i = 0;
	while (ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
} */
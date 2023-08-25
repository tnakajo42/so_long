/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:55:06 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/17 22:10:38 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		nb_read;
	char		*str_buff;
	static char	*str_line;

	if (fd == -1 || BUFFER_SIZE < 1)
	{
		ft_str_free(&str_line);
		return (NULL);
	}
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
		return (NULL);
	nb_read = read(fd, str_buff, BUFFER_SIZE);
	if (nb_read == -1)
	{
		free (str_buff);
		ft_str_free(&str_line);
		return (NULL);
	}
	str_buff[nb_read] = '\0';
	if (nb_read == 0)
		return (get_next_line_sub(&str_line, &str_buff));
	return (get_next_line_with_n(&str_line, &str_buff, fd));
}

char	*get_next_line_sub(char **str_line, char **str_buff)
{
	char	*str_temp;
	char	*str_rtrn;

	free (*str_buff);
	if (ft_str_len(*str_line))
	{
		if (ft_str_char(*str_line, '\n'))
		{
			str_temp = *str_line;
			str_rtrn = ft_str_dup_b(str_temp, '\n');
			*str_line = ft_str_dup_a(str_temp, '\n');
			free (str_temp);
			return (str_rtrn);
		}
		str_rtrn = ft_str_dup_b(*str_line, '\0');
		free (*str_line);
		*str_line = NULL;
		return (str_rtrn);
	}
	free (*str_line);
	*str_line = NULL;
	return (*str_line);
}

char	*get_next_line_with_n(char **str_line, char **str_buff, int fd)
{
	char	*str_temp;
	char	*str_rtrn;

	str_temp = *str_line;
	*str_line = ft_str_cat(str_temp, *str_buff);
	free(str_temp);
	free(*str_buff);
	if (ft_str_char(*str_line, '\n'))
	{
		str_temp = *str_line;
		str_rtrn = ft_str_dup_b(str_temp, '\n');
		*str_line = ft_str_dup_a(str_temp, '\n');
		free (str_temp);
		return (str_rtrn);
	}
	return (get_next_line(fd));
}

void	ft_str_free(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}

int	ft_str_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* char *test(int fd)
{
	ssize_t		n;
	char		*str_rtrn;
	char		*str_buff;
	char		*str_temp;
	static char	*str_line;

	if (fd == -1 || BUFFER_SIZE < 1)
	{
		if (str_line)
			free (str_line);
		return (NULL);
	}
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
		return (NULL);
	n = read(fd, str_buff, BUFFER_SIZE);
	
	str_temp = str_line;
	str_line = ft_str_cat(str_temp, str_buff);
	free(str_temp);
	free(str_buff);
	if (ft_str_char(str_line, '\n'))
	{
		str_temp = str_line;
		str_rtrn = ft_str_dup_b(str_temp, '\n');
		str_line = ft_str_dup_a(str_temp, '\n');
		free (str_temp);
		// free (str_line);
		return (str_rtrn);
	}
	else
		return (test(fd));
} */

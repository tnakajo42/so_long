/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:44:32 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/07 20:03:38 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	sign;

	str = (unsigned char *)s;
	sign = 0;
	while (sign < n)
	{
		if (str[sign] == (unsigned char)c)
			return ((char *)&str[sign]);
		sign++;
	}
	return (0);
}

/*
void	main(void)
{
	char	str[] = "http://www.tutorialspoint.com";
	char	ch = '.';
	char	*ret;

	printf("\n---------------memchr---------------\n\n");
	printf("String after |%c| is - |%s|\n", ch, memchr(str, ch, 9));
	printf("String after |%c| is - |%s|\n", ch, ft_memchr(str, ch, 9));
	printf("String after |%c| is - |%s|\n", ch, memchr(str, ch, 10));
	printf("String after |%c| is - |%s|\n", ch, ft_memchr(str, ch, 10));
	printf("String after |%c| is - |%s|\n", ch, memchr(str, ch, 11));
	printf("String after |%c| is - |%s|\n", ch, ft_memchr(str, ch, 11));
	printf("String after |%c| is - |%s|\n", ch, memchr(str, ch, 14));
	printf("String after |%c| is - |%s|\n", ch, ft_memchr(str, ch, 14));
	printf("\n-------------------------------------\n\n");
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:37:49 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/22 19:25:52 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
void	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[100];

	// ft_memcpy(dest, src, strlen(src) -2);
	ft_memcpy(dest, src, strlen(src) + 1);
	// memcpy(dest, src, strlen(src) + 1);
	printf("%s\n", dest);
}
// The main difference between the two functions is that
// memcpy simply copies a specified number of bytes
// from one location to another,
// without checking for the presence of a null terminator
// or ensuring that the destination buffer is large enough
// to hold the copied data.
// strlcpy, on the other hand, is a safer alternative
// to strcpy that checks for the presence of a null terminator
// and ensures that the destination buffer is not overflowed.
// Because of this, strlcpy is often used as a more secure alternative
// to strcpy or memcpy when copying strings.
*/

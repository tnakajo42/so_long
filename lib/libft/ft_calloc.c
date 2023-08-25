/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:32:19 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/21 21:01:04 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
int	main(void)
{
    // Allocate memory for 10 integers
    int *ptr = (int*) ft_calloc(10, sizeof(int));
    if (ptr == NULL) {
        // Handle error
        printf("Error\n");
    }
    // ptr[0] = 10;
    // ptr[1] = 20;

    // Check that the allocated memory is initialized to zero
    for (int i = 0; i < 10; i++) {
        if (ptr[i] != 0) {
            printf("Error: allocated memory is not initialized to zero\n");
            return 1;
        }
    }
    printf("^^^^finished\n");
    // Free the memory when it is no longer needed
    free(ptr);

    return (0);
}
*/

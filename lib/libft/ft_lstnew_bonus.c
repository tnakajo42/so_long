/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:37:40 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/23 15:53:40 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

/* int	main(void)
{
	// int		*content;
	// char	*content;
	char	*content = "lorem ipsum dolor sit";
	t_list	*new_node;

	// content = (int*)malloc(sizeof(int));
	// *content = 42;
	// content = (char*)malloc(sizeof(char));
	// *content = "a";
	new_node = ft_lstnew(content);
	if (new_node == NULL)
	{
		printf("Error: failed to create new list node\n");
		return (1);
	}
	// printf("Content of new list node: %d\n", *(int*)new_node->content);
	printf("Content of new list node: %s\n", new_node->content);
	// free(content);
	free(new_node);
	return (0);
} */

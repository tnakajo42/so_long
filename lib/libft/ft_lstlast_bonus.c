/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:16 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/24 12:18:45 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (NULL);
	while (last -> next)
		last = last -> next;
	return (last);
}

/* int main(int argc, const char *argv[])
{
	int			i;
	char		*content;
	t_list		*val;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("hello");
	char		*str2 = strdup("world");
	char		*str3 = strdup("and");
	char		*str4 = strdup("42");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		printf("----\n");
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		val = ft_lstlast(elem);
		i = 0;
		content = val->content;
		while (content[i])
			write(1, &(content[i++]), 1);
		write(1, "\n", 1);
		elem->next = NULL;
		val = ft_lstlast(elem);
		content = val->content;
		i = 0;
		while (content[i])
			write(1, &(content[i++]), 1);
		write(1, "\n", 1);
		elem = NULL;
		val = ft_lstlast(elem);
		if (val == NULL)
			write(1, "NULL", 4);
		write(1, "\n", 1);
	}
	return (0);
} */

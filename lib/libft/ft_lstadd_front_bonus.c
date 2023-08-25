/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:00:03 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/23 16:36:51 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

/* void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

int main(int argc, const char *argv[])
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*elemnull;
	char		*str = strdup("hey");
	char		*str2 = strdup("say");
	char		*str3 = strdup("jump");
	char		*str4 = strdup("kick");
	char		*strnull = strdup("");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elemnull = ft_lstnew(strnull);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
    printf("-----\n");
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4 || !elemnull)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		begin = NULL;
		ft_lstadd_front(&begin, elem4);
		ft_lstadd_front(&begin, elem3);
		ft_lstadd_front(&begin, elemnull);
		ft_lstadd_front(&begin, elem2);
		ft_lstadd_front(&begin, elem);
		while (begin)
		{
			ft_print_result(begin);
			begin = begin->next;
		}
	}
    printf("-----\n");
	return (0);
} */

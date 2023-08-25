/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:19:32 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/24 14:49:28 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/* void	ft_modify_list_with_d(void *elem)
{
	int		len;
	char	*content;

	len = 0;
	content = (char *)elem;
	while (content[len])
	{
		content[len++] = 'd';
	}
}

void	ft_print_result(t_list *elem)
{
	int		len;

	while (elem)
	{
		len = 0;
		while (((char *)elem->content)[len])
			len++;
		write(1, elem->content, len);
		write(1, "\n", 1);
		elem = elem->next;
	}
}

int main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("alpha");
	char		*str2 = strdup("beta");
	char		*str3 = strdup("ceta");
	char		*str4 = strdup("data");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (atoi(argv[1]) == 1)
	{
		ft_lstiter(elem, &ft_modify_list_with_d);
		ft_print_result(elem);
	}
	return (0);
} */

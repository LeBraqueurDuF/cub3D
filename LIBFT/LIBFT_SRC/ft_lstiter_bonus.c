/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:29:40 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:20 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
/*
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*n1 = ft_lstnew("Salut");
	t_list	*n2 = ft_lstnew("les");
	t_list	*n3 = ft_lstnew("copains");

	ft_lstadd_back(&n1, n2);
	ft_lstadd_back(&n1, n3);

	ft_lstiter(n1, print_content);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:56:08 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:19 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
	}
}
/*
int	main(void)
{
	t_list	*head = ft_lstnew("First");
	t_list	*node = ft_lstnew("Second");

	ft_lstadd_back(&head, node);

	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}
*/

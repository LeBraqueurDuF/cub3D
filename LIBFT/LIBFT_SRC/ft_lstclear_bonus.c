/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:26:11 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:19 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
		*lst = NULL;
	}
}
/*
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	head = ft_lstnew(strdup("hola"));
	node1 = ft_lstnew(strdup("como"));
	node2 = ft_lstnew(strdup("estas senor?"));

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);

	printf("Avant clear :\n");
	t_list *tmp = head;
	while (tmp)
	{
		printf("- %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&head, del);

	if (head == NULL)
		printf("Liste correctement supprimée.\n");

	return (0);
}
*/

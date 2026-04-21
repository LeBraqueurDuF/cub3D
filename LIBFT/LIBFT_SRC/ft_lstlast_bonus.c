/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:52:26 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:20 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void)
{
	t_list	*head = ft_lstnew("Yo");
	t_list	*first = ft_lstnew("T'es très");
	t_list	*second = ft_lstnew("chaud");
	t_list	*last;

	head->next = first;
	first->next = second;
	second->next = NULL;

	last = ft_lstlast(head);
	if (last)
		printf("%s\n", (char *)last->content);

	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:02:46 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:19 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*head = ft_lstnew("Second");
	t_list	*node = ft_lstnew("First");

	ft_lstadd_front(&head, node);

	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}
*/

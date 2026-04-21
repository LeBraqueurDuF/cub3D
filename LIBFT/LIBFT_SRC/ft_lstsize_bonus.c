/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:06:38 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:21 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
int	main(void)
{
	t_list	*head = ft_lstnew("MGP");
	t_list	*first = ft_lstnew("Razor");
	t_list	*second = ft_lstnew("Blunt");
	int		size;

	head->next = first;
	first->next = second;
	second->next = NULL;

	size = ft_lstsize(head);

	printf("%d\n", size);
	return (0);
}
*/

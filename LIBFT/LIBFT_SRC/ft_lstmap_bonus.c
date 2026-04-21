/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:12:09 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:20 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;
	t_list	*new_node;
	void	*new_content;

	head = NULL;
	temp = lst;
	while (temp)
	{
		new_content = f(temp->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		temp = temp->next;
	}
	return (head);
}
/*
void	del(void *content)
{
	free(content);
}

void	*to_upper_dup(void *content)
{
	char	*str = (char *)content;
	char	*dup = strdup(str);
	int		i = 0;

	while (dup[i])
	{
		if (dup[i] >= 'a' && dup[i] <= 'z')
			dup[i] -= 32;
		i++;
	}
	return (dup);
}

int	main(void)
{
	t_list	*n1 = ft_lstnew(strdup("la claaaasse"));
	t_list	*n2 = ft_lstnew(strdup("42"));
	t_list	*n3 = ft_lstnew(strdup("up"));
	t_list	*mapped;

	ft_lstadd_back(&n1, n2);
	ft_lstadd_back(&n1, n3);

	mapped = ft_lstmap(n1, to_upper_dup, del);

	t_list	*tmp = mapped;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&n1, del);
	ft_lstclear(&mapped, del);
	return (0);
}
*/

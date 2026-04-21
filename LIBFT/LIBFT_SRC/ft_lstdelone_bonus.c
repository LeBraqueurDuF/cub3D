/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:21:46 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:20 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
/*
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node = ft_lstnew(malloc(10));

	if (node)
	{
		ft_lstdelone(node, del_content);
		printf("Maillon supprimé.\n");
	}
	return (0);
}
*/

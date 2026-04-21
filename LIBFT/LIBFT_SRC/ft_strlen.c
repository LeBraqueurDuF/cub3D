/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:17:07 by sesquier          #+#    #+#             */
/*   Updated: 2025/11/14 15:35:33 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	const char	*s = "tema la taille du rat";
	int			la_taille_du_rat = ft_strlen(s);

	printf("%d\n", la_taille_du_rat);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:36:26 by sesquier          #+#    #+#             */
/*   Updated: 2025/11/03 18:14:20 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		dup_len;
	char	*dup;

	if (!s)
		return (NULL);
	i = 0;
	dup_len = ft_strlen(s);
	dup = malloc((dup_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < dup_len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char	*str = ft_strdup("Salut les gars je suis un test");

	if (str)
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
*/

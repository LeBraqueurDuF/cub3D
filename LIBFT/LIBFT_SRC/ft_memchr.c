/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:20:55 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:21 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "Hello42";
	char	*ptr;

	ptr = ft_memchr(str, '4', 7);
	if (ptr)
		printf("Trouvé brother: %c\n", *ptr);
	else
		printf("Pas trouvé brother\n");
	return (0);
}
*/

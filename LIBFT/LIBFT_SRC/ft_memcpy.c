/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:49:54 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:21 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*str_src;
	unsigned char		*str_dest;

	if (!dest && !src)
		return (NULL);
	i = 0;
	str_dest = (unsigned char *)dest;
	str_src = (const unsigned char *)src;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "C'est Marseille bb";
	char	dest[42];

	ft_memcpy(dest, src, 15);
	dest[15] = '\0';
	printf("%s\n", dest);
	return (0);
}
*/

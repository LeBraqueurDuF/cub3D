/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:56:06 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:21 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		while (n)
		{
			--n;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	str[] = "abcdef";

	ft_memmove(str, str + 2, 4);
	str[4] = '\0';
	printf("%s\n", str);
	return (0);
}
*/

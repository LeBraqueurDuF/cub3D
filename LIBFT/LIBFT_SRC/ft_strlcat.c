/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:46:04 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:23 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	i = 0;
	j = dst_len;
	if (siz < dst_len)
		return (src_len + siz);
	while (src[i] && j < siz - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (src_len + dst_len);
}
/*
int	main(void)
{
	char		dest[20] = "Hello ";
	const char	*src = "World!";
	size_t		result;

	result = ft_strlcat(dest, src, 20);
	printf("Resultat : %s\n", dest);
	printf("Taille totale : %zu\n", result);

	return (0);
}
*/

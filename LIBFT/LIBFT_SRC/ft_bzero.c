/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:04:27 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:11 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	buffer1[10] = "abcdefghi";
	char	buffer2[10] = "abcdefghi";
	int		i = 0;

	ft_bzero(buffer1 + 3, 4);
	bzero(buffer2 + 3, 4);

	printf("buffer1 : ");
	i = 0;
	while (i < 9)
	{
		if (buffer1[i] == '\0')
			printf("\\0");
		else
			printf("%c", buffer1[i]);
		i++;
	}
	printf("\n");

	printf("buffer2 : ");
	i = 0;
	while (i < 9)
	{
		if (buffer2[i] == '\0')
			printf("\\0");
		else
			printf("%c", buffer2[i]);
		i++;
	}
	printf("\n");

	return (0);
}
*/

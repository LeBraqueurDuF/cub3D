/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:56:37 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:13 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	cal = malloc(nmemb * size);
	if (!cal)
		return (NULL);
	ft_memset(cal, 0, nmemb * size);
	return (cal);
}
/*
int	main(void)
{
	char	*ptr;
	int		i;

	ptr = ft_calloc(10, sizeof(char));
	if (!ptr)
	{
		printf("Allocation échouée\n");
		return (1);
	}

	printf("Contenu de ptr : ");
	i = 0;
	while (i < 10)
	{
		if (ptr[i] == '\0')
			printf("\\0");
		else
			printf("%c", ptr[i]);
		i++;
	}
	printf("\n");

	free(ptr);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:31:44 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:24 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	size_t			s_len;

	i = 0;
	s_len = ft_strlen(s);
	str = malloc((s_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[s_len] = '\0';
	while (i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/*
char	upupup(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*result = ft_strmapi("bonjour", upupup);

	printf("%s\n", result);
	free(result);
	return (0);
}
*/

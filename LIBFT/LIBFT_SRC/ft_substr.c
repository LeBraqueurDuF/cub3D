/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:17:13 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:25 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;
	size_t	cpy_len;

	i = 0;
	s_len = ft_strlen(s);
	cpy_len = s_len - start;
	if (!s || start >= (unsigned int)(s_len))
		return (ft_strdup(""));
	if (len > cpy_len)
		len = cpy_len;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char const	*s = "au final il restera que ca";
	char		*sub = ft_substr(s, 9, 18);

	printf("%s\n", sub);
	free(sub);
	return (0);
}
*/

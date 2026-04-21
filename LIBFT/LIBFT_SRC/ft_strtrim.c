/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:23:25 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:25 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	trim_len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strrchr(set, s1[end - 1]))
		end--;
	trim_len = end - start;
	trim = ft_substr(s1, start, trim_len);
	return (trim);
}
/*
int	main(void)
{
	char *s = "+++42School+++";
	char *trimmed = ft_strtrim(s, "+");

	printf("%s\n", trimmed);
	free(trimmed);
	return (0);
}
*/

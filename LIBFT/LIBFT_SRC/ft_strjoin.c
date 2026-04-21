/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:21:33 by sesquier          #+#    #+#             */
/*   Updated: 2025/12/09 11:40:04 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		s1_len;
// 	int		s2_len;
// 	int		i;
// 	int		j;
// 	char	*join;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	join = malloc((s1_len + s2_len + 1) * sizeof(char));
// 	if (!join)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		join[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		join[i + j] = s2[j];
// 		j++;
// 	}
// 	join[i + j] = '\0';
// 	return (join);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	return (join[i + j] = '\0', join);
}
/*
int	main(void)
{
	char const	*s1 = "Yess bb, ";
	char const	*s2 = "Alors ca marche";
	char		*join = ft_strjoin(s1, s2);

	printf("%s\n", join);
	free(join);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:23:52 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:23 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**free_split(char **tab, int j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
	return (NULL);
}

static char	*get_word(char const *s, int *i, char c)
{
	int	start;
	int	len;

	while (s[*i] == c && s[*i])
		(*i)++;
	start = *i;
	len = 0;
	while (s[*i] != c && s[*i])
	{
		len++;
		(*i)++;
	}
	return (ft_substr(s, start, len));
}

static char	**malloc_words(char **tab, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = get_word(s, &i, c);
			if (!tab[j])
				return (free_split(tab, j));
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (malloc_words(tab, s, c));
}
/*
int	main(void)
{
	char const	*s = "Okay okay on separe avec des espaces";
	char		c = 32;
	int			i = 0;
	char		**split = ft_split(s, c);

	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
*/

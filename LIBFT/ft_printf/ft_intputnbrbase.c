/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intputnbrbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:20:57 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:28 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	check_error_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (-1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 33 || base[i] > 126)
			return (-1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_intputnbrbase(unsigned long long nbr, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = 0;
	if (check_error_base(base) == -1)
		return (0);
	while (base[base_len])
		base_len++;
	if (nbr == 0)
		return (count += ft_intputchar(base[0]));
	if (nbr >= (unsigned long long)base_len)
		count += ft_intputnbrbase(nbr / base_len, base);
	count += ft_intputchar(base[nbr % base_len]);
	return (count);
}

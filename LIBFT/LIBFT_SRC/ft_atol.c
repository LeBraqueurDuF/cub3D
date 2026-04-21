/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:00:31 by sesquier          #+#    #+#             */
/*   Updated: 2025/07/15 17:06:10 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	will_overflow(long result, int digit, int sign)
{
	if (sign == 1)
	{
		if (result > (LONG_MAX - digit) / 10)
			return (1);
	}
	else
	{
		if (result > (-(LONG_MIN + digit)) / 10)
			return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = get_sign(&str);
	while (ft_isdigit((int)*str))
	{
		digit = *str - '0';
		if (will_overflow(result, digit, sign))
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

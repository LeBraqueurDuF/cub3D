/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:49:35 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:04:09 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include "../libft.h"

int main(void)
{
    printf("Test 1: '42' -> %d\n", ft_atoi("42"));
    printf("Test 2: '   1234' -> %d\n", ft_atoi("   1234"));
    printf("Test 3: '+56' -> %d\n", ft_atoi("+56"));
    printf("Test 4: '-987' -> %d\n", ft_atoi("-987"));
    printf("Test 5: '   -+42' -> %d\n", ft_atoi("   -+42"));
    printf("Test 6: '4193 with words' -> %d\n", ft_atoi("4193 with words"));
    printf("Test 7: 'words then 789' -> %d\n", ft_atoi("words then 789"));
    printf("Test 8: '' -> %d\n", ft_atoi(""));
    printf("Test 9: '   \t\n\v\f\r 42' -> %d\n", ft_atoi("   \t\n\v\f\r 42"));
    printf("Test 10: '2147483647' -> %d\n", ft_atoi("2147483647"));
    printf("Test 11: '-2147483648' -> %d\n", ft_atoi("-2147483648"));

    return (0);
}
*/

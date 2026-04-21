/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intputunsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:24:35 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:28 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intputunsignedint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_intputunsignedint(n / 10);
	count += ft_intputchar((n % 10) + '0');
	return (count);
}
/*
int	main(void)
{
	unsigned int	n = 420;
	int				n1 = -20;
	char			c = 'a';
	int				count = ft_printf("%u", n);
	ft_printf("\n");
	int				count1 = ft_printf("%u", n1);
	ft_printf("\n");
	int				count2 = ft_printf("%u", c);
	ft_printf("\n");

	ft_printf("\n%d", count);
	ft_printf("\n%d", count1);
	ft_printf("\n%d\n", count2);

	return (0);
}
*/

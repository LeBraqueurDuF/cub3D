/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:27:10 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:27 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intputnbr(int n)
{
	int			count;
	long long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_intputchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_intputnbr(nb / 10);
	count += ft_intputchar(nb % 10 + '0');
	return (count);
}

// int main(void)
// {
// 	int	n = 100;
// 	int	count = ft_intputnbr(n);
// 	ft_printf("\n%d\n", count);
// 	return (0);
// }

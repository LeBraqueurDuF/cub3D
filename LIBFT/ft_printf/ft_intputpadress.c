/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intputpadress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:54:53 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:28 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intputpadress(void *p)
{
	int	count;

	count = 0;
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	count += ft_intputnbrbase((unsigned long)p, "0123456789abcdef");
	return (count);
}
// int	main(void)
// {
// 	int	age = 23;

// 	int count = ft_printf("%p\n", &age);
// 	printf("%p\n", &age);
// 	ft_printf("\n%d", count);
// 	return (0);
// }

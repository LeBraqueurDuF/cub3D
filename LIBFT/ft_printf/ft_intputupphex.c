/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intputupphex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:13:38 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:29 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intputupphex(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_intputnbrbase(n, "0123456789ABCDEF");
	return (count);
}
// int main(void)
// {
// 	int n = 42;
// 	ft_printf("On fait coucou les ptits %X\n", n);
// 	printf("On fait coucou les ptits %X\n", n);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intputlowhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:34:53 by sesquier          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:27 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intputlowhex(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_intputnbrbase(n, "0123456789abcdef");
	return (count);
}

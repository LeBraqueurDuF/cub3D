/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesquier <sesquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:03:55 by sesquier          #+#    #+#             */
/*   Updated: 2025/07/15 16:45:40 by sesquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_handle_format(char format, va_list *ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_intputchar(va_arg(*ap, int));
	else if (format == 's')
		count += ft_intputstr(va_arg(*ap, char *));
	else if (format == 'd' || format == 'i')
		count += ft_intputnbr(va_arg(*ap, int));
	else if (format == 'u')
		count += ft_intputunsignedint(va_arg(*ap, unsigned int));
	else if (format == 'p')
		count += ft_intputpadress(va_arg(*ap, void *));
	else if (format == 'x')
		count += ft_intputlowhex(va_arg(*ap, unsigned int));
	else if (format == 'X')
		count += ft_intputupphex(va_arg(*ap, unsigned int));
	else if (format == '%')
		count += ft_intputchar('%');
	else
		count += ft_intputchar('%') + ft_intputchar(format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_handle_format(*format, &ap);
		}
		else
			count += ft_intputchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}

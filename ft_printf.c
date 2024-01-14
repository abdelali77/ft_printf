/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:26:40 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/13 16:54:31 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char s, va_list ap)
{
	int		n;

	n = 0;
	if (s == 'c')
		n += ft_print_char(va_arg(ap, int));
	else if (s == 'd' || s == 'i')
		n += ft_print_dec_hex((long)va_arg(ap, int), 10, s);
	else if (s == 's')
		n += ft_print_str(va_arg(ap, char *));
	else if (s == '%')
		n += ft_print_char('%');
	else if (s == 'p')
		n += ft_print_addr(va_arg(ap, void *));
	else if (s == 'x' || s == 'X')
		n += ft_print_dec_hex((long)(va_arg(ap, unsigned int)), 16, s);
	else if (s == 'u')
		n += ft_print_unsigned(va_arg(ap, unsigned int));
	else
		return (ft_print_char(s));
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		char_printed;

	i = 0;
	char_printed = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			char_printed += print_format(format[++i], args);
		else
			char_printed += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (char_printed);
}

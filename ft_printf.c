/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:26:40 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/11 11:14:52 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char s, va_list ap)
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
	else if (s == 'x')
		n += ft_print_dec_hex((long)(va_arg(ap, unsigned int)), 16, s);
	else if (s == 'X')
		n += ft_print_dec_hex((long)(va_arg(ap, unsigned int)), 16, s);
	else if (s == 'u')
		n += ft_print_unsigned(va_arg(ap, unsigned int));
	else
		return (ft_print_char(s));
	return (n);
	va_end(ap);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += print_format(format[++i], args);
			if (char_printed < 0)
				return (-1);
		}
		else
		{
			char_printed += ft_print_char(format[i]);
			if (char_printed < 0)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (char_printed);
}

#include <stdio.h>
int main()
{
	int arr[] = {10, 15, 17};
	printf("%p\n", arr);
	ft_printf("%p\n", arr);
}
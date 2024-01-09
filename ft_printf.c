/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:26:40 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/09 13:31:00 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

static int	print_format(char s, va_list ap)
{
	int		n;

	n = 0;
	if (s == 'c')
		n += ft_print_char(va_arg(ap, int));
	else if (s == 'd' || s == 'i')
		n += ft_print_digit((long)va_arg(ap, int), 10, s);
	else if (s == 's')
		n += ft_print_str(va_arg(ap, char *));
	else if (s == '%')
		n += write(1, "%", 1);
	// else if (s == 'p')
	// 	n += ft_print_addr(va_arg(ap, char *));
	else if (s == 'x')
		n += ft_print_digit((long)(va_arg(ap, unsigned int)), 16, s);
	else if (s == 'X')
		n += ft_print_digit((long)(va_arg(ap, unsigned int)), 16, s);
	else
		return (write(1, &s, 1));
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
			char_printed += print_format(format[++i], args);
		else
			char_printed += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (char_printed);
}

/* #include <stdio.h>
int main()
{
	//char *str = "hello";
	printf("%X\n", 454646);
	ft_printf("%X\n", 454646);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:26:40 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/08 11:55:53 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.h"
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
		n += ft_print_num(va_arg(ap, int));
	else if (s == 's')
		n += ft_print_str(va_arg(ap, char *));
	else if (s == '%')
		n += write(1, "%", 1);
	return (n);
	va_end(ap);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count_printed;

	i = 0;
	count_printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			print_format(format[++i], args);
		else
			ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count_printed);
}

#include <stdio.h>
int main()
{
	//printf("%%%\n");
	ft_printf("%%c");
}
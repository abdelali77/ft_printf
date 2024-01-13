/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:53:02 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/13 13:34:35 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_digit(long num, int base, char s)
{
	int		n;
	char	*symbols;

	n = 0;
	if (s == 'x')
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (num < 0)
	{
		write(1, "-", 1);
		return (n += ft_print_digit(-num, base, s) + 1);
	}
	else if (num < base)
		n += ft_print_char(symbols[num]);
	else
	{
		n += ft_print_digit(num / base, base, s);
		n += ft_print_digit(num % base, base, s);
	}
	return (n);
}

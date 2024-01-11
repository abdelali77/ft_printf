/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:53:02 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/11 11:12:00 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec_hex(long num, int base, char s)
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
		n += ft_print_char('-');
		if (n < 0)
			return (-1);
		n += ft_print_dec_hex(-num, base, s);
	}
	else if (num < base)
		n += ft_print_char(symbols[num]);
	else
	{
		n += ft_print_dec_hex(num / base, base, s);
		if (n < 0)
			return (-1);
		n += ft_print_dec_hex(num % base, base, s);
	}
	return (n);
}

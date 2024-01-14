/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:53:02 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/13 16:51:58 by abmahfou         ###   ########.fr       */
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
		n += ft_print_dec_hex(-num, base, s);
	}
	else if (num < base)
		n += ft_print_char(symbols[num]);
	else
	{
		n += ft_print_dec_hex(num / base, base, s);
		n += ft_print_dec_hex(num % base, base, s);
	}
	return (n);
}

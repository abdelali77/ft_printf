/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:55:27 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/13 16:51:43 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long addr, char *symbols)
{
	int	n;

	n = 0;
	if (addr < 16)
		n += ft_print_char(symbols[addr]);
	else
	{
		n += print_hex(addr / 16, symbols);
		n += print_hex(addr % 16, symbols);
	}
	return (n);
}

int	ft_print_addr(void	*p)
{
	int				count;
	char			*symbols;
	unsigned long	addr;

	count = 0;
	symbols = "0123456789abcdef";
	addr = (unsigned long)p;
	count += ft_print_str("0x");
	count += print_hex(addr, symbols);
	return (count);
}

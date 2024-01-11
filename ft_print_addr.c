/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:55:27 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/11 10:59:19 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned long addr, char *symbols, int *count)
{
	if (addr == 0)
		return ;
	print_hex(addr / 16, symbols, count);
	*count += ft_print_char(symbols[addr % 16]);
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
	if (count < 0)
		return (-1);
	if (addr == 0)
		count += ft_print_char('0');
	else
		print_hex(addr, symbols, &count);
	return (count);
}

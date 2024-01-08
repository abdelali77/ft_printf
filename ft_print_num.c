/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:53:02 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/08 11:56:19 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c)
{
	return(write(1, &c, 1));
}

int	ft_print_num(int num)
{
	int	n;

	n = 0;
	if (num >= 0 && num <= 9)
		n += ft_print_char(num + '0');
	else if (num == -2147483648)
		write(1, "-2147483648", 11);
	else if (num > 9)
	{
		ft_print_num(num / 10);
		ft_print_num(num % 10);
	}
	else
	{
		n += ft_print_char('-');
		ft_print_num(num * -1);
	}
	return (n);
}

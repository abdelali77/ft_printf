/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:09:46 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/11 11:12:14 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_print_dec_hex(long num, int base, char s);
int	ft_print_str(const char *str);
int	ft_print_addr(void	*p);
int	ft_print_unsigned(unsigned int n);
int	ft_print_char(int c);

#endif
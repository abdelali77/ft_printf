/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:09:46 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/12 18:16:48 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_dec_hex(long num, int base, char s);
int	ft_print_str(const char *str);
int	ft_print_addr(void	*p);
int	ft_print_unsigned(unsigned int n);
int	ft_print_char(int c);

#endif
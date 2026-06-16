/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:58:11 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/22 17:58:15 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base_unsigned(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base_unsigned(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'u')
		return (ft_putnbr_base_unsigned(va_arg(args, unsigned int),
				"0123456789"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_print_ptr(void *ptr)
{
	int	count;
	int	res;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	res = ft_putnbr_base_unsigned((unsigned long)ptr, "0123456789abcdef");
	if (res == -1)
		return (-1);
	return (count + res);
}

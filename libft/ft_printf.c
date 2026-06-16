/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:13:50 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 17:03:29 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	print_pointer(va_list *args, int *count)
{
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
		print_s("(nil)", count);
	else
	{
		(*count) += write(1, "0x", 2);
		print_p((size_t)ptr, 16, count);
	}
}

static void	check_next(char c, va_list *args, int *count)
{
	if (c == 'c')
		print_c(va_arg(*args, int), count);
	else if (c == 's')
		print_s(va_arg(*args, char *), count);
	else if (c == 'p')
		print_pointer(args, count);
	else if (c == 'd' || c == 'i')
		print_n((long long int)va_arg(*args, int), 10, count, 0);
	else if (c == 'u')
		print_n((long long int)va_arg(*args, unsigned int), 10, count, 0);
	else if (c == 'x')
		print_n((long long int)va_arg(*args, unsigned int), 16, count, 0);
	else if (c == 'X')
		print_n((long long int)va_arg(*args, unsigned int), 16, count, 1);
	else if (c == '%')
		print_s("%", count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			check_next(format[++i], &args, &count);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

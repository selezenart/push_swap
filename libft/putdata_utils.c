/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdata_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:52:55 by aselezen          #+#    #+#             */
/*   Updated: 2026/05/22 17:58:15 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_sign_and_abs(long nbr, long *num)
{
	*num = nbr;
	if (nbr >= 0)
		return (0);
	*num = -nbr;
	if (ft_putchar('-') == -1)
		return (-1);
	return (1);
}

int	ft_putchar(const char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	counter;
	int	res;

	if (!str)
		return (ft_putstr("(null)"));
	counter = 0;
	while (*str)
	{
		res = ft_putchar(*str);
		if (res == -1)
			return (-1);
		str++;
		counter += res;
	}
	return (counter);
}

int	ft_putnbr_base(long nbr, char *base)
{
	unsigned int	base_len;
	long			num;
	int				count;
	int				res;

	base_len = 0;
	count = put_sign_and_abs(nbr, &num);
	if (count == -1)
		return (-1);
	while (base[base_len])
		base_len++;
	if (num >= (long)base_len)
	{
		res = ft_putnbr_base(num / base_len, base);
		if (res == -1)
			return (-1);
		count += res;
	}
	if (ft_putchar(base[num % base_len]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	unsigned int	base_len;
	int				count;
	int				res;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
	{
		res = ft_putnbr_base_unsigned(nbr / base_len, base);
		if (res == -1)
			return (-1);
		count += res;
	}
	if (ft_putchar(base[nbr % base_len]) == -1)
		return (-1);
	return (count + 1);
}

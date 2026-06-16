/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:47:56 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/24 18:43:13 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_them_sizes(int nb)
{
	int				i;
	unsigned int	n;

	if (nb == 0)
		return (1);
	i = 0;
	if (nb < 0)
	{
		i++;
		n = (unsigned int)-nb;
	}
	else
		n = (unsigned int)nb;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*r;
	unsigned int	nbr;
	unsigned int	size;

	size = count_them_sizes(n);
	r = (char *)malloc(sizeof(char) * (size + 1));
	if (!r)
		return (NULL);
	if (n < 0)
	{
		r[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		r[0] = '0';
	r[size] = '\0';
	while (nbr != 0)
	{
		r[size - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	return (r);
}

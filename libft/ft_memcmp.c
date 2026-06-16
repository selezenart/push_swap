/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:08:54 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/23 14:25:44 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(char *)(s1 + i) == *(char *)(s2 + i))
		i++;
	if (i == n)
		return (0);
	else
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}

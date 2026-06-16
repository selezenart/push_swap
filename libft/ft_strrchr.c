/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:53:48 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/23 16:11:34 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char				*copy_s;
	unsigned char		ch;
	size_t				size;

	ch = c;
	size = ft_strlen(s);
	copy_s = (char *)s + size;
	if (ch == '\0')
		return (copy_s++);
	while (copy_s >= s)
	{
		if (*copy_s == ch)
			return (copy_s);
		copy_s--;
	}
	copy_s = NULL;
	return (copy_s);
}

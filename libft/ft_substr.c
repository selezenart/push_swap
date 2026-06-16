/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:16:16 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/24 14:54:01 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	char	*src;
	size_t	rlen;

	if (!s)
		return (0);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		rlen = ft_strlen(src) + 1;
	else
		rlen = len + 1;
	r = malloc(rlen * sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, src, rlen);
	return (r);
}

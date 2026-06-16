/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:13:27 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/24 18:33:33 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	int		i;
	int		j;
	char	*dest;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *)malloc(sizeof(char) * size);
	if (!dest)
		return (0);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char *strs[] = {"one", "two", "three"};
// 	char *res = ft_strjoin(3, strs, ", ");
// 	printf("%s", res);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:18:04 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/24 18:40:16 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_sep(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static int	count_them_words(const char *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
		{
			count++;
			i += ft_strlen_sep(str + i, sep);
		}
	}
	return (count);
}

static void	free_dest(char **dest, int size)
{
	while (size--)
		free(dest[size]);
	free(dest);
}

static int	fill_dest(char **dest, const char *s, char c, int size)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	while (i < (size_t)size)
	{
		while (s[k] && s[k] == c)
			k++;
		j = ft_strlen_sep(s + k, c);
		dest[i] = ft_substr(s, k, j);
		if (!dest[i])
			return (free_dest(dest, i), 0);
		k += j;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**dest;

	if (!s)
		return (NULL);
	size = count_them_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dest)
		return (NULL);
	if (!fill_dest(dest, s, c, size))
		return (NULL);
	dest[size] = NULL;
	return (dest);
}

// int main(void)
// {
// 	char **split_string;
// 	split_string = ft_split("test,1.2", "3.");
// 	printf("%s %s %s", split_string[0], split_string[1], split_string[2]);
// 	return 0;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 02:10:08 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*grow(char *buf, int len, int *cap)
{
	char	*new;

	new = malloc(*cap * 2);
	if (!new)
		return (free(buf), NULL);
	ft_memcpy(new, buf, len);
	free(buf);
	*cap *= 2;
	return (new);
}

char	*read_line(void)
{
	char	buf[1];
	char	*line;
	int		len;
	int		cap;

	cap = 8;
	len = 0;
	line = malloc(cap);
	if (!line)
		return (NULL);
	while (read(0, buf, 1) > 0)
	{
		if (buf[0] == '\n')
			return (line[len] = '\0', line);
		if (len + 1 >= cap)
		{
			line = grow(line, len, &cap);
			if (!line)
				return (NULL);
		}
		line[len++] = buf[0];
	}
	if (len == 0)
		return (free(line), NULL);
	return (line[len] = '\0', line);
}

static int	streq(char *a, char *b)
{
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	return (ft_strncmp(a, b, ft_strlen(a) + 1) == 0);
}

int	apply_op(char *op, t_stack **a, t_stack **b)
{
	if (streq(op, "sa"))
		swap(a);
	else if (streq(op, "sb"))
		swap(b);
	else if (streq(op, "ss"))
		(swap(a), swap(b));
	else if (streq(op, "pa"))
		push(a, b);
	else if (streq(op, "pb"))
		push(b, a);
	else if (streq(op, "ra"))
		rotate(a);
	else if (streq(op, "rb"))
		rotate(b);
	else if (streq(op, "rr"))
		(rotate(a), rotate(b));
	else if (streq(op, "rra"))
		reverse_rotate(a);
	else if (streq(op, "rrb"))
		reverse_rotate(b);
	else if (streq(op, "rrr"))
		(reverse_rotate(a), reverse_rotate(b));
	else
		return (0);
	return (1);
}

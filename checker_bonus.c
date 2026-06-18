/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 02:10:16 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	fail(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return (1);
}

static int	run_ops(t_stack **a, t_stack **b)
{
	char	*line;

	line = read_line();
	while (line)
	{
		if (*line != '\0' && !apply_op(line, a, b))
			return (free(line), 1);
		free(line);
		line = read_line();
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*values;
	int		size;

	if (ac < 2)
		return (0);
	values = NULL;
	size = parse(ac, av, &values);
	if (size < 0)
		return (write(2, "Error\n", 6), 1);
	a = create_stack(values, size);
	b = create_empty_stack();
	free(values);
	if (!a || !b)
		return (fail(a, b));
	if (run_ops(&a, &b))
		return (fail(a, b));
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:35:17 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:35:55 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_and_exit(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(*a);
	if (b)
		free_stack(*b);
	error_exit();
}

static int	init_stacks(int ac, char **av, t_stack **a, t_stack **b)
{
	int		*values;
	int		size;

	values = NULL;
	size = parse(ac, av, &values);
	if (size < 0)
		return (error_exit(), -1);
	*a = create_stack(values, size);
	*b = create_empty_stack();
	free(values);
	if (!*a || !*b)
		return (free_and_exit(a, b), -1);
	return (size);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_counts	c;
	t_run		r;

	if (ac < 2)
		return (0);
	if (parse_flags(&ac, &av, &r) < 0)
		return (error_exit(), 1);
	if (ac < 2)
		return (0);
	if (init_stacks(ac, av, &stack_a, &stack_b) < 0)
		return (1);
	ft_memset(&c, 0, sizeof(t_counts));
	r.disorder = compute_disorder(stack_a);
	r.counts = &c;
	run_and_bench(&stack_a, &stack_b, &r);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
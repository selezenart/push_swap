/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:37:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 00:52:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*outer;
	t_node	*inner;
	long	mistakes;
	long	total_pairs;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	outer = a->head;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			total_pairs++;
			if (outer->value > inner->value)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

static void	adaptive_sort(t_run *run)
{
	double	d;

	d = run->disorder;
	if (d < 0.05)
	{
		run->chosen = SIMPLE;
		selection_sort_stacks(run);
	}
	else if (d < 0.5)
	{
		run->chosen = MEDIUM;
		medium_sort_stacks(run);
	}
	else
	{
		run->chosen = COMPLEX;
		radix_sort_stacks(run);
	}
}

void	run_and_bench(t_stack **a, t_stack **b, t_run *run)
{
	run->stack_a = *a;
	run->stack_b = *b;
	run->chosen = run->strategy;
	if (run->strategy == SIMPLE)
		selection_sort_stacks(run);
	else if (run->strategy == MEDIUM)
		medium_sort_stacks(run);
	else if (run->strategy == COMPLEX)
		radix_sort_stacks(run);
	else
		adaptive_sort(run);
	if (run->bench)
		print_bench(run);
}

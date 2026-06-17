/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:37:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:58:15 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Disorder in [0, 1]: count every pair (i < j) where a top element is bigger
// than one below it (a "mistake"), divided by the total number of pairs.
// 0.0 = already sorted, 1.0 = worst possible order. Measure before any moves.
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

// ADAPTIVE: choose the algorithm from the measured disorder. Thresholds are
// placeholders to calibrate once the benchmark exists; lower disorder favours
// the cheaper O(n^2) pass, higher disorder favours O(n log n).
static void	adaptive_sort(t_run *run)
{
	double	d;

	d = run->disorder;
	if (d < 0.05)
		selection_sort_stacks(run);
	else if (d < 0.5)
		medium_sort_stacks(run);
	else
		radix_sort_stacks(run);
}

// Entry point: wire the stacks into run, then dispatch on strategy.
// --simple/--medium/--complex force an algorithm; --adaptive (default) picks.
void	run_and_bench(t_stack **a, t_stack **b, t_run *run)
{
	run->stack_a = *a;
	run->stack_b = *b;
	if (run->strategy == SIMPLE)
		selection_sort_stacks(run);
	else if (run->strategy == MEDIUM)
		medium_sort_stacks(run);
	else if (run->strategy == COMPLEX)
		radix_sort_stacks(run);
	else
		adaptive_sort(run);
}

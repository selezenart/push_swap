/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:37:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/23 13:23:56 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_optimal(t_run *run)
{
	t_stack	*a;

	a = run->stack_a;
	if (a->size == 3)
		return (sort_three(run), 1);
	if (a->size == 5)
		return (sort_five(run), 1);
	return (0);
}

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

	if (do_optimal(run))
		return ;
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

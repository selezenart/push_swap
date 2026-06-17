/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:52:58 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/16 14:32:55 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_stack *a, t_stack *b, int val)
{
	t_node	*cur;
	int		rank;

	rank = 0;
	cur = a->head;
	while (cur)
	{
		if (cur->value < val)
			rank++;
		cur = cur->next;
	}
	cur = b->head;
	while (cur)
	{
		if (cur->value < val)
			rank++;
		cur = cur->next;
	}
	return (rank);
}

static int	find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		max_pos;
	int		i;

	cur = b->head;
	max = cur->value;
	max_pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->value > max)
		{
			max = cur->value;
			max_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (max_pos);
}

static void	max_to_top(t_run *run)
{
	int		pos;
	int		size;
	t_stack	*b;

	b = run->stack_b;
	pos = find_max_pos(b);
	size = (b)->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(run);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(run);
	}
}

static void	push_to_b(t_run *run, int sz)
{
	int	ceiling;
	int	pushed;
	int	r;

	ceiling = sz;
	pushed = 0;
	while (run->stack_a->size > 0)
	{
		r = get_rank(run->stack_a, run->stack_b, run->stack_a->head->value);
		if (r < ceiling)
		{
			pb(run);
			pushed++;
			if (r < ceiling - sz / 2)
				rb(run);
			if (pushed % sz == 0)
				ceiling += sz;
		}
		else
			ra(run);
	}
}

void	medium_sort_stacks(t_run *run)
{
	int		sz;
	int		n;
	t_stack	*a;
	t_stack	*b;

	a = run->stack_a;
	b = run->stack_b;
	n = a->size;
	if (n < 2 || is_sorted(a))
		return ;
	sz = isqrt(n);
	if (sz < 1)
		sz = 1;
	push_to_b(run, sz);
	while (b->size > 0)
	{
		max_to_top(run);
		pa(run);
	}
}

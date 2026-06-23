/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:52:29 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/23 13:14:15 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_stack *stack)
{
	t_node	*curr;
	int		max;
	int		max_pos;
	int		i;

	curr = stack->head;
	max = curr->value;
	max_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value > max)
		{
			max = curr->value;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

static void	move_max_to_top_b(t_run *run)
{
	int		pos;
	int		size;
	t_stack	*b;

	b = run->stack_b;
	pos = find_max_pos(b);
	size = b->size;
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

void	selection_sort_stacks(t_run *run)
{
	t_stack	*a;
	t_stack	*b;

	a = run->stack_a;
	b = run->stack_b;
	if (a->size < 2 || is_sorted(a))
		return ;
	while (a->size > 0)
		pb(run);
	while (b->size > 0)
	{
		move_max_to_top_b(run);
		pa(run);
	}
}

void	sort_three(t_run *run)
{
	int	x;
	int	y;
	int	z;

	x = run->stack_a->head->value;
	y = run->stack_a->head->next->value;
	z = run->stack_a->head->next->next->value;
	if (x > y && y < z && x < z)
		sa(run);
	else if (x > y && y > z)
	{
		sa(run);
		rra(run);
	}
	else if (x > y && y < z && x > z)
		ra(run);
	else if (x < y && y > z && x < z)
	{
		sa(run);
		ra(run);
	}
	else if (x < y && y > z && x > z)
		rra(run);
}

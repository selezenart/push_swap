/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 01:03:41 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 02:09:22 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *stack)
{
	t_node	*curr;
	int		min;
	int		min_pos;
	int		i;

	curr = stack->head;
	min = curr->value;
	min_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value < min)
		{
			min = curr->value;
			min_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_pos);
}

static void	move_min_to_top_a(t_run *run)
{
	int	pos;
	int	size;

	pos = find_min_pos(run->stack_a);
	size = run->stack_a->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(run);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(run);
	}
}

void	sort_five(t_run *run)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		move_min_to_top_a(run);
		pb(run);
		i++;
	}
	sort_three(run);
	while (run->stack_b->size > 0)
		pa(run);
}

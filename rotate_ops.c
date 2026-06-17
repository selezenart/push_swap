/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:40 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:36:40 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Silent primitive (shared with the checker): top element goes to the bottom.
void	rotate(t_stack **s)
{
	t_node	*first;
	t_node	*last;

	if (!s || !(*s)->head || !(*s)->head->next)
		return ;
	first = (*s)->head;
	(*s)->head = first->next;
	last = (*s)->head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_run *run)
{
	rotate(&run->stack_a);
	run->counts->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_run *run)
{
	rotate(&run->stack_b);
	run->counts->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_run *run)
{
	rotate(&run->stack_a);
	rotate(&run->stack_b);
	run->counts->rr++;
	write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:50 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:36:50 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Silent primitive (shared with the checker): bottom element goes to the top.
void	reverse_rotate(t_stack **s)
{
	t_node	*prev;
	t_node	*last;

	if (!s || !(*s)->head || !(*s)->head->next)
		return ;
	prev = (*s)->head;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = (*s)->head;
	(*s)->head = last;
}

void	rra(t_run *run)
{
	reverse_rotate(&run->stack_a);
	run->counts->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_run *run)
{
	reverse_rotate(&run->stack_b);
	run->counts->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_run *run)
{
	reverse_rotate(&run->stack_a);
	reverse_rotate(&run->stack_b);
	run->counts->rrr++;
	write(1, "rrr\n", 4);
}

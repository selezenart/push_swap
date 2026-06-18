/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:27:50 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 02:09:35 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	put_op(run, "rra\n");
}

void	rrb(t_run *run)
{
	reverse_rotate(&run->stack_b);
	run->counts->rrb++;
	put_op(run, "rrb\n");
}

void	rrr(t_run *run)
{
	reverse_rotate(&run->stack_a);
	reverse_rotate(&run->stack_b);
	run->counts->rrr++;
	put_op(run, "rrr\n");
}

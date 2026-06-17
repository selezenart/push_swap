/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:30 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/17 12:36:30 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Silent primitive (shared with the checker): move src's top onto dst.
void	push(t_stack **dst, t_stack **src)
{
	t_node	*node;

	if (!src || !(*src)->head)
		return ;
	node = (*src)->head;
	(*src)->head = node->next;
	(*src)->size--;
	node->next = (*dst)->head;
	(*dst)->head = node;
	(*dst)->size++;
}

void	pa(t_run *run)
{
	push(&run->stack_a, &run->stack_b);
	run->counts->pa++;
	write(1, "pa\n", 3);
}

void	pb(t_run *run)
{
	push(&run->stack_b, &run->stack_a);
	run->counts->pb++;
	write(1, "pb\n", 3);
}

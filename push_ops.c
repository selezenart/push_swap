/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:36:30 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 00:51:36 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	put_op(run, "pa\n");
}

void	pb(t_run *run)
{
	push(&run->stack_b, &run->stack_a);
	run->counts->pb++;
	put_op(run, "pb\n");
}

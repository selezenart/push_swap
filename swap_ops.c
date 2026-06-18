/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:13 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 02:09:17 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack)
		return ;
	first = (*stack)->head;
	if (!first)
		return ;
	second = first->next;
	if (!second)
		return ;
	first->next = second->next;
	second->next = first;
	(*stack)->head = second;
}

void	sa(t_run *run)
{
	swap(&run->stack_a);
	run->counts->sa++;
	put_op(run, "sa\n");
}

void	sb(t_run *run)
{
	swap(&run->stack_b);
	run->counts->sb++;
	put_op(run, "sb\n");
}

void	ss(t_run *run)
{
	swap(&run->stack_a);
	swap(&run->stack_b);
	run->counts->ss++;
	put_op(run, "ss\n");
}

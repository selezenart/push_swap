/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:13 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/18 00:52:13 by aselezen         ###   ########.fr       */
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
	write(1, "sa\n", 3);
}

void	sb(t_run *run)
{
	swap(&run->stack_b);
	run->counts->sb++;
	write(1, "sb\n", 3);
}

void	ss(t_run *run)
{
	swap(&run->stack_a);
	swap(&run->stack_b);
	run->counts->ss++;
	write(1, "ss\n", 3);
}
